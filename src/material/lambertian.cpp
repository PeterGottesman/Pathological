#include <iostream>
#include <cmath>
#include <algorithm>

#include "ray.h"
#include "vec3.h"
#include "material.h"
#include "scene.h"
#include "randgen.h"

Color Lambertian::sample(const Scene &sc,
						 Hit &hit,
						 const Ray &r,
						 RandGen &rng) const
{
	// Sampling the entire hemisphere would be a double integral
	// over theta (polar) [0, pi/2] and phi (azimuth) [0, 2pi]. This integration is
	// of the form:

	// Int_phi[Int_theta[f(theta,phi) rho^2 sin(theta) d_theta]d_phi]
	// 0 <= phi <= 2pi, 0 <= theta <= pi/2, rho = radius

	// For a this model, the integrand function f does not vary
	// with phi and the radius is always 1, so this simplifies to:

	// 2pi * Int_theta[ f(...,theta) sin(theta) d_theta]
	// 0 <= theta <= pi/2

	// Probability of choosing any specific point on a unit
	// hemisphere is sin(theta)/2pi. The sin(theta) in the
	// numerator cancels with the sin(theta) in the integral
	// above.
	if (r.depth == r.max_depth) return ke;
	float prob = M_1_PI/2;

	// This comes from integrating (brdf*kd*cos_theta*light_in) over
	// the unit hemisphere. To properly conserve energy, this integral
	// should evaluate to at most the incoming light - a surface can
	// only scatter as much light as it receives. This will evaluate
	// to (pi*brdf*kd*li) <= li, as the brdf is a constant. Given kd
	// has no element greater than 1, this results in brdf=1/PI. Great
	// explanation here:
	// http://www.rorydriscoll.com/2009/01/25/energy-conservation-in-games/
	Color brdf = M_1_PI;

	Vec3 wo = RandGen::sample_hemisphere_uniform(hit.norm, rng);
	Ray ro(hit.hit_pos, wo, r.depth+1);

	// Reflected light is proportional to cos(theta)
	float cos_theta = Vec3::dot(hit.norm, ro.direction);

	Color diffuse(0.0);

	if (cos_theta > 1e-3 && sc.nearest_hit(ro, hit))
	{
		Color light_in = hit.mat->sample(sc, hit, ro, rng);
		Color atten = kd * cos_theta * brdf/prob;
		diffuse = light_in * atten;

	}

	return ke + diffuse;
}
