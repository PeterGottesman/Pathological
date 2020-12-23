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
	int depth, max_depth;
	float max_dist;
	float ior;


	Ray(int max_depth=MAX_DEPTH,
		float max_dist=MAX_RAY_LENGTH,
		float ior = 1.0f)
		: max_depth(max_depth), max_dist(max_dist), ior(ior) {}

	Ray(Vec3 ori, Vec3 dir,
		int depth=0,
		float ior = 1.0f,
		int max_depth=MAX_DEPTH,
		float max_dist=MAX_RAY_LENGTH)
		: origin(ori), direction(dir),
		  depth(depth), max_depth(max_depth),
		  max_dist(max_dist), ior(ior) {}
};
