// Includes gl - do this first
#include "window.h"

#include <thread>
#include <GLFW/glfw3.h>

#include "pathological.h"

const int WIDTH = 400;
const int HEIGHT = 400;

int main(int argc, char **argv)
{
	Window win(WIDTH, HEIGHT, "Pathological path tracer");
	int width = win.get_width();
	int height = win.get_height();

	Pathological app(width, height);
	void *pixels = app.get_texture();
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
