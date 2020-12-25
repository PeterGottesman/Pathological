#include "material.h"
#include "scene.h"

// Refraction, derivation shown in
// https://graphics.stanford.edu/courses/cs148-10-summer/docs/2006--degreve--reflection_refraction.pdf
Vec3 refract(Vec3 norm, Vec3 dir, float ior1, float ior2)
{
	// Hitting back of object, this is a hack until the ray ior is
	// properly implemented
	if (Vec3::dot(norm, dir) > 0.0f)
	{
		norm *= -1;
		float tmp = ior1;
		ior1 = ior2;
		ior2 = tmp;
	}
	
	float ror = ior1/ior2;

	// Incident cos theta
	float cos_itheta = Vec3::dot(norm , dir);

	// Refracted sin theta squared
	float sin2_rtheta = ror * ror * (1 - cos_itheta * cos_itheta);

	// Total internal reflection
	if (sin2_rtheta > 1.0f)
		return Vec3::reflect(norm, dir);

	return ror * dir + norm * (ror * cos_itheta - sqrt(1-sin2_rtheta));
}

Color Dielectric::sample(const Scene &sc, Hit &hit,
						 const Ray &r, RandGen &rng) const
{
	if (r.depth == r.max_depth)
		return sc.get_background({0.0});

	Vec3 wo = rng.uniform() < 0.9 ? refract(hit.norm, r.direction, 1, ior)
		: Vec3::reflect(hit.norm, r.direction);

	Ray ro(hit.hit_pos, wo, r.depth+1);
	if(sc.nearest_hit(ro, hit))
		return hit.mat->sample(sc, hit, ro, rng);

	return sc.get_background(wo);
}
