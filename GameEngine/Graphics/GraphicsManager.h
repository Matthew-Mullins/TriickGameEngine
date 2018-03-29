#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class GraphicsManager {
public:
	//Return Singleton Instance
	static GraphicsManager& GetInstance();

	bool Initialize();
	void Update();

	GLFWwindow* GetWindow();

private:
	//Prevent Copying of Singleton Instance
	GraphicsManager() {}
	GraphicsManager(const GraphicsManager&) = delete;
	void operator=(const GraphicsManager&) = delete;

	bool CreateWindow();

private:
	GLFWwindow* window;
	const GLuint initWindowWidth = 1024;
	const GLuint initWindowHeight = 768;
	const char* windowTitle = "GameEngine";
};