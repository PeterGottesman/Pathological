// Includes gl - do this first
#include "window.h"
#include "camera.h"
#include "scene.h"
#include "ray.h"
#include "sphere.h"
#include "triangle.h"

#include <cstdio>
#include <string>
#include <array>
#include <chrono>

#include <GLFW/glfw3.h>

const int WIDTH = 400;
const int HEIGHT = 400;

int main(int argc, char **argv)
{
	Window win(WIDTH, HEIGHT, "Nifty stuff");
	int width = win.get_width()/2;
	int height = win.get_height()/2;

	Vec3 cam_pos(0, 0.0, 7.0);

	Vec3 look_at(0, 0, 0);
	Vec3 cam_up = Vec3(0, 1, 0);

	Scene sc;
	Camera cam(sc, cam_pos, look_at, cam_up, width, height, 45);

	void *pixels;

	Vec3 origin(0.0, 0.0, 0.0);
	Vec3 ymin(0.0, -5.0, 0.0);
	Vec3 ymax(0.0, 5.0, 0.0);

	Vec3 xmin(-5.0, 0.0, 0.0);
	Vec3 xmax(5.0, 0.0, 0.0);

	Vec3 nullnorms(0.0, 0.0, 0.0);

	Color red(1.0, 0.0, 0.0);
	Color green(0.0, 1.0, 0.0);
	Color blue(0.0, 0.0, 1.0);
	Color cyan(0.0, 1.0, 1.0);
	Color yellow(1.0, 1.0, 0.0);
	Color white(1.0, 1.0, 1.0);
	Material *light = new Lambertian({0.3}, white*30);
	Material *redtris = new Lambertian(red, {});
	Material *whitetris= new Lambertian(white, {});
	Material *greentris = new Lambertian(green, {});

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
	sc.add_renderable(new Triangle(floor1, {nullnorms}, whitetris));
	sc.add_renderable(new Triangle(floor2, {nullnorms}, whitetris));

	// Ceiling
	sc.add_renderable(new Triangle(ceil1, {nullnorms}, whitetris));
	sc.add_renderable(new Triangle(ceil2, {nullnorms}, whitetris));

	// Left wall
	sc.add_renderable(new Triangle(left1, {nullnorms}, redtris));
	sc.add_renderable(new Triangle(left2, {nullnorms}, redtris));

	// Right wall
	sc.add_renderable(new Triangle(right1, {nullnorms}, greentris));
	sc.add_renderable(new Triangle(right2, {nullnorms}, greentris));

	// Back wall
	sc.add_renderable(new Triangle(back1, {nullnorms}, whitetris));
	sc.add_renderable(new Triangle(back2, {nullnorms}, whitetris));

	// Ceiling light
	sc.add_renderable(new Triangle(light1, {nullnorms}, light));
	sc.add_renderable(new Triangle(light2, {nullnorms}, light));

	sc.add_renderable(new Sphere(
						  Vec3{1.0f, -2.0f, -1.0f},
						  0.5f,
						  greentris
						  ));

	while (!win.should_quit())
	{
		pixels = cam.render_image();
		win.display_texture(width, height, (char *)pixels);
	}
}
