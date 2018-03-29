#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Input/InputManager.h"
#include "../Graphics/GraphicsManager.h"

#include "../Utilities/Time.h"

class GameManager {
public:
	//Return Singleton Instance
	static GameManager& GetInstance();

	bool Initialize();
	void Run();
	void Update();

	static Time GetDeltaTime();
	static Time GetGameTime();

private:
	//Prevent Copying of Singleton Instance
	GameManager() {}
	GameManager(const GameManager&) = delete;
	void operator=(const GameManager&) = delete;

private:
	static Time deltaTime;
	static Time gameTime;
	Time currentTime = 0;
	Time lastTime = 0;

	InputManager& inputManager = InputManager::GetInstance();
	GraphicsManager& graphicsManager = GraphicsManager::GetInstance();
	//Audio Manager
	//Physics Manager
};