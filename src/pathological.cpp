#include "pathological.h"
#include "sphere.h"
#include "triangle.h"

void Pathological::generate_initial_regions(void)
{
	// TODO: divide regions into squares according
	unsigned reg_height = floor((float)tex_height/nthreads);
	unsigned reg_start = 0;
	for (unsigned i = 0; i < nthreads-1; ++i)
	{
		regions.push_back(
			RenderRegion(tex_width, tex_height, // full texture dimensions
						 tex_width, reg_height, // region dimensions
						 reg_start, 0)			// region offset (r, c)
			);
		reg_start += reg_height;
	}

	// Last region is larger if need be
	regions.push_back(
		RenderRegion(tex_width, tex_height,
					 tex_width, tex_height-reg_start,
					 reg_start, 0)
		);
}

void Pathological::schedule(void)
{
	// TODO: When schedule is called, analysis is done on the threads'
	// regions and regions are recomputed

	// TODO: Maybe to this on a per-thread basis, where the thread
	// will call schedule with itself as the argument when some
	// condition is met, and will be reassigned a new region. Most
	// likely, this will just be round robin, but eventually this
	// should be based on some more complex heuristic which (off the
	// top of my head) should take into account the image's
	// convergence and the percentage of "interesting" rays (i.e. rays
	// which collide with an object.

	// TODO: It would be really cool if specific rays can be scheduled
	// to threads based on some kind of cache-optimization. There has
	// been some research into this, Daniel Kopta's dissertation seems
	// to link to good information, look around sect 2.1.4.
	// https://dkoptacs.github.io/papers/kopta_dissertation.pdf
}

void Pathological::launch_threads(void)
{
	unsigned seed;
	for (unsigned i = 0; i < nthreads; ++i)
	{
		
		threads.push_back({&cam, regions[i], rand.randgen_seeded_generator(seed)});
		threads.back().launch();
	}
}

void Pathological::add_exporter(Exporter *exp)
{
	exporter = exp;
}

bool Pathological::load_default_scene(Scene &sc, Camera &cam)
{
	// TODO: Make these Color::red, etc
	Color red(1.0, 0.0, 0.0);
	Color green(0.0, 1.0, 0.0);
	Color blue(0.0, 0.0, 1.0);
	Color cyan(0.0, 1.0, 1.0);
	Color yellow(1.0, 1.0, 0.0);
	Color white(1.0, 1.0, 1.0);

	// TODO: Transfer material and renderable ownership to scene
	// instance, destroy them in scene destructor
	Material *light = new Lambertian({0.3}, white*30);
	Material *redmat = new Lambertian(red, {});
	Material *whitemat= new Lambertian(white, {});
	Material *greenmat = new Lambertian(green, {});
	Material *mirrormat = new Mirror();
    Material *glassmat = new Dielectric(1.5);

	Vec3 l_fru{0.5f, 2.99f, -0.25f};
	Vec3 l_flu{-0.5f, 2.99f, -0.25f};
	Vec3 l_bru{0.5f, 2.99f, -0.75f};
	Vec3 l_blu{-0.5f, 2.99f, -0.75f};

	Vec3 fru{2.0f, 3.0f, 8.0f};
	Vec3 flu{-2.0f, 3.0f, 8.0f};
	Vec3 bru{2.0f, 3.0f, -2.0f};
	Vec3 blu{-2.0f, 3.0f, -2.0f};

	Vec3 frd{2.0f, -3.0f, 8.0f};
	Vec3 fld{-2.0f, -3.0f, 8.0f};
	Vec3 brd{2.0f, -3.0f, -2.0f};
	Vec3 bld{-2.0f, -3.0f, -2.0f};

	std::array<Vec3, 3> light1 = {l_bru, l_fru, l_blu};
	std::array<Vec3, 3> light2 = {l_flu, l_blu, l_fru};

	std::array<Vec3, 3> floor1 = {frd, brd, bld};
	std::array<Vec3, 3> floor2 = {frd, bld, fld};

	std::array<Vec3, 3> ceil1 = {fru, blu, bru};
	std::array<Vec3, 3> ceil2 = {fru, flu, blu};

	std::array<Vec3, 3> left1 = {flu, fld, bld};
	std::array<Vec3, 3> left2 = {flu, bld, blu};

	std::array<Vec3, 3> right1 = {fru, brd, frd};
	std::array<Vec3, 3> right2 = {fru, bru, brd};

	std::array<Vec3, 3> back1 = {bld, brd, bru};
	std::array<Vec3, 3> back2 = {bld, bru, blu};

	// Behind camera
	std::array<Vec3, 3> front1 = {frd, fld, fru};
	std::array<Vec3, 3> front2 = {fld, flu, fru};

	// Floor
	sc.add_renderable(new Triangle(floor1, {0.0}, whitemat));
	sc.add_renderable(new Triangle(floor2, {0.0}, whitemat));

	// Ceiling
	sc.add_renderable(new Triangle(ceil1, {0.0}, whitemat));
	sc.add_renderable(new Triangle(ceil2, {0.0}, whitemat));

	// Left wall
	sc.add_renderable(new Triangle(left1, {0.0}, redmat));
	sc.add_renderable(new Triangle(left2, {0.0}, redmat));

	// Right wall
	sc.add_renderable(new Triangle(right1, {0.0}, greenmat));
	sc.add_renderable(new Triangle(right2, {0.0}, greenmat));

	// Back wall
	sc.add_renderable(new Triangle(back1, {0.0}, whitemat));
	sc.add_renderable(new Triangle(back2, {0.0}, whitemat));

	// Front wall
	sc.add_renderable(new Triangle(front1, {0.0}, whitemat));
	sc.add_renderable(new Triangle(front2, {0.0}, whitemat));

	// Ceiling light
	sc.add_renderable(new Triangle(light1, {0.0}, light));
	sc.add_renderable(new Triangle(light2, {0.0}, light));

	sc.add_renderable(new Sphere(
						  Vec3{1.3f, -2.2f, -0.5f},
						  0.5f,
						  glassmat
						  ));

	// sc.add_renderable(new Sphere(
	// 					  Vec3{1.3f, -2.0f, -1.4f},
	// 					  0.5f,
	// 					  greenmat
	// 					  ));

	sc.add_renderable(new Sphere(
						  Vec3{-1.4f, -2.4f, -1.2f},
						  0.5f,
						  mirrormat
						  ));

	// sc.add_renderable(new Sphere(
	// 					  Vec3{-0.8f, -2.7f, -1.7f},
	// 					  0.25f,
	// 					  mirrormat
	// 					  ));

	Vec3 cam_pos(0, 2.0, 6.0);

	Vec3 look_at(0, 0, 0);
	Vec3 cam_up = Vec3(0, 1, 0);

	cam.look_at(look_at, cam_up);
	cam.set_pos(cam_pos);

	sc.set_background({0.0});

	return true;
}
