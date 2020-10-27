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
};
