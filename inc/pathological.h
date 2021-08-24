#pragma once

#include <thread>
#include <atomic>
#include <cstdio>

#include "scene.h"
#include "camera.h"
#include "renderthread.h"
#include "randgen.h"
#include "util/exporter.h"

#include "util/timer.h"

class Pathological
{
private:
	unsigned seed;
	RandGen rand;

	// NOTE: Multiple scenes? Multiple cameras in a scene?
	Scene sc;
	Camera cam;
	unsigned tex_width, tex_height;
	void *tex;
	Timer timer;

	std::atomic_bool running;
	unsigned nthreads;
	std::vector<RenderThread> threads;
	std::vector<RenderRegion> regions;
	Exporter *exporter;

	unsigned spp;


public:
	Pathological(unsigned w, unsigned h, unsigned spp,
				 unsigned numthreads = std::thread::hardware_concurrency())
		: rand(RandGen::rand_dev_seeded_generator(seed)),
		  sc(), cam(sc, spp, rand), tex_width(w),
		  tex_height(h), nthreads(numthreads), spp(spp)
	{
		cam.set_image_props(tex_width, tex_height, 45);
		tex = cam.get_image_buf();
		load_default_scene(sc, cam);

		threads.reserve(numthreads);
		regions.reserve(numthreads);

		generate_initial_regions();
	}

	void generate_initial_regions(void);
	void schedule(void);
	void launch_threads(void);
	void add_exporter(Exporter *exp);

	void *get_texture(void) const
	{
		return tex;
	}

	// Main loop for pathtracer execution, to be run in it's own
	// thread.
	void run(void)
	{
		timer.start();
		launch_threads();
		running = true;
	}

	void stop(void)
	{
		running = false;

		// Invoke RenderThread destructor for each thread, joining and
		// cleaning up. Not the cleanest solution but it works fine
		// for the first pass and it mirrors the thread creation in
		// run()
		threads.clear();
		timer.stop();

		long long unsigned num_iters = 0;
		for (unsigned i = 0; i < tex_width*tex_height; ++i)
			num_iters += cam.get_iters_buf()[i];

		printf("Ran for %.4f ms\n", timer.get_ms());
		printf("Computed %.4f million paths per second\n",
			   timer.get_cnt_per_ms(num_iters)/1000 * spp);

		exporter->export_image();

	}

	// TODO: Scene, obj, etc loaders
	static bool load_default_scene(Scene &sc, Camera &cam);
};
