#include <cstdio>

#include "benchmark.h"
#include "camera.h"
#include "scene.h"
#include "sphere.h"
#include "triangle.h"
#include "randgen.h"

template<class Func, class ...Args>
constexpr float Benchmark::bench(Func &&f, int samples, Args &&...args)
{
	Timer t;
	t.start();
	for (int i = 0; i < samples; ++i)
		f(args...);
	t.stop();

	return t.get_cnt_per_ms(samples);
}

void Benchmark::bench_tris(int samples)
{
	RandGen rng(BENCH_SEED);

	Scene sc(Color(0.0));
	Camera cam(sc, rng);

	Lambertian lamb({0.2}, {1.0});

	printf("Running on scene with 1000 randomly placed triangles\n");
	// Generate tris 
	for (int i = 0; i < 1000; ++i)
	{
		Vec3 v1(
			rng.uniform_range(-10.0, 10.0),
			rng.uniform_range(-10.0, 10.0),
			rng.uniform_range(-10.0, 10.0)
			);
		Vec3 v2(
			rng.uniform_range(-10.0, 10.0),
			rng.uniform_range(-10.0, 10.0),
			rng.uniform_range(-10.0, 10.0)
			);
		Vec3 v3(
			rng.uniform_range(-10.0, 10.0),
			rng.uniform_range(-10.0, 10.0),
			rng.uniform_range(-10.0, 10.0)
			);
		sc.add_renderable(new Triangle(
							  {v1, v2, v3}, // Verts
							  {{0.0}},		// Vertex normals
							  &lamb			// mat
							  ));
	}

	// Generate pixel offsets
	std::vector<Vec3> offsets;
	offsets.reserve(samples);
	for (int i = 0; i < samples; ++i)
	{
		offsets.push_back({
				rng.uniform_range(0, BENCH_WIDTH),
				rng.uniform_range(0, BENCH_HEIGHT),
				0.0
			});
	}

	Ray r;
	int i = 0;
	float sample_ms = bench([&](const std::vector<Vec3> &offsets, int &i) {
		cam.get_pixel_ray(r, 0, 0, offsets[i]);
		cam.cast_ray(r, rng);
		i+=1;
	}, samples, offsets, i);
		
	printf("%f million paths per second\n", sample_ms/1000);
}

void Benchmark::bench_spheres(int samples)
{
	RandGen rng(BENCH_SEED);

	Scene sc(Color(0.0));
	Camera cam(sc, rng);

	Lambertian lamb({0.2}, {1.0});

	printf("Running on scene with 1000 randomly placed spheres\n");
	// Generate spheres
	for (int i = 0; i < 1000; ++i)
	{
		Vec3 center(
			rng.uniform_range(-10.0, 10.0),
			rng.uniform_range(-10.0, 10.0),
			rng.uniform_range(-10.0, 10.0)
			);
		sc.add_renderable(new Sphere(
							  center,		 // center
							  rng.uniform(), // rad
							  &lamb			 // mat
							  ));
	}

	// Generate pixel offsets
	std::vector<Vec3> offsets;
	offsets.reserve(samples);
	for (int i = 0; i < samples; ++i)
	{
		offsets.push_back({
				rng.uniform_range(0, BENCH_WIDTH),
				rng.uniform_range(0, BENCH_HEIGHT),
				0.0
			});
	}

	Ray r;
	int i = 0;
	float sample_ms = bench([&](const std::vector<Vec3> &offsets, int &i) {
		cam.get_pixel_ray(r, 0, 0, offsets[i]);
		cam.cast_ray(r, rng);
		i+=1;
	}, samples, offsets, i);
		
	printf("%f million paths per second\n", sample_ms/1000);
}
