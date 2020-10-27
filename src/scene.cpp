#include "ray.h"
#include "scene.h"
#include "triangle.h"
#include "sphere.h"

bool Scene::any_hit(const Ray &r, Hit &h) const
{
	for (auto &rend : renderables)
	{
		if(rend->intersect(r, h))return true;
	}

	return false;
}

bool Scene::nearest_hit(const Ray &r, Hit &h) const
{
	Hit tmp_hit;
	float min_d = r.max_dist;
	bool didhit = false;
	for (auto &rend : renderables)
	{
		if(rend->intersect(r, tmp_hit) && tmp_hit.dist < min_d)
		{
			if (tmp_hit.dist > min_d) continue;
			min_d = tmp_hit.dist;
			h = tmp_hit;
			didhit = true;
		}
	}

	// if (didhit)
	// 	std::cout << "nearest hit was: " << min_d << std::endl;
	return didhit;
	
}
