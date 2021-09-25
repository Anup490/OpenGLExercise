#include "Headers.h"

namespace Exercise2
{
	int hard_problem()
	{
		float square_vertices[] =
		{
			-0.5f, -0.5f,
			-0.5f, sqrt(0.15f),
			 0.5f, sqrt(0.15f),
			 0.5f, -0.5f
		};

		const char* window_title = "OpenGLExercise2HardProblem";

		const char* vertex_shader_source =
		"#version 330 core\n"
		"layout (location = 0) in vec2 aPos;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(aPos, 0.0f, 1.0f);\n"
		"}\n";

		const char* fragment_shader_source =
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(0.34f, 0.21f, 0.51f, 1.0f);\n"
		"}\n";

		int has_shader_compiled;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Error loading window for Exercise2::hard_problem" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0, 0, window_width, window_height);

		GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
		glCompileShader(vertex_shader);
		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &has_shader_compiled);
		if (!has_shader_compiled)
		{
			std::cout << "Error compiling vertex shader" << std::endl;
		}

		GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
		glCompileShader(fragment_shader);
		glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &has_shader_compiled);
		if (!has_shader_compiled)
		{
			std::cout << "Error compiling fragment shader" << std::endl;
		}

		GLuint shader_program = glCreateProgram();
		glAttachShader(shader_program, vertex_shader);
		glAttachShader(shader_program, fragment_shader);
		glLinkProgram(shader_program);
		glGetShaderiv(shader_program, GL_COMPILE_STATUS, &has_shader_compiled);
		if (!has_shader_compiled)
		{
			std::cout << "Error linking shaders" << std::endl;
		}
		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

		GLuint VAO, VBO;
		glGenBuffers(1, &VBO);
		glGenVertexArrays(1, &VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(square_vertices),  square_vertices, GL_STATIC_DRAW);
		glBindVertexArray(VAO);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		while (!glfwWindowShouldClose(window))
		{
			glClearColor(0.82f, 0.69f, 0.60f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glUseProgram(shader_program);
			glBindVertexArray(VAO);
			glDrawArrays(GL_LINE_LOOP, 0, 4);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwDestroyWindow(window);
		glfwTerminate();
		return 0;
	}
}