#pragma once

#include <iostream>
#include <random>
#include "vec3.h"

class RandGen
{
private:
	unsigned seed;
	std::mt19937 engine;
	std::uniform_real_distribution<float> zero_one;

public:
	RandGen(unsigned seed)
		: seed(seed), engine(seed), zero_one(0.0, 1.0) {}

	unsigned get_seed(void)
	{
		return seed;
	}

	float uniform()
	{
		return zero_one(engine);
	}

	float uniform_range(float min, float max)
	{
		std::uniform_real_distribution<float> dist(min, max);
		return dist(engine);
	}

	// Create a new RandGen from std::random_device. Returns RandGen,
	// and sets seed to the generated seed.  This should only be used
	// to create the initial randgen. The generated seed should be
	// logged, then all future randgens should be created in a
	// deterministic order using randgen_seeded_generator. This should
	// make the run fully reproducible.
	static RandGen rand_dev_seeded_generator(unsigned &seed)
	{
		std::random_device dev;
		std::uniform_int_distribution<unsigned> dist;
		seed = dist(dev);

		std::cout << "Random generator initialized with seed '"
		          << seed << "' from random_device" << std::endl;

		return {seed};
	}

	RandGen randgen_seeded_generator(unsigned &seed)
	{
		std::uniform_int_distribution<unsigned> dist;
		seed = dist(engine);
		return {seed};
	}

	static Vec3 sample_hemisphere_uniform(const Vec3 &norm, RandGen &rg);
};
