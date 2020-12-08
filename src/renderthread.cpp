#include "renderthread.h"

void RenderThread::run(void)
{
	while (running)
	{
		render_region();
	}
}

void RenderThread::render_region(void)
{
	unsigned row_start = region.region_row_offset;
	unsigned row_end = row_start + region.region_height;

	unsigned col_start = region.region_col_offset;
	unsigned col_end = col_start + region.region_width;

	for (unsigned y = row_start; y < row_end; ++y)
	{
		for (unsigned x = col_start; x < col_end; ++x)
		{
			int idx = y*region.im_width + x;
			image[idx] += (calc_pixel(x, y) - image[idx])/(iters[idx]+1);
			iters[idx]++;

			if (!running)
				return;
		}
	}
}

Color RenderThread::calc_pixel(unsigned x, unsigned y)
{
	const int iters = 300;

	cam->get_pixel_ray(r, x, y);
	return cam->cast_ray(r, iters);
}
