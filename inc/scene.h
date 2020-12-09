#pragma once

#include <memory>
#include <vector>
#include <stdint.h>

#include "ray.h"
#include "renderable.h"
#include "light.h"
#include "pathologicalobj.h"

class Scene : public PathologicalObject
{
private:
	// TODO: Is this a proper use of unique_ptr?
	std::vector<Renderable *> renderables;

	// TODO: At the moment all non-ambient light is from emissive objects
	// add explicit lights at a later time
	// std::vector<std::unique_ptr<Light>> lights;
	Color bg;

public:
	Scene(RandGen &rng)
		: PathologicalObject(rng) {}

	Scene(const Color &background, RandGen &rng)
		: PathologicalObject(rng), bg(background) {}

	Color get_background(const Vec3 &dir) const
	{
		// Facing fwd is black, behind is a gradient
		return bg;
	}
	void set_background(const Color &c) { bg = c; }

	bool any_hit(const Ray &r, Hit &h) const;
	bool nearest_hit(const Ray &r, Hit &h) const;

	void add_renderable(Renderable *rend)
	{
		renderables.push_back(rend);
	}

};
