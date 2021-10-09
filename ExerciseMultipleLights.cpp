#include "Wrappers.h"

#define DESERT
//#define FACTORY
//#define HORROR
//#define BIOCHEMICAL

#ifdef  DESERT
#define COLOR 0.96f, 0.87f, 0.58f, 1.0f
#define LIGHT_1 1.0f, 0.0f, 0.0f
#define LIGHT_2 1.0f, 0.67f, 0.0f
#define LIGHT_3 0.65f, 0.16f, 0.16f
#define LIGHT_4 1.0f, 1.0f, 0.0f
#define DIFFUSE_DIR 0.8f
#define AMBIENT_DIR DIFFUSE_DIR
#define DIFFUSE_POINT 0.8f
#define AMBIENT_POINT DIFFUSE_POINT
#define DIFFUSE_SPOT 0.8f
#define AMBIENT_SPOT DIFFUSE_SPOT
#define LIGHT_INTENSITY 1.0f
#endif

#ifdef  FACTORY
#define COLOR 0.0f, 0.0f, 0.1f, 1.0f
#define LIGHT_1 0.56f, 0.0f, 1.0f
#define LIGHT_2 1.0f, 0.67f, 0.0f
#define LIGHT_3 0.65f, 0.16f, 0.16f
#define LIGHT_4 1.0f, 1.0f, 0.0f
#define DIFFUSE_DIR 0.1f
#define AMBIENT_DIR DIFFUSE_DIR
#define DIFFUSE_POINT 0.1f
#define AMBIENT_POINT DIFFUSE_POINT
#define DIFFUSE_SPOT 0.8f
#define AMBIENT_SPOT DIFFUSE_SPOT
#define LIGHT_INTENSITY 1.0f
#endif

#ifdef  HORROR
#define COLOR 0.0f, 0.0f, 0.0f, 1.0f
#define LIGHT_1 0.56f, 0.0f, 1.0f
#define LIGHT_2 1.0f, 0.67f, 0.0f
#define LIGHT_3 0.65f, 0.16f, 0.16f
#define LIGHT_4 1.0f, 1.0f, 0.0f
#define DIFFUSE_DIR 0.1f
#define AMBIENT_DIR DIFFUSE_DIR
#define DIFFUSE_POINT 0.1f
#define AMBIENT_POINT DIFFUSE_POINT
#define DIFFUSE_SPOT 0.1f
#define AMBIENT_SPOT DIFFUSE_SPOT
#define LIGHT_INTENSITY 0.5f
#endif

#ifdef  BIOCHEMICAL
#define COLOR 1.0f, 1.0f, 1.0f, 1.0f
#define LIGHT_1 0.0f, 1.0f, 0.0f
#define LIGHT_2 0.0f, 1.0f, 0.0f
#define LIGHT_3 0.0f, 1.0f, 0.0f
#define LIGHT_4 0.0f, 1.0f, 0.0f
#define DIFFUSE_DIR 0.8f
#define AMBIENT_DIR DIFFUSE_DIR
#define DIFFUSE_POINT 0.8f
#define AMBIENT_POINT DIFFUSE_POINT
#define DIFFUSE_SPOT 0.8f
#define AMBIENT_SPOT DIFFUSE_SPOT
#define LIGHT_INTENSITY 1.0f
#endif


namespace ExerciseMultipleLights
{
	static glm::vec3 get_light_color(int index);

	int problem1()
	{
		GLfloat square_vertices[] = {
			// positions          // normals           // texture coords
			  -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
			   0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
			   0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
			   0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
			  -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
			  -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

			  -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
			   0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
			   0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
			   0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
			  -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
			  -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

			  -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
			  -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
			  -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
			  -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
			  -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
			  -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

			   0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
			   0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
			   0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
			   0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
			   0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
			   0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

			  -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
			   0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
			   0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
			   0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
			  -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
			  -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

			  -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
			   0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
			   0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
			   0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
			  -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
			  -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
		};

		GLfloat light_vertices[] =
		{
			//VERTICES            
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,

		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f
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

		const int pointLightPositionsSize = 4;
		glm::vec3 pointLightPositions[] = {
			glm::vec3(0.7f,  0.2f,  2.0f),
			glm::vec3(2.3f, -3.3f, -1.0f),
			glm::vec3(-4.0f,  2.0f, -12.0f),
			glm::vec3(0.0f,  0.0f, -3.0f)
		};

		const char* window_title = "OpenGLMultipleLights";
		Window window(window_title);

		VertexBufferObject VBO(square_vertices, sizeof(square_vertices));
		ShaderProgram shader("exercisemultiplelights.vert", "exercisemultiplelights.frag");

		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
		VAO.link_VBO_data(VBO, 1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		VAO.link_VBO_data(VBO, 2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));

		VertexBufferObject light_VBO(light_vertices, sizeof(light_vertices));
		ShaderProgram light_shader("multiplelightslight.vert", "multiplelightslight.frag");
		VertexArrayObject light_VAO;
		light_VAO.link_VBO_data(light_VBO, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

		glm::vec3 camera_pos = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 camera_target = glm::vec3(0.0f);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

		Texture texturediff("containerdiff.png", GL_TEXTURE0, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_NEAREST, GL_RGBA);
		Texture texturespec("containerspec.png", GL_TEXTURE1, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_NEAREST, GL_RGBA);

		Camera camera(window, camera_pos, camera_target, up);
		camera.set_view_matrix(shader);
		camera.set_projection_matrix(shader);
		camera.set_view_matrix(light_shader);
		camera.set_projection_matrix(light_shader);

		shader.set_int_uniform("material.diffuse", 0);
		shader.set_int_uniform("material.specular", 1);
		shader.set_float_uniform("material.shininess", 32.0f);

		glm::vec3 direct_light_position(0.2f, 1.0f, 0.3f);
		glm::vec3 spot_light_position = camera.get_position();//(-0.2f, 1.0f, 0.3f);
		glm::vec3 spot_light_front = -camera.get_front();//spot_light_position - cubePositions[0];
		glm::vec3 light_color(1.0f);

		glm::vec3 diffuse_color_dir = light_color * glm::vec3(DIFFUSE_DIR);
		glm::vec3 ambient_color_dir = diffuse_color_dir * glm::vec3(AMBIENT_DIR);

		glm::vec3 diffuse_color_point = light_color * glm::vec3(DIFFUSE_POINT);
		glm::vec3 ambient_color_point = diffuse_color_point * glm::vec3(AMBIENT_POINT);

		glm::vec3 diffuse_color_spot = light_color * glm::vec3(DIFFUSE_SPOT);
		glm::vec3 ambient_color_spot = diffuse_color_spot * glm::vec3(AMBIENT_SPOT);

		shader.set_vec3_uniform("dirLight.ambient", ambient_color_dir);
		shader.set_vec3_uniform("dirLight.diffuse", diffuse_color_dir);
		shader.set_vec3_uniform("dirLight.specular", glm::vec3(1.0f));
		shader.set_vec3_uniform("dirLight.position", direct_light_position);

		
		for (int i=0; i<pointLightPositionsSize; i++)
		{
			std::string uniform_name = "pointLights[";
			uniform_name.append(std::to_string(i));
			uniform_name.append("]");
			shader.set_vec3_uniform(std::string(uniform_name +".ambient").c_str(), ambient_color_point);
			shader.set_vec3_uniform(std::string(uniform_name + ".diffuse").c_str(), diffuse_color_point);
			shader.set_vec3_uniform(std::string(uniform_name + ".specular").c_str(), glm::vec3(1.0f));
			shader.set_vec3_uniform(std::string(uniform_name + ".position").c_str(), pointLightPositions[i]);
			shader.set_vec3_uniform(std::string(uniform_name + ".color").c_str(), get_light_color(i));
			shader.set_float_uniform(std::string(uniform_name + ".constant").c_str(), 1.0f);
			shader.set_float_uniform(std::string(uniform_name + ".linear").c_str(), 0.09f);
			shader.set_float_uniform(std::string(uniform_name + ".quadratic").c_str(), 0.032f);
		}

		shader.set_vec3_uniform("spotLight.ambient", ambient_color_spot);
		shader.set_vec3_uniform("spotLight.diffuse", diffuse_color_spot);
		shader.set_vec3_uniform("spotLight.specular", glm::vec3(1.0f));
		shader.set_vec3_uniform("spotLight.position", spot_light_position);
		shader.set_vec3_uniform("spotLight.front", spot_light_front);
		shader.set_float_uniform("spotLight.cutoff", glm::cos(glm::radians(12.5f)));
		shader.set_float_uniform("spotLight.outercutoff", glm::cos(glm::radians(17.5f)));

		light_shader.set_vec3_uniform("light_color", light_color);
		light_shader.set_float_uniform("light_intensity", LIGHT_INTENSITY);

		glEnable(GL_DEPTH_TEST);

		float prev_time = window.get_current_time();
		float crnt_time;

		while (window.should_stay())
		{
			glClearColor(COLOR);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			VAO.bind();
			shader.activate();
			camera.update_vectors();
			camera.update_matrices(shader);
			shader.set_vec3_uniform("viewPos", camera.get_position());
			glDrawArrays(GL_TRIANGLES, 0, 36);
			for (unsigned int i = 0; i < 10; i++)
			{
				camera.set_model_matrix(shader, cubePositions[i], glm::vec3(0.5f, 1.0f, 1.0f), 20.0f * i);
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
			VAO.unbind();

			light_VAO.bind();
			light_shader.activate();
			camera.update_matrices(light_shader);

			for (int i = 0; i < pointLightPositionsSize; i++)
			{
				light_shader.set_vec3_uniform("light_color", get_light_color(i));
				camera.set_model_matrix(light_shader, pointLightPositions[i], glm::vec3(0.5f, 1.0f, 1.0f), 0.0f, glm::vec3(0.5f));
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
		
			light_VAO.unbind();

			window.run_swapbuffer_eventpoller();
		}
		return 0;
	}

	static glm::vec3 get_light_color(int index)
	{
		if (index == 0) {
			return glm::vec3(LIGHT_1);
		}
		else if (index == 1)
		{
			return glm::vec3(LIGHT_2);
		}
		else if (index == 2)
		{
			return glm::vec3(LIGHT_3);
		}
		else
		{
			return glm::vec3(LIGHT_4);
		}
	}
}