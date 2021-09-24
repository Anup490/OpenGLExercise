#include "Headers.h"

namespace Exercise2
{
	int easy_problem_1()
	{
		float equilateral_triangle_vertices[] =
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f, sqrt(0.15f), 0.0f
		};

		float right_angled_triangle_vertices[] =
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			-0.5f, sqrt(0.15f), 0.0f
		};

		const char* vertex_shader_source =	
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos, 1.0f);\n"
		"}\n";

		const char* fragment_shader_source =
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 0.75f, 0.8f, 1.0f);\n"
		"}\0";

		int has_shader_compiled;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		const char* window_title = "OpenGLExercise2EasyProblem 1";
		GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Error loading window for Exercise2::easy_problem_1" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0, 0, window_width, window_height);

		unsigned VAO;
		unsigned VBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(right_angled_triangle_vertices), right_angled_triangle_vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		unsigned vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
		glCompileShader(vertex_shader);
		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &has_shader_compiled);
		if (!has_shader_compiled)
		{
			std::cout << "Error compiling vertex shader" << std::endl;
		}

		unsigned fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
		glCompileShader(fragment_shader);
		glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &has_shader_compiled);
		if (!has_shader_compiled)
		{
			std::cout << "Error compiling fragment shader" << std::endl;
		}

		unsigned shader_program = glCreateProgram();
		glAttachShader(shader_program, vertex_shader);
		glAttachShader(shader_program, fragment_shader);
		glLinkProgram(shader_program);
		glGetShaderiv(shader_program, GL_COMPILE_STATUS, &has_shader_compiled);
		if (!has_shader_compiled)
		{
			std::cout << "Error linking shaders in shader program" << std::endl;
		}
		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

		while (!glfwWindowShouldClose(window))
		{
			glClearColor(0.5f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glUseProgram(shader_program);
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteProgram(shader_program);
		glfwDestroyWindow(window);
		glfwTerminate();
		return 0;
	}

	int easy_problem_2()
	{
		float triangle[] =
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f, sqrt(0.15f), 0.0f
		};

		const char* vertex_shader_source =
			"#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"	gl_Position = vec4(aPos, 1.0f);"
			"}\n";

		const char* fragment_shader_source =
			"#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"	FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
			"}\n";

		constexpr int point_size = 10;

		int has_shader_compiled;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		const char* window_title = "OpenGLExercise2EasyProblem 2";
		GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Error loading window for Exercise2::easy_problem_2" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0, 0, window_width, window_height);

		GLuint VAO, VBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STREAM_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		unsigned vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
		glCompileShader(vertex_shader);
		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &has_shader_compiled);
		if (!has_shader_compiled)
		{
			std::cout << "error compiling vertex shader" << std::endl;
		}

		unsigned fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
		glCompileShader(fragment_shader);
		glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &has_shader_compiled);
		if (!has_shader_compiled)
		{
			std::cout << "error compiling fragment shader" << std::endl;
		}

		unsigned shader_program = glCreateProgram();
		glAttachShader(shader_program, vertex_shader);
		glAttachShader(shader_program, fragment_shader);
		glLinkProgram(shader_program);
		glGetShaderiv(shader_program, GL_COMPILE_STATUS, &has_shader_compiled);
		if (!has_shader_compiled)
		{
			std::cout << "error linking shaders" << std::endl;
		}

		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);
		glPointSize(point_size);

		while (!glfwWindowShouldClose(window))
		{
			glClearColor(0.1f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glUseProgram(shader_program);
			glBindVertexArray(VAO);
			glDrawArrays(GL_POINTS, 0, 3);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwDestroyWindow(window);
		glfwTerminate();
		return 0;
	}
}