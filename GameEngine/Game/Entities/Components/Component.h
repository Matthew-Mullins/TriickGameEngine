#pragma once

class Entity;
class MeshComponent;

enum ComponentType {
	ComponentType_Mesh
};

class Component {
public:
	Component();
	~Component();

	void SetOwner(Entity* _owner);
	Entity* GetOwner();

	bool IsEnabled();
	void SetEnabled(bool _value);

	virtual ComponentType GetComponentType() = 0;

private:
	bool enabled = true;

	Entity* owner;
};