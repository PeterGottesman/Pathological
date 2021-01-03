#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>

class Window {
private:
	std::string window_title;
	GLuint tex_id, prog_id;
	int width, height;
	GLFWwindow *win;

	int create_window(void);

	int load_gl(void);

	static void keyhandler(GLFWwindow *win, int key, int scancode,
					int action, int mods);

public:

	Window(int w, int h, std::string title);
	void display_texture(int width, int height, char *pixels);

	bool should_quit() {return glfwWindowShouldClose(win); }
	int get_width() { return width; }
	int get_height() { return height; }
};
