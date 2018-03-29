#include "Entity.h"

Entity::Entity(size_t _id) :
	id(_id),
	components(std::vector<Component*>()),
	markedForDeletion(false),
	transform(new Transform())
	{}

Entity::~Entity() {
	while (!components.empty()) {
		//Destroy Components
	}
}

Transform* Entity::GetTransform() {
	return transform;
}

void Entity::AddComponent(Component* _component) {
	_component->SetOwner(this);
	components.push_back(_component);
}

void Entity::AddComponents(std::vector<Component*> _components) {
	for (Component* component : _components) {
		AddComponent(component);
	}
}

size_t Entity::GetId() const{
	return id;
}

void Entity::MarkForDeletion() {
	markedForDeletion = true;
}

bool Entity::IsMarkedForDeletion() const{
	return markedForDeletion;
}