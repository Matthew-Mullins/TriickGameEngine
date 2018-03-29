#include "GraphicsManager.h"

#include <iostream>

#include "../Game/Entities/Components/Component.h"
#include "../Game/Entities/Components/MeshComponent.h"

#include "../Game/Entities/Entity.h"
#include "../Game/Entities/EntityManager.h"

GraphicsManager& GraphicsManager::GetInstance() {
	static GraphicsManager instance;
	return instance;
}

bool GraphicsManager::Initialize() {
	//Initialize GLFW
	if (!glfwInit()) {
		std::cout << "Failed to Initialize GLFW" << std::endl;
		return false;
	}
	//Create Window
	if (!CreateWindow()) {
		std::cout << "Failed to Create GLFW Window" << std::endl;
		return false;
	}
	glfwMakeContextCurrent(window);
	//Initialize GLEW
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to Initialize GLEW" << std::endl;
		return false;
	}

	//Clear Sky Color
	glClearColor(180.0f / 255.0f, 215.0f / 255.0f, 230.0f / 255.0f, 1.0f);

	return true;
}

void GraphicsManager::Update() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Draw Stuff
	std::vector<Entity*> gameEntities = EntityManager::GetEntities();
	for (Entity* gameEntity : gameEntities) {
		MeshComponent* entityMesh = gameEntity->GetComponent<MeshComponent>();
		if (entityMesh) {
			//Render Mesh
			entityMesh->Render();
		}
	}

	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool GraphicsManager::CreateWindow() {
	glfwWindowHint(GLFW_SAMPLES, 4);		//4x Antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);		//OpenGL Version 4.4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);		//Modern OpenGL

	window = glfwCreateWindow(initWindowWidth, initWindowHeight, windowTitle, NULL, NULL);
	if (window == NULL) {
		glfwTerminate();
		return false;
	}
	return true;
}

GLFWwindow* GraphicsManager::GetWindow() {
	return window;
}