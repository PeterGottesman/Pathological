#pragma once

#include <thread>
#include <atomic>

#include "scene.h"
#include "camera.h"
#include "randgen.h"

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

public:
	Pathological()
		: cam(sc), top_rand(RandGen::rand_dev_seeded_generator(seed))
	{
		std::cout << "Random generator initialized with seed '"
				  << seed << "'" << std::endl;

		cam.set_image_props(500, 500, 45);
		tex = cam.make_image_buf();
		load_default_scene(sc, cam);
	}

	void *get_texture(void)
	{
		return tex;
	}

	void render(void)
	{
		cam.render_image();
	}

	// Main loop for pathtracer execution, to be run in it's own
	// thread.
	void run(void)
	{
		running = true;
		while (running)
		{
			render();
		}
	}

	void stop(void)
	{
		running = false;
	}

	static bool load_default_scene(Scene &sc, Camera &cam);
};
