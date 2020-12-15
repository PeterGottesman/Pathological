#include "material.h"
#include "scene.h"

Vec3 reflect(const Vec3 &norm, const Vec3 &wi)
{
	return wi - 2.0 * norm * Vec3::dot(norm, wi);
}

Color Mirror::sample(const Scene &sc, Hit &hit,
					 const int depth, RandGen &rng) const
{
	Vec3 wo = reflect(hit.norm, hit.dir_in);
	if (depth == 0)
		return sc.get_background(wo);

	Ray r(hit.hit_pos, wo, depth-1);
	if(sc.nearest_hit(r, hit))
		return hit.mat->sample(sc, hit, depth-1, rng);

	return sc.get_background(wo);
}
