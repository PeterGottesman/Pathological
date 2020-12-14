#pragma once

#include <thread>
#include <atomic>

#include "randgen.h"
#include "vec3.h"
#include "camera.h"
#include "ray.h"

struct RenderRegion
{
	unsigned im_width, im_height;
	unsigned region_width, region_height;
	unsigned region_row_offset, region_col_offset;

	RenderRegion(unsigned im_w, unsigned im_h, unsigned reg_w, unsigned reg_h,
				 unsigned reg_roff, unsigned reg_coff)
		: im_width(im_w), im_height(im_h), region_width(reg_w),
		  region_height(reg_h), region_row_offset(reg_roff),
		  region_col_offset(reg_coff) {}
};

class RenderThread
{
private:
	Camera *cam;

	// Each thread has one ray object, no need to keep constructing
	// and destroying them.
	Ray r;

	Color *image;
	unsigned *iters;

	RenderRegion region;
	RandGen rand;

	std::thread thread;
	std::atomic<bool> running;

	Color calc_pixel(unsigned x, unsigned y, const Vec3 &offset);
	void render_region(void);
	void run(void);

public:
	RenderThread(const RenderThread &rt)
		: cam(rt.cam), region(rt.region), rand(rt.rand)
		{
			image = cam->get_image_buf();
			iters = cam->get_iters_buf();
		}

	RenderThread(Camera *cam, RenderRegion region, RandGen rng)
		: cam(cam), region(region), rand(rng)
		{
			image = cam->get_image_buf();
			iters = cam->get_iters_buf();
		}

	~RenderThread()
	{
		if (thread.joinable())
		{
			running = false;
			thread.join();
		}
	}

	void launch(void)
	{
		running = true;
		thread = std::thread(&RenderThread::run, this);
	}
};
