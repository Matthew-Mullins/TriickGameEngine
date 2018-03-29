#include "EntityManager.h"

size_t EntityManager::nextEntityId = 0;

std::vector<Entity*> EntityManager::entities;
std::map<size_t, Entity*> EntityManager::idToEntity;

Entity* EntityManager::FindEntity(size_t _id) {
	return idToEntity[_id];
}

std::vector<Entity*> EntityManager::GetEntities() {
	return entities;
}

Entity* EntityManager::CreateEntity() {
	const size_t tempId = nextEntityId++;
	Entity* entity = new Entity(tempId);
	entities.push_back(entity);
	idToEntity[tempId] = entity;
	return entity;
}

void EntityManager::DestroyEntity(Entity* _entity) {
	if (!_entity) {
		return;
	}
	idToEntity.erase(_entity->GetId());
	const auto iterator = std::find(entities.begin(), entities.end(), _entity);
	entities.erase(iterator);
	delete _entity;
}

void EntityManager::DestroyEntity(size_t _id) {
	DestroyEntity(FindEntity(_id));
}

void EntityManager::DestroyEntities(std::vector<Entity*> _entities) {
	for (Entity* entity : _entities) {
		DestroyEntity(entity);
	}
}

void EntityManager::DestroyEntities(std::vector<size_t> _ids) {
	for (size_t id : _ids) {
		DestroyEntity(FindEntity(id));
	}
}