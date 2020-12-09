#include <cstdio>

#include "camera.h"
#include "vec3.h"
#include "ray.h"
#include "scene.h"

Color Camera::cast_ray(Ray &ray, unsigned iters)
{
	Hit hit;
	if (nearest_hit(ray, hit))
	{
		Color col(0.0);
		for (int i = 0; i < iters; ++i)
		{
			col += hit.mat->sample(this->scene, hit, ray.max_depth, rand);
		}
		return col/(float)iters;
	}

	// TODO: Scene-specific background sampling
	return scene.get_background(ray.direction);
}

void Camera::get_pixel_ray(Ray &r, unsigned x, unsigned y) const
{
	Vec3 ip_coords = lower_left + pix_size * Vec3(x, y, 0.0);

	// TODO: Mat4, Vec3*Mat4
	r.direction = Vec3::normalize(
		ip_coords.x * x_axis
		+ ip_coords.y * y_axis
		+ this->dir * 1);

	r.origin = location;
	r.max_depth = MAX_DEPTH;
}

bool Camera::any_hit(const Ray &r, Hit &h) const
{
	return scene.any_hit(r, h);
}

bool Camera::nearest_hit(const Ray &r, Hit &h) const
{
	return scene.nearest_hit(r, h);
}
