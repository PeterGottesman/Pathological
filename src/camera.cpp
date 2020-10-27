#include <cstdio>

#include "camera.h"
#include "vec3.h"
#include "ray.h"

Color Camera::calc_pix(int x, int y) const
{
	Vec3 ray_dir;
	Vec3 ip_coords;
	Vec3 col;
	Hit hit;

	ip_coords = Vec3((float)x/width, (float)y/height, 0);
	ip_coords = ip_coords + Vec3(-0.5, -0.5, 0);

	// TODO: Mat4, Vec3*Mat4
	ray_dir = ip_coords.x * x_axis
		+ ip_coords.y * y_axis
		+ this->dir * 1;

	ray_dir = Vec3::normalize(ray_dir);
	Ray ray = Ray(this->location, ray_dir);

	// TODO: real multisampling
	const int iters = 30;
	for (int i = 0; i < iters; ++i)
	{
		if (nearest_hit(ray, hit))
		{
			col = col + hit.mat->sample(this->scene, hit.pos, hit.norm, ray.max_depth)/(float)iters;
		}
		else
		{
			col = col + Color{0.1, 0.3, 0.2}/(float)iters;
		}
	}

	return col;
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
			image[idx] = ((iter-1) * image[idx])/iter + calc_pix(x, y)/iter;
		}
	}
	iter++;
	return image;
}

bool Camera::any_hit(const Ray &r, Hit &h) const
{
	return scene.any_hit(r, h);
}

bool Camera::nearest_hit(const Ray &r, Hit &h) const
{
	return scene.nearest_hit(r, h);
}