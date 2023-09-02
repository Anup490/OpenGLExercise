#include "Wrappers.h"
#include "AnimationHeaders.h"

//#define BACKPACK
#define NATHAN

namespace ExerciseAnimation
{
	void printMat4(glm::mat4& m);
	void printVec3(glm::vec3& v);

	int problem1()
	{
		const char* window_title = "OpenGLExerciseAnimation";
		Window window(window_title);
#ifdef NATHAN
		glm::vec3 model_position(0.0f, -100.0f, -300.0f);
#endif
#ifdef BACKPACK
		glm::vec3 model_position(0.0f, 0.0f, -2.0f);
#endif
		glm::vec3 camera_pos(0.0f, 0.0f, 10.0f);
		glm::vec3 camera_front = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 camera_right = glm::vec3(1.0f, 0.0f, 0.0f);
		glm::vec3 camera_up = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::mat4 view_matrix = glm::lookAt(camera_pos, camera_pos + camera_front, camera_up);

		float fov = 45.0f;
		float aspect_ratio = 1.0f;

		glm::mat4 projection_matrix = glm::mat4(1.0f);
		projection_matrix = glm::perspective(glm::radians(fov), aspect_ratio, 0.1f, 1000.0f);

		glm::mat4 model_matrix = glm::mat4(1.0f);
		model_matrix = glm::translate(model_matrix, model_position);
#ifdef BACKPACK
		model_matrix = glm::scale(model_matrix, glm::vec3(0.01f, 0.01f, 0.01f));
#endif
		Animation::Shader shader("exerciseanimation.vert", "exerciseanimation.frag");
		shader.setMat4("view", view_matrix);
		shader.setMat4("projection", projection_matrix);
		shader.setMat4("model", model_matrix);
#ifdef NATHAN
		Animation::Model model("D:/Projects/C++/OpenGLExercise/Assets/rp_nathan_animated_003_walking.fbx");
#endif
#ifdef BACKPACK
		//Animation::Model model("D:/Projects/C++/OpenGLExercise/Assets/survival_guitar_backpack.glb");
		Animation::Model model("D:/Projects/C++/OpenGLExercise/Assets/survival_backpack/Survival_BackPack_2.fbx");
#endif
		glEnable(GL_DEPTH_TEST);
		while (window.should_stay())
		{
			glClearColor(0.1f, 0.75f, 0.8f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			model.Draw(shader);
			glm::mat4 modelMat = glm::mat4(1.0f);
			modelMat = glm::translate(modelMat, model_position);
			modelMat = glm::rotate(modelMat, float(window.get_current_time()) * glm::radians(100.0f), glm::vec3(0.0f, 1.0f, 0.0f));
#ifdef BACKPACK
			modelMat = glm::scale(modelMat, glm::vec3(0.01f, 0.01f, 0.01f));
#endif
			shader.setMat4("model", modelMat);
			window.run_swapbuffer_eventpoller();
		}
		return 0;
	}

	void printMat4(glm::mat4& m)
	{
		for (int r = 0; r < 4; r++)
		{
			for (int c = 0; c < 4; c++)
			{
				std::cout << m[r][c];
				if (c < 3)
					std::cout << ", ";
			}
			std::cout << std::endl;
		}
	}

	void printVec3(glm::vec3& v)
	{
		std::cout << "("<<v.x<<", "<< v.y << ", " << v.z << ")" << std::endl;
	}
}