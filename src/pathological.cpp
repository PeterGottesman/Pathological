#include "pathological.h"
#include "sphere.h"
#include "triangle.h"

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

	Vec3 l_fru{0.5f, 2.99f, -0.25f};
	Vec3 l_flu{-0.5f, 2.99f, -0.25f};
	Vec3 l_bru{0.5f, 2.99f, -0.75f};
	Vec3 l_blu{-0.5f, 2.99f, -0.75f};

	Vec3 fru{2.0f, 3.0f, 0.0f};
	Vec3 flu{-2.0f, 3.0f, 0.0f};
	Vec3 bru{2.0f, 3.0f, -2.0f};
	Vec3 blu{-2.0f, 3.0f, -2.0f};

	Vec3 frd{2.0f, -3.0f, 0.0f};
	Vec3 fld{-2.0f, -3.0f, 0.0f};
	Vec3 brd{2.0f, -3.0f, -2.0f};
	Vec3 bld{-2.0f, -3.0f, -2.0f};

	std::array<Vec3, 3> light1 = {l_fru, l_bru, l_blu};
	std::array<Vec3, 3> light2 = {l_fru, l_blu, l_flu};

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

	// Ceiling light
	sc.add_renderable(new Triangle(light1, {0.0}, light));
	sc.add_renderable(new Triangle(light2, {0.0}, light));

	sc.add_renderable(new Sphere(
						  Vec3{1.0f, -2.0f, -1.0f},
						  0.5f,
						  greenmat
						  ));

	Vec3 cam_pos(0, 0.0, 7.0);

	Vec3 look_at(0, 0, 0);
	Vec3 cam_up = Vec3(0, 1, 0);

	cam.look_at(look_at, cam_up);
	cam.set_pos(cam_pos);

	return true;
}
