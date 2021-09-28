#include "Wrappers.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

namespace Exercise6
{
	int easy_problem_1()
	{
		GLfloat square_vertices[] =
		{
			//   COORDINATES       TEXCOORDS
			-1.0f, -1.0f, 0.0f,   0.0f, 0.0f,
			 1.0f, -1.0f, 0.0f,   2.0f, 0.0f,
			-1.0f,  1.0f, 0.0f,   0.0f, 1.0f,
			 1.0f,  1.0f, 0.0f,   2.0f, 1.0f
		};

		GLuint square_indices[] =
		{
			0, 1, 2,
			2, 3, 1
		};
		const char* window_title = "OpenGLExercise5EasyProblem 1";
		Window window(window_title);
		VertexBufferObject VBO(square_vertices, sizeof(square_vertices));
		ShaderProgram shader("exercise6easyproblem1.vert", "exercise6easyproblem1.frag");
		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		VAO.link_VBO_data(VBO, 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		ElementBufferObject EBO(square_indices, sizeof(square_indices));

		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, color_channels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load("happy.png", &width, &height, &color_channels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			stbi_image_free(data);
		}
		
		while (window.should_stay())
		{
			glClearColor(0.96f, 0.87f, 0.58f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindTexture(GL_TEXTURE_2D, texture);
			VAO.bind(EBO);
			shader.activate();
			window.run_swapbuffer_eventpoller();
		}
		return 0;
	}
}