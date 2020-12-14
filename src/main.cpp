// Includes gl - do this first
#include "window.h"
#include <thread>
#include "pathological.h"
#include "exporter.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

int main(int argc, char **argv)
{
	Window win(WIDTH, HEIGHT, "Pathological path tracer");
	int width = WIDTH;
	int height = HEIGHT;

	Pathological app(width, height);
	void *pixels = app.get_texture();
	NetPBM exp("traced.ppm", width, height, (Color *)pixels);

	app.add_exporter(&exp);
	std::thread app_thread(&Pathological::run, &app);

	while (!win.should_quit())
	{
		win.display_texture(width, height, (char *)pixels);

		// Update display at 15 FPS
		std::this_thread::sleep_for(
			std::chrono::duration<float, std::ratio<1, 1>>(1.0/15.0));
	}

	app.stop();
	app_thread.join();
}
