#pragma once

#include "vec3.h"
#include "ray.h"

class Scene;

class Material
{
private:
	Color c;

public:
	Material() {};
	

	// TODO: Where should I be calling this?
	// How should I be passing the scene data around?
	virtual Color sample(const Scene &sc, const Vec3 &pos,
						 const Vec3& norm, const int depth) const
	{
		return norm;
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

	Color sample(const Scene &sc, const Vec3 &pos,
				 const Vec3& norm, const int depth) const override;
};
