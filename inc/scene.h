#pragma once

#include <memory>
#include <vector>
#include <stdint.h>

#include "ray.h"
#include "renderable.h"
#include "light.h"

class Scene
{
private:
	// TODO: Is this a proper use of unique_ptr?
	std::vector<Renderable *> renderables;

	// TODO: At the moment all non-ambient light is from emissive objects
	// add explicit lights at a later time
	// std::vector<std::unique_ptr<Light>> lights;

public:
	bool any_hit(const Ray &r, Hit &h) const;
	bool nearest_hit(const Ray &r, Hit &h) const;

	void add_renderable(Renderable *rend)
	{
		renderables.push_back(rend);
	}
};
