#include "ray.h"
#include "scene.h"
#include "triangle.h"
#include "sphere.h"

// TODO: Remove
#include <chrono>

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
	// thread_local long int count = 0;
	// thread_local auto start= std::chrono::high_resolution_clock::now();
	Hit tmp_hit;
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
			didhit = true;
		}
	}

	// if (++count == 100000000)
	// {
	// 	auto end = std::chrono::high_resolution_clock::now();

	// 	std::chrono::duration<double, std::milli> duration = end-start;
	// 	std::cout << "Cast 100M rays/thread in "
	// 			  << duration.count() << "ms" << std::endl;
	// 	start = end;
	// 	count = 0;
	// }

	return didhit;
}
