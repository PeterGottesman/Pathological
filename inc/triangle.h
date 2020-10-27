#pragma once

#include <array>
#include <iostream>

#include "vec3.h"
#include "ray.h"
#include "renderable.h"

class Triangle : public Renderable
{
	/* Vertices, Vertex Normals */
	std::array<Vec3, 3> v;
	std::array<Vec3, 3> n;

	// Edges
	std::array<Vec3, 2> e;

	/* Triangle face normal and unnormalized version*/
	Vec3 norm, cross_edges;

public:

	Triangle(const std::array<Vec3, 3> &verts = {},
			 const std::array<Vec3, 3> &norms = {},
			 const Material *mat = {})
		: Renderable(mat), v(verts), n(norms)
	{
		e[0] = v[1] - v[0];
		e[1] = v[0] - v[2];
		cross_edges = Vec3::cross(e[1], e[0]);
		norm = Vec3::normalize(cross_edges);
	}

	bool intersect(const Ray &r, Hit &h) override
	{
		Vec3 e2 = (1.0f/Vec3::dot(cross_edges, r.direction)) * (v[0] - r.origin);
		Vec3 i = Vec3::cross(r.direction, e2);

		float beta = Vec3::dot(i, e[1]);
		float gamma = Vec3::dot(i, e[0]);
		float dist = Vec3::dot(cross_edges, e2);

		h.mat = mat;
		h.dist = dist;
		h.pos = r.origin + r.direction * h.dist;
		h.norm = norm;
		return (dist > 0) & (beta >= 0) & (gamma >= 0) & (beta+gamma<=1);
	}
};
