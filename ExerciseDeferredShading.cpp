#include "Headers.h"
#include <string.h>
#include <fstream>
#include <sstream>
#include "Base.h"

model* prepare_gltf_model_data(const char* file_path);

namespace ExerciseDeferredShading
{
	std::string read_shader_file(const char* path);

	int problem()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		const char* title = "OpenGLDeferredShading";
		GLFWwindow* window = glfwCreateWindow(window_width, window_height, title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "ERROR :: Failed to create window" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();

		model* pmodel = prepare_gltf_model_data("D:/Projects/C++/3DImporter/Assets/statue/scene.gltf");

		GLuint VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, pmodel->pvertices->size() * sizeof(vertex), pmodel->pvertices->data(), GL_STATIC_DRAW);

		GLuint VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		GLuint EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, pmodel->pindices->size() * sizeof(GLuint), pmodel->pindices->data(), GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		glBindVertexArray(0);

		GLint has_compiled;
		GLuint shader = glCreateProgram();

		std::string vertex_shader_file = read_shader_file("exercisedeferredlighting.vert");
		GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		const char* vertex_shader_source = vertex_shader_file.c_str();
		glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
		glCompileShader(vertex_shader);
		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &has_compiled);
		if (!has_compiled)
			std::cout << "Error compiling vertex shader" << std::endl;
		glAttachShader(shader, vertex_shader);

		std::string fragment_shader_file = read_shader_file("exercisedeferredlighting.frag");
		GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		const char* fragment_shader_source = fragment_shader_file.c_str();
		glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
		glCompileShader(fragment_shader);
		glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &has_compiled);
		if (!has_compiled)
			std::cout << "Error compiling fragment shader" << std::endl;
		glAttachShader(shader, fragment_shader);

		glLinkProgram(shader);
		glCompileShader(shader);
		glGetShaderiv(shader, GL_COMPILE_STATUS, &has_compiled);
		if (!has_compiled)
			std::cout << "Error linking shaders" << std::endl;

		//Framebuffer begin
		GLfloat quad_vertices[] = {
			-1.0f,  -1.0f, 0.0f, 0.0f, 0.0f,
			-1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
			 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
			-1.0f,  -1.0f, 0.0f, 0.0f, 0.0f,
			 1.0f,  -1.0f, 0.0f, 1.0f, 0.0f,
			 1.0f,  1.0f, 0.0f, 1.0f, 1.0f
		};

		GLuint framebufferVBO;
		glGenBuffers(1, &framebufferVBO);
		glBindBuffer(GL_ARRAY_BUFFER, framebufferVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quad_vertices), quad_vertices, GL_STATIC_DRAW);
		
		GLuint framebufferVAO;
		glGenVertexArrays(1, &framebufferVAO);
		glBindVertexArray(framebufferVAO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		GLuint framebufferShader = glCreateProgram();

		std::string fb_vertex_shader_file = read_shader_file("fbdeferredlighting.vert");
		GLuint fb_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		const char* fb_vertex_shader_source = fb_vertex_shader_file.c_str();
		glShaderSource(fb_vertex_shader, 1, &fb_vertex_shader_source, NULL);
		glCompileShader(fb_vertex_shader);
		glGetShaderiv(fb_vertex_shader, GL_COMPILE_STATUS, &has_compiled);
		if (!has_compiled)
			std::cout << "Error compiling framebuffer vertex shader" << std::endl;
		glAttachShader(framebufferShader, fb_vertex_shader);

		std::string fb_fragment_shader_file = read_shader_file("fbdeferredlighting.frag");
		GLuint fb_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		const char* fb_fragment_shader_source = fb_fragment_shader_file.c_str();
		glShaderSource(fb_fragment_shader, 1, &fb_fragment_shader_source, NULL);
		glCompileShader(fb_fragment_shader);
		glGetShaderiv(fb_fragment_shader, GL_COMPILE_STATUS, &has_compiled);
		if (!has_compiled)
			std::cout << "Error compiling framebuffer fragment shader" << std::endl;
		glAttachShader(framebufferShader, fb_fragment_shader);

		glLinkProgram(framebufferShader);
		glGetShaderiv(framebufferShader, GL_LINK_STATUS, &has_compiled);
		if (!has_compiled)
			std::cout << "Error linking framebuffer fragment shader" << std::endl;

		int framebufferWidth = window_width;
		int framebufferHeight = window_height;

		GLuint frameBuffer;
		glGenFramebuffers(1, &frameBuffer);
		glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);

		/*GLuint depthBuffer;
		glGenRenderbuffers(1, &depthBuffer);
		glBindRenderbuffer(GL_RENDERBUFFER, depthBuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT32F, framebufferWidth, framebufferHeight);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthBuffer);*/	

		GLuint positionTexture;
		glGenTextures(1, &positionTexture);
		glBindTexture(GL_TEXTURE_2D, positionTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, framebufferWidth, framebufferHeight, 0, GL_RGB, GL_FLOAT, NULL);
		glBindTexture(GL_TEXTURE_2D, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, positionTexture, 0);

		GLuint normalTexture;
		glGenTextures(1, &normalTexture);
		glBindTexture(GL_TEXTURE_2D, normalTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, framebufferWidth, framebufferHeight, 0, GL_RGB, GL_FLOAT, NULL);
		glBindTexture(GL_TEXTURE_2D, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, normalTexture, 0);
		
		GLuint texTexture;
		glGenTextures(1, &texTexture);
		glBindTexture(GL_TEXTURE_2D, texTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, framebufferWidth, framebufferHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
		glBindTexture(GL_TEXTURE_2D, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_2D, texTexture, 0);

		GLuint depthTexture;
		glGenTextures(1, &depthTexture);
		glBindTexture(GL_TEXTURE_2D, depthTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, framebufferWidth, framebufferHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
		glBindTexture(GL_TEXTURE_2D, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthTexture, 0);

		unsigned attachments[4] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2 };
		glDrawBuffers(4, attachments);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		//Framebuffer end

		while (!glfwWindowShouldClose(window))
		{
			glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);

			glViewport(0, 0, framebufferWidth, framebufferHeight);
			glClearColor(1.0f, 0.65f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_DEPTH_TEST);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBindVertexArray(VAO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glUseProgram(shader);
			glDrawElements(GL_TRIANGLES, pmodel->pindices->size(), GL_UNSIGNED_INT, 0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
			glUseProgram(0);

			glBindFramebuffer(GL_FRAMEBUFFER, 0);		
			glDisable(GL_DEPTH_TEST);

			glViewport(0, 0, window_width, window_height);
			glClearColor(0.0f, 1.0f, 0.65f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glBindBuffer(GL_ARRAY_BUFFER, framebufferVBO);
			glBindVertexArray(framebufferVAO);
			glUseProgram(framebufferShader);

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, positionTexture);
			glUniform1i(glGetUniformLocation(framebufferShader, "positionTexture"), 0);

			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, normalTexture);
			glUniform1i(glGetUniformLocation(framebufferShader, "normalTexture"), 1);

			glActiveTexture(GL_TEXTURE2);
			glBindTexture(GL_TEXTURE_2D, texTexture);
			glUniform1i(glGetUniformLocation(framebufferShader, "texCoordTexture"), 2);

			glActiveTexture(GL_TEXTURE3);
			glBindTexture(GL_TEXTURE_2D, depthTexture);
			glUniform1i(glGetUniformLocation(framebufferShader, "depthTexture"), 3);
			
			glDrawArrays(GL_TRIANGLES, 0, 6);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}


		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		glUseProgram(0);

		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &framebufferVBO);
		glDeleteVertexArrays(1, &VAO);
		glDeleteVertexArrays(1, &framebufferVAO);

		glfwDestroyWindow(window);
		glfwTerminate();
		return -1;
	}


	std::string read_shader_file(const char* path)
	{
		std::string shader_source = "";
		std::ifstream file_input_stream;
		std::stringstream string_stream;
		try
		{
			file_input_stream.open(path);
			string_stream << file_input_stream.rdbuf();
			file_input_stream.close();
			shader_source = string_stream.str();
		}
		catch (const std::ifstream::failure& f)
		{
			std::cout << "Failure reading :: " << path << std::endl;
			std::cout << "Error :: " << f.what() << std::endl;
		}
		return shader_source;
	}
}