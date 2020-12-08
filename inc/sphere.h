#pragma once

#include <array>
#include <iostream>

#include "vec3.h"
#include "ray.h"
#include "renderable.h"

struct Sphere : public Renderable
{
	Vec3 center;
	float radius;

public:

	Sphere(const Vec3 &center, const float &rad, const Material *mat)
		: Renderable(mat), center(center), radius(rad) {}

	bool intersect(const Ray &r, Hit &h)
	{
		// Line from origin to center of sphere
		Vec3 ln = r.origin - center;

		// dot(r.dir, r.dir), r.dir is a unit vec, so this is always 1
		float a = 1;

		// proj ray dir onto line to center
		float b = 2 * Vec3::dot(ln, r.direction);

		// sqmag of ln - radius squared
		float c = Vec3::dot(ln, ln) - radius * radius;

		// Calculate discriminant
		float dsc = b*b - 4*a*c;

		if (dsc >= 0)
		{
			float dsc_root = sqrt(dsc);
			float x0 = (-b + dsc_root)/2;
			float x1 = (-b - dsc_root)/2;
			h.dist = x0 < x1 ? x0 : x1;
			h.mat = mat;
			h.hit_pos = r.origin + r.direction * h.dist;
			h.norm = Vec3::normalize(h.hit_pos - center);
			return h.dist > 0;
		}

		return false;
	}
};
