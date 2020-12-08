#include "material.h"
#include "scene.h"

Color Mirror::sample(const Scene &sc, const Hit &in_hit, const int depth) const
{
	Vec3 wo = in_hit.dir_in + 2*in_hit.norm;
	if (depth == 0)
		return sc.get_background(wo);

	Hit h;
	Ray r(in_hit.hit_pos, wo, depth-1);
	if(sc.nearest_hit(r, h))
		return h.mat->sample(sc, h, depth-1);

	return sc.get_background(wo);
}
