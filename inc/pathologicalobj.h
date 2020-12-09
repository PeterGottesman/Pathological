#pragma once

#include "randgen.h"

class PathologicalObject
{
private:
	friend class Pathological;
	PathologicalObject()
		: rand(RandGen::rand_dev_seeded_generator(seed))
		{}

protected:
	// Top level random generator, use to create all other generators
	unsigned seed;
	RandGen rand;

	PathologicalObject(RandGen &rng)
		: rand(rng.randgen_seeded_generator(seed))
		{}
};
