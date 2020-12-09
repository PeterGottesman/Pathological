#pragma once

#include "vec3.h"

const int MAX_DEPTH = 5;
const float MAX_RAY_LENGTH = 100.0;

class Material;

struct Hit {
	float dist;
	Vec3 origin;
	Vec3 hit_pos;
	Vec3 dir_in;
	Vec3 norm;

	const Material *mat;
};

struct Ray {
	Vec3 origin;
	Vec3 direction;
	int max_depth;
	float max_dist;

	Ray(int depth=MAX_DEPTH,
		float max_dist=MAX_RAY_LENGTH)
		: max_depth(depth), max_dist(max_dist) {}

	Ray(Vec3 ori, Vec3 dir,
		int depth=MAX_DEPTH,
		float max_dist=MAX_RAY_LENGTH)
		: origin(ori), direction(dir), max_depth(depth),
		  max_dist(max_dist) {}
};
