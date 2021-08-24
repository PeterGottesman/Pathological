#include "renderthread.h"
#include <chrono>

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

	unsigned spp = cam->get_spp();

	// Generate sub-pixel offsets for each sample
	std::vector<Vec3> offsets;
	for (unsigned i = 0; i < spp; ++i)
	{
		offsets.push_back({rand.uniform_range(0, 1.0),
						rand.uniform_range(0, 1.0),
						0.0});
	}

	for (unsigned y = row_start; y < row_end; ++y)
	{
		for (unsigned x = col_start; x < col_end; ++x)
		{
			int idx = y*region.im_width + x;
			Color col(0.0);
			for (unsigned s = 0; s < spp; ++s)
			{
				if (!running) return;

				col += calc_pixel(x, y, offsets[s]);
			}

			image[idx] += ((col/spp) - image[idx])/(iters[idx]+1);
			iters[idx]++;
		}
	}
}

Color RenderThread::calc_pixel(unsigned x, unsigned y, const Vec3 &offset)
{
	cam->get_pixel_ray(r, x, y, offset);
	return cam->cast_ray(r, rand);
}
