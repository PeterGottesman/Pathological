#include "randgen.h"

Vec3 RandGen::sample_hemisphere_uniform(const Vec3 &norm, RandGen &rg)
{
	// This is a bit ugly, _buuut_ it results in a 3x speedup. If rg
	// is used, there are massive delays due to cache misses in the
	// mersenne twister engine.
	static thread_local unsigned seed;
	static thread_local RandGen rng = rg.randgen_seeded_generator(seed);

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

	float theta = 2 * M_PI * rng.uniform();
	float cos_phi = rng.uniform(); // phi = acos(cos_phi)

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
