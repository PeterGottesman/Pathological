#include "material.h"
#include "scene.h"

Vec3 reflect(const Vec3 &norm, const Vec3 &wi)
{
	return wi - 2.0 * norm * Vec3::dot(norm, wi);
}

Color Mirror::sample(const Scene &sc, const Hit &in_hit,
					 const int depth, RandGen &rng) const
{
	Vec3 wo = reflect(in_hit.norm, in_hit.dir_in);
	if (depth == 0)
		return sc.get_background(wo);

	Hit h;
	Ray r(in_hit.hit_pos, wo, depth-1);
	if(sc.nearest_hit(r, h))
		return h.mat->sample(sc, h, depth-1, rng);

	return sc.get_background(wo);
}
