// Includes gl - do this first
#include "window.h"
#include "pathological.h"

#include <GLFW/glfw3.h>

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

	while (!win.should_quit())
	{
		app.render();
		win.display_texture(width, height, (char *)pixels);
	}
}
