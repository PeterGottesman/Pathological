#pragma once

#include "ray.h"
#include "material.h"

class Renderable
{
protected:
	const Material *mat;

public:
	Renderable(const Material *mat) : mat(mat) {};
	virtual bool intersect(const Ray &r, Hit &h) = 0;
	virtual Vec3 get_normal(const Vec3 &pt) = 0;
    virtual Vec3 uniform_random_point(RandGen& rng) = 0;
    virtual float get_area() const = 0;
    bool is_emissive() { return mat->is_emissive(); }
};
