#include <cmath>

#include "material.h"
#include "randgen.h"
#include "ray.h"
#include "scene.h"
#include "vec3.h"

Color Lambertian::sample_light(const Scene& sc, const Ray& r, const Vec3& orig, RandGen& rng) const
{
	const std::vector<Renderable*>& emissives = sc.get_emissives();
	size_t idx = rng.uniform_range_int(0, emissives.size() - 1);
	float weight = 1.f / emissives.size();

	Vec3 light_pt = emissives[idx]->uniform_random_point(rng);
	Color emission = {-1.f};

	// Check for occlusion
	Vec3 diff = light_pt - orig;
	float mag = Vec3::magnitude(diff);

	Hit light_hit;
	Ray light_ray(orig, diff / mag);
	light_ray.max_depth = 0;

	if (sc.nearest_hit(light_ray, light_hit) && light_hit.mat->is_emissive())
	{
		// This is probably all wrong
		Color light_in = light_hit.mat->sample(sc, light_hit, light_ray, rng);
		float cos_theta = Vec3::dot(light_hit.norm, Vec3{0} - light_ray.direction);
		Color atten = kd * cos_theta;
		emission = light_in * atten / (mag * mag);
	}

	return emission * weight;
}

Color Lambertian::sample_brdf(const Scene& sc, Hit& hit, const Ray& r, RandGen& rng) const
{
	// Sampling the entire hemisphere would be a double integral
	// over theta (polar) [0, pi/2] and phi (azimuth) [0, 2pi]. This integration is
	// of the form:

	// Int_phi[Int_theta[f(theta,phi) rho^2 sin(theta) d_theta]d_phi]
	// 0 <= phi <= 2pi, 0 <= theta <= pi/2, rho = radius

	// For a this model, the integrand function f does not vary
	// with phi and the radius is always 1, so this simplifies to:

	// 2pi * Int_theta[ f(...,theta) sin(theta) d_theta]
	// 0 <= theta <= pi/2

	// Probability of choosing any specific point on a unit
	// hemisphere is sin(theta)/2pi. The sin(theta) in the
	// numerator cancels with the sin(theta) in the integral
	// above.
	float prob = M_1_PI / 2;

	// This comes from integrating (brdf*kd*cos_theta*light_in) over
	// the unit hemisphere. To properly conserve energy, this integral
	// should evaluate to at most the incoming light - a surface can
	// only scatter as much light as it receives. This will evaluate
	// to (pi*brdf*kd*li) <= li, as the brdf is a constant. Given kd
	// has no element greater than 1, this results in brdf=1/PI. Great
	// explanation here:
	// http://www.rorydriscoll.com/2009/01/25/energy-conservation-in-games/
	Color brdf = M_1_PI;

	Vec3 wo = RandGen::sample_hemisphere_uniform(hit.norm, rng);
	Ray ro(hit.hit_pos, wo, r.depth + 1);

	// Reflected light is proportional to cos(theta)
	float cos_theta = Vec3::dot(hit.norm, ro.direction);

	Color diffuse(0.0);

	if (cos_theta > 1e-3 && sc.nearest_hit(ro, hit))
	{
		Color light_in = hit.mat->sample(sc, hit, ro, rng);
		Color atten = kd * cos_theta * brdf / prob;
		diffuse = light_in * atten;
	}

	return diffuse;
}

Color Lambertian::sample(const Scene& sc, Hit& hit, const Ray& r, RandGen& rng) const
{
	if (r.depth == r.max_depth)
		return ke;

	// TODO: The way this hit object is used and passed around is hideous. Rewrite this entire program.
	Vec3 hit_pos = hit.hit_pos;

	Color brdf_sample = sample_brdf(sc, hit, r, rng);

	Color light_sample = {};
	float weight;
	if (sc.get_emissives().empty())
	{
		weight = 1;
	}
	else
	{
		light_sample = sample_light(sc, r, hit_pos, rng);
		weight = 0.5;
		if (light_sample.x < 0.f)
		{
			weight = 1;
			light_sample = {0.f};
		}
	}

	return ke + weight * (brdf_sample + light_sample);
}