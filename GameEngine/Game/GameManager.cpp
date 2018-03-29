#include "GameManager.h"

#include <iostream>

#include "Entities/EntityManager.h"

#include "Entities/Components/Component.h"
#include "Entities/Components/MeshComponent.h"

Time GameManager::deltaTime = 0;
Time GameManager::gameTime = 0;

GameManager& GameManager::GetInstance() {
	static GameManager instance;
	return instance;
}

bool GameManager::Initialize() {
	if (!graphicsManager.Initialize()) {
		std::cout << "Failed to Initialize Graphics Manager" << std::endl;
		return false;
	}
	if (!inputManager.Initialize()) {
		std::cout << "Failed to Initialize Input Manager" << std::endl;
		return false;
	}

	Entity* entity = EntityManager::CreateEntity();
	entity->AddComponent(new MeshComponent());

	return true;
}

void GameManager::Run(){
	inputManager.Update();
	GameManager::Update();
	graphicsManager.Update();
}

void GameManager::Update() {
	//Update DeltaTime
	currentTime = glfwGetTime();
	deltaTime = currentTime - lastTime;
	lastTime = currentTime;

}

Time GameManager::GetDeltaTime() {
	return deltaTime;
}

Time GameManager::GetGameTime() {
	return gameTime;
}