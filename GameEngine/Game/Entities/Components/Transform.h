#pragma once

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

class Transform {
public:
	Transform(Transform* _parent = nullptr);

	static const glm::vec3 FORWARD;
	static const glm::vec3 RIGHT;
	static const glm::vec3 UP;

	void Translate(glm::vec3 _translation);
	void Scale(glm::vec3 _scale);
	void Rotate(glm::quat _rotation);

	void SetPosition(glm::vec3 _position);
	void SetScale(glm::vec3 _scale);
	void SetRotation(glm::quat _rotation);

	glm::vec3 GetLocalPosition();
	glm::vec3 GetLocalScale();
	glm::quat GetLocalRotation();

	glm::vec3 GetGlobalPosition();
	glm::vec3 GetGlobalScale();
	glm::quat GetGlobalRotation();

	glm::vec3 GetForward();
	glm::vec3 GetRight();
	glm::vec3 GetUp();

	glm::mat4 GetTranslationMatrix();
	glm::mat4 GetScalingMatrix();
	glm::mat4 GetRotationMatrix();
	glm::mat4 GetTransformationMatrix();

private:
	Transform* parent;

	glm::vec3 position;
	glm::vec3 scale;
	glm::quat rotation;

	glm::mat4 translationMatrix;
	glm::mat4 scalingMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 transformationMatrix;

private:
	glm::vec3 GetLocalDirection(glm::vec3 _globalDirection);
	glm::vec3 GetGlobalDirection(glm::vec3 _localDirection);

	void UpdateTranslationMatrix();
	void UpdateScalingMatrix();
	void UpdateRotationMatrix();
	void UpdateTransformationMatrix();
};