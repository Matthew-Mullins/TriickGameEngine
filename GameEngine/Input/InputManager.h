#pragma once

class InputManager {
public:
	//Return Singleton Instance
	static InputManager& GetInstance();

	bool Initialize();
	void Update();

	void HandleMouse();
	void HandleKeyboard();
	void HandleGamepad();

private:
	//Prevent Copying of Singleton Instance
	InputManager() {}
	InputManager(const InputManager&) = delete;
	void operator=(const InputManager&) = delete;
};