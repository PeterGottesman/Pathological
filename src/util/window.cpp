#include "util/window.h"

int Window::create_window(void)
{
	glfwInit();

	win = glfwCreateWindow(width, height, window_title.c_str(),
						   NULL, NULL);

	if (!win)
	{
		fprintf(stderr, "Failed to create window\n");
		return -1;
	}

	// Update width and height settings to account for the height
	// being different than requested
	glfwGetWindowSize(win, &width, &height);
	fprintf(stderr, "Window created with size (%d, %d)\n", width, height);

	/* Make opengl context the active context for this thread */
	glfwMakeContextCurrent(win);

	return 0;
}

int Window::load_gl(void)
{
	GLuint vert_id, elem_id;

	float verts[] = {
		-1.0f, 1.0f,
		-1.0f, -1.0f,
		1.0f, 1.0f,
		1.0f, -1.0f,
	};

	unsigned int tris[] = {
		0, 1, 2,
		2, 1, 3
	};

	glewInit();

	glViewport(0, 0, width, height);
	glfwSetKeyCallback(win, Window::keyhandler);

	glGenVertexArrays(1, &vert_id);
	glBindVertexArray(vert_id);

	glBindBuffer(GL_ARRAY_BUFFER, vert_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts,
				 GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &elem_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elem_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(tris),
				 tris, GL_STATIC_DRAW);

	glGenTextures(1, &tex_id);
	glBindTexture(GL_TEXTURE_2D, tex_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
					GL_LINEAR);

	std::ifstream in;
	int vs_id, fs_id;
	int vs_len, fs_len;
	char *vs, *fs;
	int success;
	char infoLog[512];

	vs_id = glCreateShader(GL_VERTEX_SHADER);
	fs_id = glCreateShader(GL_FRAGMENT_SHADER);


	in.open("vs.vert");
	in.seekg(0, in.end);
	vs_len = in.tellg();
	in.seekg(0, in.beg);
	vs = new char[vs_len];
	in.read(vs, vs_len);
	in.close();

	glShaderSource(vs_id, 1, &vs, &vs_len);

	in.open("fs.frag");
	in.seekg(0, in.end);
	fs_len = in.tellg();
	in.seekg(0, in.beg);
	fs = new char[fs_len];
	in.read(fs, fs_len);
	in.close();

	glShaderSource(fs_id, 1, &fs, &fs_len);

	glCompileShader(vs_id);
	glGetShaderiv(vs_id, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vs_id, 512, NULL, infoLog);
		printf("vs_err:\n %s\n", infoLog);
		return -1;
	}

	glCompileShader(fs_id);
	glGetShaderiv(fs_id, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fs_id, 512, NULL, infoLog);
		printf("fs_err:\n %s\n", infoLog);
		return -1;
	}

	// Clean up
	prog_id = glCreateProgram();
	glAttachShader(prog_id, vs_id);
	glAttachShader(prog_id, fs_id);
	glLinkProgram(prog_id);
	glUseProgram(prog_id);

	glDeleteShader(vs_id);
	glDeleteShader(fs_id);

	delete[] vs;
	delete[] fs;

	GLuint res_loc = glGetUniformLocation(prog_id, "uResolution");
	glUniform2f(res_loc, width, height);

	return 0;
}

void Window::keyhandler(GLFWwindow *win, int key, int scancode,
						int action, int mods)
{
	switch (key)
	{
		case GLFW_KEY_Q:
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(win, GLFW_TRUE);
			break;
		default:
			break;
	}
}

void Window::display_texture(int width, int height, char *pixels)
{
		glClearColor(1, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
					 width, height, 0, GL_RGB,
					 GL_FLOAT, pixels);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwPollEvents();
		glfwSwapBuffers(win);
}

Window::Window(int w, int h, std::string title)
	: window_title(title),  width(w), height(h)
{
	create_window();
	load_gl();
}
