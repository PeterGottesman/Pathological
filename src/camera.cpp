#include <cstdio>

#include "camera.h"
#include "vec3.h"
#include "ray.h"
#include "scene.h"

Color Camera::calc_pix(int x, int y) const
{
	Ray ray;
	Color col;
	Hit hit;

	get_pixel_ray(ray, x, y);

	// TODO: real multisampling
	const int iters = 30;
	for (int i = 0; i < iters; ++i)
	{
		if (nearest_hit(ray, hit))
		{
			col += hit.mat->sample(this->scene, hit.pos,
								   hit.norm, ray.max_depth);
		}
		else
		{
			col += Color{0.1, 0.3, 0.2};
		}
	}

	return col/(float)iters;
}

Color *Camera::render_image()
{
	static int iter = 1;
    #pragma omp parallel for collapse(2)
	for (unsigned y = 0; y < height; ++y)
	{
		for (unsigned x = 0; x < width; ++x)
		{
			int idx = y*width + x;
			image[idx] = ((iter-1) * image[idx]
						  + calc_pix(x, y))/(float)iter;
		}
	}
	iter++;
	return image;
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
