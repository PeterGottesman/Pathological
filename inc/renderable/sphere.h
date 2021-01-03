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

	bool intersect(const Ray &r, Hit &h) override
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

		if (dsc >= 0.0f)
		{
			float dsc_root = sqrt(dsc);
			float x0 = -b + dsc_root;
			float x1 = -b - dsc_root;

			// Smallest _positive_ distance
			h.dist = ( (x0 < x1 && x0 > 1e-6) ? x0 : x1 ) / 2.0f;

			h.mat = mat;
			return h.dist > 1e-6;
		}

		return false;
	}

	Vec3 get_normal(const Vec3 &pt) override
	{
			return (pt - center)/radius;
	}

	void get_normal(const Vec3 &pt, Vec3 &norm) override
	{
			norm = (pt - center)/radius;
	}
};
