// Includes gl - do this first
#include "window.h"

#include <thread>
#include <GLFW/glfw3.h>

#include "pathological.h"

const int WIDTH = 400;
const int HEIGHT = 400;

int main(int argc, char **argv)
{
	Window win(WIDTH, HEIGHT, "Nifty stuff");
	int width = win.get_width();
	int height = win.get_height();
	width = height = 500;

	Pathological app;
	void *pixels = app.get_texture();
	std::thread app_thread(&Pathological::run, &app);

	while (!win.should_quit())
	{
		win.display_texture(width, height, (char *)pixels);
	}

	app.stop();
	app_thread.join();
}
