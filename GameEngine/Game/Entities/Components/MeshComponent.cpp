#include "MeshComponent.h"

#include <iostream>

MeshComponent::MeshComponent() {

}

MeshComponent::~MeshComponent() {

}

void MeshComponent::Render() {
	std::cout << "Rendered Entity ID: " << std::endl;
}

ComponentType MeshComponent::GetComponentType() {
	return ComponentType_Mesh;
}