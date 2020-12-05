#pragma once

#include <cmath>
#include <iostream>
#include <math.h>

#include "ray.h"
#include "vec3.h"
#include "scene.h"

class Camera
{
	Scene &scene;
	Vec3 location;				// Coordinates of camera in world
								// space

	Vec3 dir;
	Vec3 look;

	Vec3 up;					// Camera's up direction, normalized

	Vec3 ip_origin;			    // 0,0 of image plane, center of image
	Vec3 x_axis, y_axis;		// x, y axes of image plane

	unsigned width, height;
	float aspect;
	float hfov, vfov; 			   // Vert && Horiz field of view

	Color *image;

public:
	Camera(Scene &sc, Vec3 loc, Vec3 look,
		   Vec3 up_dir, int w, int h, int fov)
		: scene(sc), location(loc), look(look),
		  up(up_dir), width(w), height (h)
		{
			aspect = (float)width/height;

			look_at(look);

			hfov = M_PI/180.0 * fov;
			vfov = 2 * std::atan2(std::tan((float)hfov/2), aspect);

			// Create image plane
			image = new Color[width*height]{0};
		}

	~Camera()
	{
		delete[] image;
	};


	Color calc_pix(int x, int y) const;
	Color *render_image();
	bool any_hit(const Ray &r, Hit &h) const;
	bool nearest_hit(const Ray &r, Hit &h) const;

	void set_pos(const Vec3 &loc)
	{
		this->location = loc;
		look_at(this->look);
	}

	void look_at(const Vec3 &point)
	{
		this->look = point;
		// Direction straight ahead
		this->dir = Vec3::normalize(point-this->location);

		this->x_axis = Vec3::normalize(
			Vec3::cross(this->dir, this->up)
			);
		this->y_axis = Vec3::normalize(up);
	}
};
