#pragma once

#include <array>
#include <iostream>

#include "vec3.h"
#include "ray.h"

struct Plane
{
	Vec3 pt;
	/* Plane normal */
	Vec3 norm;
	Color col;

public:

	Plane(Vec3 pt, Vec3 norm, Color col) : pt(pt), norm(norm), col(col) {}

	bool intersect(const Ray &r, Hit &h)
	{
		float denom = Vec3::dot(r.direction, norm);
		denom = denom < 0 ? -denom : denom;
		float dist = Vec3::dot((r.origin - pt), norm) / denom;
		if (denom > 1e-3 && dist > 1e-3 && dist < 10)
		{
			h.dist = dist;
			h.col = col;
			return true;
		}

		return false;
	}
};
