#include "Component.h"

Component::Component() {}

Component::~Component() {}

void Component::SetOwner(Entity* _owner) {
	owner = _owner;
}

Entity* Component::GetOwner() {
	return owner;
}

bool Component::IsEnabled() {
	return enabled;
}

void Component::SetEnabled(bool _value) {
	enabled = _value;
}