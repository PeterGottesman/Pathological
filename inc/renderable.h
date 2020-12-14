#pragma once

#include "ray.h"
#include "material.h"

class Renderable
{
protected:
	const Material *mat;

public:
	Renderable(const Material *mat) : mat(mat) {};
	virtual ~Renderable() = default;
	virtual bool intersect(const Ray &r, Hit &h) = 0;
	virtual Vec3 get_normal(const Vec3 &pt) = 0;
	virtual void get_normal(const Vec3 &pt, Vec3 &norm) = 0;
};
