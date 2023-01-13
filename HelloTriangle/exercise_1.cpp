//#include <iostream>
//#include "glad/glad.h"
//#include "GLFW/glfw3.h"
//
//void logMessage(std::string  msg);
//void set_framebuffer_size_callback(GLFWwindow* window, int width, int height);
//
//int main() {
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#if __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//	GLFWwindow* window = glfwCreateWindow(600, 500, "LearnOpenGL", NULL, NULL);
//	if (window == NULL) {
//		logMessage("Failed to create the window!");
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, set_framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		logMessage("Failed to init glad");
//		glfwTerminate();
//		return -1;
//	}
//
//	const char* vertexShaderSource =
//		"#version 330 core\n"
//		"layout(location = 0) in vec3 aPos;\n"
//		"void main() {\n"
//		"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
//		"}\n";
//
//	const char* fragmentShaderSource =
//		"#version 330 core\n"
//		"out vec4 FragColor;\n"
//		"void main() {\n"
//		"	FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
//		"}\n";
//
//	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		logMessage(infoLog);
//	}
//
//	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		logMessage(infoLog);
//	}
//
//	unsigned int shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		logMessage(infoLog);
//	}
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	float vertices[] = {
//		-0.5f, -0.5f, 0.0f, // bottom left
//		-0.5f,  0.5f, 0.0f, // top left
//		 0.5f,  0.5f, 0.0f, // top right
//
//		-0.5f, -0.5f, 0.0f, // bottom left
//		 0.5f,  0.5f, 0.0f, // top right
//		 0.5f, -0.5f, 0.0f  // bottom right
//	};
//
//	unsigned int VAO, VBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	while (!glfwWindowShouldClose(window)) {
//
//		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
//			glfwSetWindowShouldClose(window, GL_TRUE);
//		}
//
//		glClearColor(0.2f, 0.1f, 0.4f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteProgram(shaderProgram);
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//
//	return 0;
//}
//
//void logMessage(std::string  msg) {
//	std::cout << msg << std::endl;
//}
//
//void set_framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}