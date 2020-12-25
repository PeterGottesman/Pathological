#include "material.h"
#include "scene.h"

Color Mirror::sample(const Scene &sc, Hit &hit,
					 const Ray &r, RandGen &rng) const
{
	Vec3 wo = Vec3::reflect(hit.norm, r.direction);
	if (r.depth == r.max_depth)
		return sc.get_background(wo);

	Ray ro(hit.hit_pos, wo, r.depth+1);
	if(sc.nearest_hit(ro, hit))
		return hit.mat->sample(sc, hit, ro, rng);

	return sc.get_background(wo);
}
