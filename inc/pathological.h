#pragma once

#include <thread>
#include <atomic>

#include "scene.h"
#include "camera.h"
#include "randgen.h"
#include "renderthread.h"

class Pathological
{
private:
	// NOTE: Multiple scenes? Multiple cameras in a scene?
	Scene sc;
	Camera cam;
	unsigned tex_width, tex_height;
	void *tex;

	// Top level random generator, use to create all other generators
	unsigned seed;
	RandGen top_rand;

	std::atomic_bool running;
	unsigned nthreads;
	std::vector<RenderThread> threads;
	std::vector<RenderRegion> regions;

public:
	Pathological(unsigned w, unsigned h,
				 unsigned numthreads = std::thread::hardware_concurrency())
		: cam(sc), tex_width(w), tex_height(h),
		  top_rand(RandGen::rand_dev_seeded_generator(seed)),
		  nthreads(numthreads)
	{
		std::cout << "Random generator initialized with seed '"
				  << seed << "'" << std::endl;

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

	void *get_texture(void) const
	{
		return tex;
	}

	// Main loop for pathtracer execution, to be run in it's own
	// thread.
	void run(void)
	{
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
	}

	// TODO: Scene, obj, etc loaders
	static bool load_default_scene(Scene &sc, Camera &cam);
};
