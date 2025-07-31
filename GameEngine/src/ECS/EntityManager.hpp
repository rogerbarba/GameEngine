#pragma once

#include "Entity.h"
#include "Components.h"
#include <unordered_set>
#include <unordered_map>
#include <string>

class EntityManager
{
private:
	Entity nextID = 1;
	std::unordered_set<Entity> aliveEntities;
	std::unordered_map<std::string, Entity> namedEntities;

	std::unordered_map<Entity, Transform> transforms;
	std::unordered_map<Entity, Sprite> sprites;
	std::unordered_map<Entity, Velocity> velocities;
	std::unordered_map<Entity, Health> healths;

public:
	Entity createEntity();
	void nameEntity(Entity entity, const std::string& name);
	Entity getNamedEntity(const std::string& name);
	void destroyEntity(Entity entity);

	void addTransform(Entity entity, const Transform& transform);
	void addSprite(Entity entity, const Sprite& sprite);
	void addVelocity(Entity entity, const Velocity& velocity);
	void addHealth(Entity entity, const Health& health);

	Transform* getTransform(Entity entity);
	Sprite* getSprite(Entity entity);
	Velocity* getVelocity(Entity entity);
	Health* getHealth(Entity entity);
};