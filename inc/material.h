#pragma once

#include "vec3.h"
#include "ray.h"
#include "randgen.h"

class Scene;

class Material
{
public:
  Material() = default;

	virtual Color sample(const Scene &sc, Hit &hit,
						 const Ray &r, RandGen &rng) const = 0;
};

class DebugNormMaterial : public Material
{
public:
  DebugNormMaterial() = default;

	Color sample(const Scene &sc, Hit &hit,
						 const Ray &r, RandGen &rng) const override {
      return hit.norm;
    }
};

class Lambertian: public Material
{
private:
	// diffuse, emissive
	Color kd, ke;
public:
	Lambertian(const Color& kd, const Color& ke)
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

class Dielectric: public Material
{
private:
	float ior;
public:
	Dielectric(float ior) : ior(ior) {}

	Color sample(const Scene &sc, Hit &hit,
				 const Ray &r, RandGen &rng) const override;
};
