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
    virtual bool is_emissive() const = 0;
};

class DebugNormMaterial : public Material
{
public:
  DebugNormMaterial() = default;

	Color sample(const Scene &sc, Hit &hit,
						 const Ray &r, RandGen &rng) const override {
      return hit.norm;
    }

  bool is_emissive() const override {
    return true;
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

	Color sample_brdf(const Scene &sc, Hit &hit,
                      const Ray &r, RandGen &rng) const;

    Color sample_light(const Scene &sc, const Hit &h, const Ray &r,
                       const Vec3 &orig, RandGen &rng) const;

	Color sample(const Scene &sc, Hit &hit,
				 const Ray &r, RandGen &rng) const override;

  bool is_emissive() const override {
    return ke.r != 0.f || ke.g != 0.f || ke.b != 0.f;
  }
};

class Mirror: public Material
{
public:
	Mirror() {}

	Color sample(const Scene &sc, Hit &hit,
				 const Ray &r, RandGen &rng) const override;

  bool is_emissive() const override {
    return false;
  }
};

class Dielectric: public Material
{
private:
	float ior;
public:
	Dielectric(float ior) : ior(ior) {}

	Color sample(const Scene &sc, Hit &hit,
				 const Ray &r, RandGen &rng) const override;

  bool is_emissive() const override {
    return false;
  }
};
