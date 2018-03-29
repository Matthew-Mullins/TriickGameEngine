#include "InputManager.h"

InputManager& InputManager::GetInstance() {
	static InputManager instance;
	return instance;
}

bool InputManager::Initialize() {

	return true;
}

void InputManager::Update() {
	HandleMouse();
	HandleKeyboard();
	HandleGamepad();
}

void InputManager::HandleMouse() {
	return;
}

void InputManager::HandleKeyboard() {
	return;
}

void InputManager::HandleGamepad() {
	return;
}