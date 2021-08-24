#pragma once

#include <cmath>
#include <iostream>
#include <math.h>

#include "ray.h"
#include "vec3.h"
#include "randgen.h"

class Scene;

class Camera
{
	// TODO: randomized multisampling
	unsigned seed;
	RandGen rand;

	const Vec3 lower_left = {-0.5, -0.5, 0};
	Vec3 pix_size;

	Scene &scene;
	Color *image = nullptr;
	unsigned *iters = nullptr;
	unsigned spp;

	Vec3 location;				// Coordinates of camera in world
								// space

	Vec3 dir;
	Vec3 look_point;

	Vec3 up;					// Camera's up direction, normalized

	Vec3 ip_origin;			    // 0,0 of image plane, center of image
	Vec3 x_axis, y_axis;		// x, y axes of image plane

	unsigned width, height;
	float aspect;
	float hfov, vfov; 			   // Vert && Horiz field of view

public:
	Camera(Scene &scene, unsigned spp, RandGen &rng)
		:  rand(rng), scene(scene), spp(spp) {}

	Camera(Scene &scene, unsigned spp, Vec3 loc, Vec3 look,
		   Vec3 up_dir, int w, int h, int fov, RandGen &rng)
		: rand(rng), scene(scene), spp(spp),
		  location(loc), look_point(look), up(up_dir)
		{
			look_at(look_point, up);
			set_image_props(w, h, fov);
		}

	~Camera()
	{
		destroy_image();
	};

	Color calc_pix(int x, int y) const;
	Color cast_ray(Ray &ray, RandGen &rand);
	Color *render_image(void);
	void get_pixel_ray(Ray &r, unsigned x, unsigned y, const Vec3 &offset) const;

	bool any_hit(const Ray &r, Hit &h) const;
	bool nearest_hit(const Ray &r, Hit &h) const;

	Color *get_image_buf(void) const { return image; }
	unsigned *get_iters_buf(void) const { return iters; }
	unsigned get_spp(void) { return spp; }

	Color *make_image_buf(void *image_buf)
	{
		if (image != nullptr)
			destroy_image();

		image = (image_buf != nullptr) ? (Color *)image_buf
			                           : new Color[width * height];
		iters = new unsigned[width * height];
		return image;
	}

	void destroy_image(void)
	{
		delete[] image;
		delete[] iters;
		image = nullptr;
		iters = nullptr;
	}

	void set_image_bounds(unsigned w, unsigned h)
	{
		width = w;
		height = h;
		aspect = (float)w/h;
		pix_size = Vec3(1.0/width, 1.0/height, 0.0);
	}

	void set_image_fov(int fov)
	{
		hfov = M_PI/180.0 * fov;
		vfov = 2 * std::atan2(std::tan((float)hfov/2), aspect);
	}

	void set_image_props(unsigned w, unsigned h,
						 int fov, void *image_buf = nullptr)
	{
		set_image_bounds(w, h);
		set_image_fov(fov);
		make_image_buf(image_buf);
	}

	void set_pos(const Vec3 &loc)
	{
		this->location = loc;
		look_at(this->look_point, this->up);
	}


	void look_at(const Vec3 &point, const Vec3 &up)
	{
		this->look_point = point;
		this->up = Vec3::normalize(up);

		// Direction straight ahead
		this->dir = Vec3::normalize(point-this->location);

		this->x_axis = Vec3::normalize(
			Vec3::cross(this->dir, this->up)
			);
		this->y_axis = Vec3::normalize(up);
	}
};
