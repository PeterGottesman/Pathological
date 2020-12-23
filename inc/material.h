#pragma once

#include "vec3.h"
#include "ray.h"
#include "randgen.h"

class Scene;

class Material
{
public:
	Material() {};

	virtual Color sample(const Scene &sc, Hit &hit,
						 const Ray &r, RandGen &rng) const
	{
		return hit.norm;
	}
};

class Lambertian: public Material
{
private:
	// diffuse, emissive
	Color kd, ke;
public:
	Lambertian(Color kd, Color ke)
		: kd(kd), ke(ke) {}

	Color sample(const Scene &sc, Hit &hit,
				 const Ray &r, RandGen &rng) const override;
};

class Mirror: public Material
{
public:
	Mirror() {}

	Color sample(const Scene &sc, Hit &hit,
				 const Ray &r, RandGen &rng) const override;
};

};
