#include "Wrappers.h"

namespace ExerciseFrameBuffers
{
	int problem1()
	{
		GLfloat square_vertices[] =
		{
			//VERTICES            TEXCOORDS
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};

		glm::vec3 cubePositions[] = {
			glm::vec3(0.0f,  0.0f,  0.0f),
			glm::vec3(2.0f,  5.0f, -15.0f),
			glm::vec3(-1.5f, -2.2f, -2.5f),
			glm::vec3(-3.8f, -2.0f, -12.3f),
			glm::vec3(2.4f, -0.4f, -3.5f),
			glm::vec3(-1.7f,  3.0f, -7.5f),
			glm::vec3(1.3f, -2.0f, -2.5f),
			glm::vec3(1.5f,  2.0f, -2.5f),
			glm::vec3(1.5f,  0.2f, -1.5f),
			glm::vec3(-1.3f,  1.0f, -1.5f)
		};

		GLfloat framebuffervertices[] = {
			-0.5f,  0.74f, 0.0f, 0.0f, 0.0f,
			-0.5f,  1.0f, 0.0f, 0.0f, 1.0f,
			 0.5f,  1.0f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.74f, 0.0f, 0.0f, 0.0f,
			 0.5f,  0.74f, 0.0f, 1.0f, 0.0f,
			 0.5f,  1.0f, 0.0f, 1.0f, 1.0f
		};

		const char* window_title = "OpenGLExerciseFramebuffers 1";
		Window window(window_title);
		VertexBufferObject VBO(square_vertices, sizeof(square_vertices));
		ShaderProgram shader("exerciseframebuffers.vert", "exerciseframebuffers.frag");
		shader.set_int_uniform("tex0", 0);
		shader.set_int_uniform("tex1", 1);
		shader.deactivate();

		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		VAO.link_VBO_data(VBO, 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

		VertexBufferObject framebufferVBO(framebuffervertices, sizeof(framebuffervertices));
		VertexArrayObject framebufferVAO;
		framebufferVAO.link_VBO_data(framebufferVBO, 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		framebufferVAO.link_VBO_data(framebufferVBO, 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

		
		glm::vec3 camera_pos = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 camera_target = glm::vec3(0.0f);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

		glm::vec3 reverse_camera_pos = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 reverse_camera_target = glm::vec3(0.0f, 0.0f, 6.0f);
		glm::vec3 reverse_up = glm::vec3(0.0f, 1.0f, 0.0f);

		NormalCamera camera(window, camera_pos, camera_target, up);
		camera.set_view_matrix(shader);
		camera.set_projection_matrix(shader);

		ReverseCamera reverse_camera(window, reverse_camera_pos, reverse_camera_target, reverse_up);
		reverse_camera.set_view_matrix(shader);
		reverse_camera.set_projection_matrix(shader);

		CameraHandler camera_handler(window);
		camera_handler.add_camera(&camera);
		camera_handler.add_camera(&reverse_camera);

		Texture tex1("container.png", GL_TEXTURE0, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR, GL_RGB);
		tex1.deactivate();

		Texture tex2("happy.png", GL_TEXTURE1, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR, GL_RGBA);
		tex2.deactivate();

		ShaderProgram framebuffershader("framebuffer.vert", "framebuffer.frag");
		framebuffershader.deactivate();

		GLuint framebuffer;
		glGenFramebuffers(1, &framebuffer);
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

		GLuint framebuffertexture;
		glGenTextures(1, &framebuffertexture);
		glBindTexture(GL_TEXTURE_2D, framebuffertexture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 100, 100, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		float borderColor[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
		glBindTexture(GL_TEXTURE_2D, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, framebuffertexture, 0);

		GLuint renderbuffer;
		glGenRenderbuffers(1, &renderbuffer);
		glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 100, 100);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderbuffer);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		{
			std::cout << "Error creating framebuffer" << std::endl;
			return -1;
		}

		const int framebuffer_width = 100;
		const int framebuffer_height = 100;

		while (window.should_stay())
		{
			glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
			glViewport(0, 0, framebuffer_width, framebuffer_height);
			glClearColor(0.96f, 0.87f, 0.58f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_DEPTH_TEST);
			VAO.bind();
			shader.activate();
			reverse_camera.update_vectors();
			reverse_camera.update_matrices(shader);
			tex2.activate();
			tex1.activate();
			for (unsigned int i = 0; i < 10; i++)
			{
				reverse_camera.set_model_matrix(shader, cubePositions[i], glm::vec3(1.0f, 1.0f, 1.0f), 20.f * i);
				glDrawArrays(GL_TRIANGLES, 0, 36);	
			}
			VAO.unbind();
			shader.deactivate();
			tex1.deactivate();
			tex2.deactivate();
			glBindFramebuffer(GL_FRAMEBUFFER, 0);

			glViewport(0, 0, window_width, window_height);
			glClearColor(0.96f, 0.87f, 0.58f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_DEPTH_TEST);
			VAO.bind();
			shader.activate();
			camera.update_vectors();
			camera.update_matrices(shader);
			tex2.activate();
			tex1.activate();
			for (unsigned int i = 0; i < 10; i++)
			{
				camera.set_model_matrix(shader, cubePositions[i], glm::vec3(1.0f, 1.0f, 1.0f), 20.f * i);
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
			VAO.unbind();
			shader.deactivate();
			tex1.deactivate();
			tex2.deactivate();

			glDisable(GL_DEPTH_TEST);
			framebuffershader.activate();
			framebuffershader.set_int_uniform("tex", 0);
			framebufferVAO.bind();
			glBindTexture(GL_TEXTURE_2D, framebuffertexture);
			glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			framebuffershader.deactivate();
			framebufferVAO.unbind();

			window.run_swapbuffer_eventpoller();
		}
		return 0;
	}
}