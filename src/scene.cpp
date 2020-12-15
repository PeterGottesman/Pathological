#include "ray.h"
#include "scene.h"
#include "triangle.h"
#include "sphere.h"

bool Scene::any_hit(const Ray &r, Hit &h) const
{
	for (auto &rend : renderables)
	{
		if(rend->intersect(r, h))
		{
			h.hit_pos = r.origin + r.direction * h.dist;
			rend->get_normal(h.hit_pos, h.norm);
			return true;
		}
	}

	return false;
}

bool Scene::nearest_hit(const Ray &r, Hit &h) const
{
	Hit tmp_hit;
	Renderable *closest;
	tmp_hit.dir_in = r.direction;

	float min_d = r.max_dist;
	bool didhit = false;
	for (auto &rend : renderables)
	{
		if(rend->intersect(r, tmp_hit) && tmp_hit.dist < min_d)
		{
			if (tmp_hit.dist > min_d) continue;
			min_d = tmp_hit.dist;
			h = tmp_hit;
			closest = rend;
			didhit = true;
		}
	}

	if (didhit)
	{
		h.hit_pos = r.origin + r.direction * h.dist;
		closest->get_normal(h.hit_pos, h.norm);
	}

	return didhit;
}
