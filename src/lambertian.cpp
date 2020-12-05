#include <iostream>
#include <cmath>
#include <algorithm>

#include "ray.h"
#include "vec3.h"
#include "material.h"
#include "scene.h"
#include "randgen.h"

unsigned seed;
RandGen r = RandGen::rand_dev_seeded_generator(seed);

static Vec3 sample_hemisphere_uniform(const Vec3 &norm)
{
	// Unit vector that isn't collinear with norm, use to create basis
	Vec3 not_norm = std::abs(norm.x) > 0.9
		? Vec3(0.0, 1.0, 0.0) : Vec3(1.0, 0.0, 0.0);

	// Coordinate system around norm
	Vec3 y_axis = Vec3::normalize(Vec3::cross(norm, not_norm));
	Vec3 x_axis = Vec3::cross(y_axis, norm);
	
	// To get a random point on a sphere, generating a random value of
	// theta and phi is not valid, this would result in many points at
	// the poles.

	// http://www.pbr-book.org/3ed-2018/Monte_Carlo_Integration/2D_Sampling_with_Multidimensional_Transformations.html

	float theta = 2 * M_PI * r.uniform();
	float cos_phi = r.uniform(); // phi = acos(cos_phi)

	// Shortcut spherical to cartesian using sin(acos(x)) = sqrt(1 - x*x)
	float sin_phi = std::sqrt(std::max(0.0, 1.0 - cos_phi * cos_phi));
	Vec3 cart = {
		sin_phi * std::cos(theta),
		sin_phi * std::sin(theta),
		cos_phi
	};
	return cart.x * x_axis +
		cart.y * y_axis +
		cart.z * norm;
}

Color Lambertian::sample(const Scene &sc,
						 const Vec3 &pos,
						 const Vec3& norm,
						 const int depth) const
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
	if (depth == 0) return ke;
	float prob = M_1_PI/2;

 	// I do not fully understand the derivation for this, but the
	// brdf is albedo/pi.
	Color brdf = kd * M_1_PI;

	Vec3 wo = sample_hemisphere_uniform(norm);
	Ray r(pos, wo, depth-1);

	// Reflected light is proportional to cos(theta)
	float cos_theta = Vec3::dot(norm, r.direction);

	Hit h;
	Color diffuse(0.0);

	if (cos_theta > 1e-3 && sc.nearest_hit(r, h))
	{
		Color light_in = h.mat->sample(sc, h.pos, h.norm, r.max_depth);
		diffuse = (light_in * brdf * cos_theta)/prob; 
	}

	// return r.direction;
	return ke + diffuse;
}
