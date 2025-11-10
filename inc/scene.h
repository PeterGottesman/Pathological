#pragma once

#include <memory>
#include <stdint.h>
#include <vector>

#include "ray.h"
#include "renderable/renderable.h"

class Scene
{
  private:
	// TODO: Is this a proper use of unique_ptr?
	std::vector<Renderable*> renderables;
	std::vector<Renderable*> emissives;

	Color bg;

  public:
	Scene()
	{
	}
	Scene(const Color& background) : bg(background)
	{
	}

	Color get_background(const Vec3& dir) const
	{
		return bg;
	}
	void set_background(const Color& c)
	{
		bg = c;
	}

	bool any_hit(const Ray& r, Hit& h) const;
	bool nearest_hit(const Ray& r, Hit& h) const;

	void add_renderable(Renderable* rend)
	{
		renderables.push_back(rend);
		if (rend->is_emissive())
		{
			emissives.push_back(rend);
		}
	}

	const std::vector<Renderable*>& get_renderables() const
	{
		return renderables;
	}
	const std::vector<Renderable*>& get_emissives() const
	{
		return emissives;
	}
};