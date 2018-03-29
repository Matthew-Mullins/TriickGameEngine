#include "Transform.h"

#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>

const glm::vec3 Transform::FORWARD = glm::vec3(0.0f, 0.0f, 1.0f);
const glm::vec3 Transform::RIGHT = glm::vec3(1.0f, 0.0f, 0.0f);
const glm::vec3 Transform::UP = glm::vec3(0.0f, 1.0f, 0.0f);

Transform::Transform(Transform* _parent) {
	parent = _parent;
	SetPosition(glm::vec3(0.0f));
	SetScale(glm::vec3(1.0f));
	SetRotation(glm::quat());
}

void Transform::Translate(glm::vec3 _translation) {
	SetPosition(position + _translation);
}

void Transform::Scale(glm::vec3 _scale) {
	SetScale(scale * _scale);
}

void Transform::Rotate(glm::quat _rotation) {
	SetRotation(_rotation * rotation);
}

void Transform::SetPosition(glm::vec3 _position) {
	position = _position;
	UpdateTranslationMatrix();
}

void Transform::SetScale(glm::vec3 _scale) {
	scale = _scale;
	UpdateScalingMatrix();
}

void Transform::SetRotation(glm::quat _rotation) {
	rotation = _rotation;
	UpdateRotationMatrix();
}

glm::vec3 Transform::GetLocalPosition() {
	//Relative to parents position
	if(parent) return position - parent->position;
	return glm::vec3(0.0f);
}

glm::vec3 Transform::GetLocalScale() {
	//Relative to parents scale
	if(parent) return scale / parent->scale;
	return glm::vec3(1.0f);
}

glm::quat Transform::GetLocalRotation() {
	//Relative to parents rotation
	if (parent) return glm::inverse(parent->rotation) * rotation;
	return glm::quat();
}

glm::vec3 Transform::GetLocalDirection(glm::vec3 _globalDirection) {
	return glm::inverse(GetTransformationMatrix()) * glm::vec4(_globalDirection, 0.0f);
}

glm::vec3 Transform::GetGlobalPosition() {
	return position;
}

glm::vec3 Transform::GetGlobalScale() {
	return scale;
}

glm::quat Transform::GetGlobalRotation() {
	return rotation;
}

glm::vec3 Transform::GetGlobalDirection(glm::vec3 _localDirection) {
	return GetTransformationMatrix() * glm::vec4(_localDirection, 0.0f);
}

glm::vec3 Transform::GetForward() {
	GetGlobalDirection(FORWARD);
}

glm::vec3 Transform::GetRight() {
	GetGlobalDirection(RIGHT);
}

glm::vec3 Transform::GetUp() {
	GetGlobalDirection(UP);
}

glm::mat4 Transform::GetTranslationMatrix() {
	return translationMatrix;
}

glm::mat4 Transform::GetScalingMatrix() {
	return scalingMatrix;
}

glm::mat4 Transform::GetRotationMatrix() {
	return rotationMatrix;
}

glm::mat4 Transform::GetTransformationMatrix() {
	return transformationMatrix;
}

void Transform::UpdateTranslationMatrix() {
	translationMatrix = glm::translate(position);
	UpdateTransformationMatrix();
}

void Transform::UpdateScalingMatrix() {
	scalingMatrix = glm::scale(scale);
	UpdateTransformationMatrix();
}

void Transform::UpdateRotationMatrix() {
	rotationMatrix = glm::toMat4(rotation);
	UpdateTransformationMatrix();
}

void Transform::UpdateTransformationMatrix() {
	transformationMatrix = translationMatrix * scalingMatrix * rotationMatrix;
}