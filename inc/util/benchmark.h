#pragma once

#include <functional>

#include "timer.h"

class Benchmark
{
private:
	static const int BENCH_SEED = 214231;
	static const int BENCH_SAMPLES = 5e6;
	static const int BENCH_WIDTH = 512;
	static const int BENCH_HEIGHT = 512;

public:
	template<class Func, class ...Args>
	static constexpr float bench(Func &&f, int samples, Args &&...args);

	static void bench_tris(int samples = BENCH_SAMPLES);
	static void bench_spheres(int samples = BENCH_SAMPLES);
};
