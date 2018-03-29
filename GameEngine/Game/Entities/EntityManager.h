#pragma once

#include <vector>
#include <map>

#include "Entity.h"

class EntityManager {
public:
	//Entity Access
	static Entity* FindEntity(size_t id);
	static std::vector<Entity*> GetEntities();

	//Manage Entities
	static Entity* CreateEntity();

	static void DestroyEntity(Entity* _entity);
	static void DestroyEntity(size_t _id);
	static void DestroyEntities(std::vector<Entity*> _entities);
	static void DestroyEntities(std::vector<size_t> _ids);
private:
	static size_t nextEntityId;

	static std::vector<Entity*> entities;
	static std::map<size_t, Entity*> idToEntity;
};