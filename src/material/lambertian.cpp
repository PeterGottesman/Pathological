#include <cmath>

#include "ray.h"
#include "vec3.h"
#include "material.h"
#include "scene.h"
#include "randgen.h"
#include "renderable/renderable.h"

Color Lambertian::sample_light(const Scene &sc,
                               const Hit& h,
                               const Ray &r,
                               const Vec3& orig,
                               RandGen &rng) const
{
    const std::vector<Renderable*>& emissives = sc.get_emissives();
    size_t idx = rng.uniform_range_int(0, emissives.size()-1);
    float weight = 1.f/emissives.size();

    Vec3 light_pt = emissives[idx]->uniform_random_point(rng);
    Color emission = {-1.f};

    // Check for occlusion
    Vec3 diff = light_pt - orig;
    float mag = Vec3::magnitude(diff);

    Hit light_hit;
    Ray light_ray(orig, diff/mag);
    light_ray.max_depth = 0;

    if (sc.nearest_hit(light_ray, light_hit) && light_hit.mat->is_emissive()) {
      // This is probably all wrong
      Color light_in = light_hit.mat->sample(sc, light_hit, light_ray, rng);
      float cos_theta_receiver = Vec3::dot(h.norm, light_ray.direction);
      float cos_theta_light = Vec3::dot(light_hit.norm, Vec3{0}-light_ray.direction);
      float pdf =  (mag * mag) / (light_hit.obj->get_area() * cos_theta_light);
      // Color atten = kd * cos_theta_receiver / pdf;
      // emission = light_in * atten;
      emission = kd * M_1_PI * light_in * cos_theta_receiver / pdf;
    }

    return emission / weight;
}

Color Lambertian::sample_brdf(const Scene &sc,
                         Hit &hit,
                         const Ray &r,
                         RandGen &rng) const
{
    Vec3 wo = RandGen::sample_hemisphere_cosine(hit.norm, rng);
    Ray ro(hit.hit_pos, wo, r.depth+1);

    Color diffuse(0.0);

    float cos_theta = Vec3::dot(hit.norm, ro.direction);
    if (sc.nearest_hit(ro, hit))
    {
        Color light_in = hit.mat->sample(sc, hit, ro, rng);
        diffuse = light_in * kd;
    }

    return diffuse;
}

Color Lambertian::sample(const Scene &sc,
                         Hit &hit,
                         const Ray &r,
                         RandGen &rng) const
{
    if (r.depth == r.max_depth) return ke;

    // TODO: The way this hit object is used and passed around is hideous. Rewrite this entire program.
    Vec3 hit_pos = hit.hit_pos;

    Color brdf_sample = sample_brdf(sc, hit, r, rng);

    Color light_sample = {};
    float weight;
    if (sc.get_emissives().empty()) {
      weight = 1;
    } else {
      light_sample = sample_light(sc, hit, r, hit_pos, rng);
      weight = 0.5;
      if (light_sample.x < 0.f) {
        weight = 1;
        light_sample = {0.f};
      }
    }

    return ke + weight * (brdf_sample + light_sample);
    // return ke + brdf_sample;
}
