//#include <iostream>
//
//#include "glad/glad.h"
//#include "GLFW/glfw3.h"
//
//#include <cmath>
//
//void set_framebuffer_size_callback(GLFWwindow* window, int width, int height);
//
//int main() {
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#if __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "Shader Triangle", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "failed to create the window!\n";
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, set_framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "failed to init glad!\n";
//		glfwTerminate();
//		return -1;
//	}
//
//	const char* vertexShaderSrc =
//		"#version 330 core\n"
//		"layout(location = 0) in vec3 aPos;\n"
//		"void main() {\n"
//		"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
//		"}\n";
//
//	const char* fragmentShaderSrc = 
//		"#version 330 core\n"
//		"out vec4 FragColor;\n"
//		"uniform vec4 ourColor;\n"
//		"void main() {\n"
//		"	FragColor = ourColor;\n"
//		"}\n";
//
//	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSrc, NULL);
//	glCompileShader(vertexShader);
//
//	int success;
//	char infoLog[512];
//
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "failed to compile vertex shader. error: " << infoLog << std::endl;
//	}
//
//	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSrc, NULL);
//	glCompileShader(fragmentShader);
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "failed to compile fragment shader. error: " << infoLog << std::endl;
//	}
//
//	unsigned int shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "failed to link the shader program. error: " << infoLog << std::endl;
//	}
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	float vertices[] = {
//		-0.5f, -0.5f, 0.0f,
//		 0.0f,  0.5f, 0.0f,
//		 0.5f, -0.5f, 0.0f
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
//
//	while (!glfwWindowShouldClose(window)) {
//		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgram);
//
//	    auto ourColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//
//	    auto time = glfwGetTime();
//		auto color = static_cast<float>( (sin(time) / 2.0f) + 0.5f );
//
//		glUniform4f(ourColorLocation, 0.0f, color, 0.0f, 1.0f);
//		
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		 
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteProgram(shaderProgram);
//	glDeleteBuffers(1, &VBO);
//	glDeleteVertexArrays(1, &VAO);
//	glfwTerminate();
//
//	return 0;
//}
//
//void set_framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}
