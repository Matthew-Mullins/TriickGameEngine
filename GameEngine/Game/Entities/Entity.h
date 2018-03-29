#pragma once

#include <vector>

#include "Components/Component.h"
#include "Components/Transform.h"

class Entity {
	friend class EntityManager;
public:
	~Entity();

	Transform* GetTransform();

	void AddComponent(Component* _component);
	void AddComponents(std::vector<Component*> _components);

	//Returns First Component of Given Type
	template <class T>
	T* GetComponent() {
		for (Component* component : components) {
			T* typedComponent = dynamic_cast<T*>(component);
			if (typedComponent) {
				return typedComponent;
			}
		}
		return nullptr;
	}

	//Returns All Components of Given Type
	template <class T>
	std::vector<T*> GetComponents() {
		std::vector<T*> tempComponents;
		for (Component* component : components) {
			T* typedComponent = dynamic_cast<T*>(component);
			if (typedComponent) {
				tempComponents.push_back(typedComponent);
			}
		}
		return tempComponents;
	}

	size_t GetId() const;

	void MarkForDeletion();
	bool IsMarkedForDeletion() const;

private:
	Entity(size_t _id);

	size_t id;

	bool markedForDeletion;

	Transform* transform;
	std::vector<Component*> components;
};