#include "material.h"
#include "scene.h"

float schlick(float cos_itheta, float ior1, float ior2)
{
	float r0 = (ior1-ior2)/(ior1+ior2);
	r0 *= r0;

	float ci = 1 - cos_itheta;
	float sch = r0 + (1 - r0) * ci * ci * ci * ci * ci;

	// Clamp to [0, 1]. Round values which will result in an
	// infinitesimally small probability (i.e. sch < eps or sch >
	// 1-eps), to the boundary
	sch = sch <= (1.0f-0.001f) ? sch : 1.0f;
	sch = sch >= 0.001f ? sch : 0.0f;

	return sch;
}

// Refraction, derivation shown in
// https://graphics.stanford.edu/courses/cs148-10-summer/docs/2006--degreve--reflection_refraction.pdf
bool refract(Vec3 &wo, float cos_itheta, const Vec3 &norm, const Vec3 &dir, float ior1, float ior2)
{
	float ror = ior1/ior2;

	// Refracted sin theta squared
	float sin2_rtheta = ror * ror * (1 - cos_itheta * cos_itheta);

	// Total internal reflection
	if (sin2_rtheta > 1.0f)
		return false;

	wo = ror * dir - norm * (ror * cos_itheta + sqrt(1-sin2_rtheta));
	return true;
}

Color Dielectric::sample(const Scene &sc, Hit &hit,
						 const Ray &r, RandGen &rng) const
{
	if (r.depth == r.max_depth)
		return sc.get_background({0.0});

	Vec3 norm;
	float ior1, ior2;

	// If hitting back of object invert indicies of refraction, this
	// is a hack until the ray ior is properly implemented
	float cos_itheta = Vec3::dot(hit.norm, r.direction);
	if (cos_itheta > 0.0f)
	{
		norm = -1 * hit.norm;
		ior1 = ior;
		ior2 = 1;
	}
	else
	{
		cos_itheta *= -1;
		norm = hit.norm;
		ior1 = 1;
		ior2 = ior;
	}

	Vec3 wo;
	float prob;

	// refract either returns false for TIR, or true and sets wo
	bool refr = refract(wo, cos_itheta, norm, r.direction, ior1, ior2);
	Vec3 refl = Vec3::reflect(hit.norm, r.direction);

	if (refr)
	{
		// Probability of transmission is 1 minus probability of reflection
		prob = 1 - schlick(cos_itheta, ior1, ior2);

		if (rng.uniform() > prob)
		{
			prob = 1.0f - prob;
			wo = refl;
		}
	}
	else
	{
		wo = refl;
		prob = 1.0f;
	}

	Ray ro(hit.hit_pos, wo, r.depth+1);
	if(sc.nearest_hit(ro, hit))
		return hit.mat->sample(sc, hit, ro, rng);

	return sc.get_background(wo);
}
