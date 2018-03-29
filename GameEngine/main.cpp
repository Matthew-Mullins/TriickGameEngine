#include <iostream>

#include "Game/GameManager.h"
#include "Graphics/GraphicsManager.h"

int main(int argc, char* argv[]) {

	GameManager& gameManager = GameManager::GetInstance();
	if (!gameManager.Initialize()) {
		std::cout << "Failed to Initialize Game Manager" << std::endl;
		return -1;
	}

	while (!glfwWindowShouldClose(GraphicsManager::GetInstance().GetWindow())) {
		gameManager.Run();
	}

	glfwTerminate();
	return 0;
}