#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

void processTheInput(GLFWwindow*);
void displayMessage(std::string);

int main() {
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif 

    GLFWwindow* window = glfwCreateWindow(600, 400, "Learn OpenGL", NULL, NULL);
	if (window == NULL) {
		displayMessage("Failed to create window!");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		displayMessage("Failed to initialize glad!");
		return -1;
	}

	while (!glfwWindowShouldClose(window)) {
		processTheInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void displayMessage(std::string msg) {
	std::cout << msg << std::endl;
}

void processTheInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}