#include "Wrappers.h"
#include "stb/stb_image.h"

namespace Exercise6
{
	int hard_problem()
	{
		GLfloat triangle_vertices[] =
		{
		   -0.5f, -0.5f, 0.0f,  -1.0f,-1.0f,
			0.0f,  0.5f, 0.0f,   0.5f, 2.0f,
			0.5f, -0.5f, 0.0f,   2.0f,-1.0f,
		};

		const char* window_title = "OpenGLExercise6HardProblem";
		Window window(window_title);
		VertexBufferObject VBO(triangle_vertices, sizeof(triangle_vertices));
		ShaderProgram shader("exercise6hardproblem1.vert", "exercise6hardproblem1.frag");
		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		VAO.link_VBO_data(VBO, 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		
		int width, height, color_channels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load("happy.png", &width, &height, &color_channels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			stbi_image_free(data);
		}

		while (window.should_stay())
		{
			glClearColor(0.96f, 0.87f, 0.58f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			VAO.bind();
			shader.activate();
			glDrawArrays(GL_TRIANGLES, 0, 6);
			window.run_swapbuffer_eventpoller();
		}
		return 0;
	}
}