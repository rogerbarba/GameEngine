#pragma once

#include "Entity.hpp"
#include "Components.hpp"
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

class EntityManager
{
private:
	Entity nextID = 1;
	std::unordered_set<Entity> aliveEntities;
	std::unordered_map<std::string, Entity> namedEntities;

	std::unordered_map<Entity, TransformComponent> transforms;
	std::unordered_map<Entity, Sprite> sprites;
	std::unordered_map<Entity, Velocity> velocities;
	std::unordered_map<Entity, Health> healths;

public:
	Entity createEntity();
	void destroyEntity(Entity entity);

	void nameEntity(Entity entity, const std::string& name);
	Entity getNamedEntity(const std::string& name);
	void unnameEntity(const std::string& name);

	void addTransform(Entity entity, const TransformComponent& transform);
	void addSprite(Entity entity, const Sprite& sprite);
	void addVelocity(Entity entity, const Velocity& velocity);
	void addHealth(Entity entity, const Health& health);

	TransformComponent* getTransform(Entity entity);
	Sprite* getSprite(Entity entity);
	Velocity* getVelocity(Entity entity);
	Health* getHealth(Entity entity);

	std::vector<Entity> getEntitiesWithTransform();
	std::vector<Entity> getEntitiesWithSprite();
	std::vector<Entity> getEntitiesWithVelocity();
	std::vector<Entity> getEntitiesWithHealth();
};