#pragma once

#include <cmath>
#include <iostream>
#include <math.h>

#include "ray.h"
#include "vec3.h"

class Scene;

class Camera
{
	Scene &scene;
	Color *image = nullptr;

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
	Camera(Scene &scene) : scene(scene) {}
	Camera(Scene &scene, Vec3 loc, Vec3 look,
		   Vec3 up_dir, int w, int h, int fov)
		: scene(scene), location(loc), look_point(look),
		  up(up_dir), width(w), height (h)
		{
			look_at(look_point, up);
			set_image_fov(fov);
			make_image_buf();
		}

	~Camera()
	{
		destroy_image();
	};

	Color calc_pix(int x, int y) const;
	Color *render_image(void);
	bool any_hit(const Ray &r, Hit &h) const;
	bool nearest_hit(const Ray &r, Hit &h) const;

	Color *get_image_buf(void) const { return image; }

	Color *make_image_buf(void)
	{
		if (image != nullptr)
			destroy_image();

		image = new Color[width * height];
		return image;
	}

	void destroy_image(void)
	{
		delete[] image;
		image = nullptr;
	}

	void set_image_bounds(unsigned w, unsigned h)
	{
		width = w;
		height = h;
		aspect = (float)w/h;
	}

	void set_image_fov(int fov)
	{
		hfov = M_PI/180.0 * fov;
		vfov = 2 * std::atan2(std::tan((float)hfov/2), aspect);
	}

	void set_image_props(unsigned w, unsigned h,
						 int fov, void *image_buf = nullptr)
	{
		width = w;
		height = h;
		aspect = (float)w/h;

		set_image_fov(fov);

		if (image_buf != nullptr)
			image = (Color *)image_buf;
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
