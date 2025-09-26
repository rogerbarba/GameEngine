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
	// Entity
	Entity nextID = 1;
	std::unordered_set<Entity> aliveEntities;
	std::unordered_map<std::string, Entity> namedEntities;

	// Component
	std::unordered_map<Entity, TransformComponent> transforms;
	std::unordered_map<Entity, RectangleShape> rectangles;
	std::unordered_map<Entity, CircleShape> circles;
	std::unordered_map<Entity, Sprite> sprites;
	std::unordered_map<Entity, Velocity> velocities;
	std::unordered_map<Entity, Health> healths;

public:
	// Entity
	Entity& createEntity();
	void destroyEntity(Entity entity);
	void nameEntity(Entity entity, const std::string& name);
	Entity getNamedEntity(const std::string& name);

	// Component
	void addTransform(Entity entity, const TransformComponent& transform);
	void addRectangle(Entity entity, const RectangleShape& rectangle);
	void addCircle(Entity entity, const CircleShape& circle);
	void addSprite(Entity entity, const Sprite& sprite);
	void addVelocity(Entity entity, const Velocity& velocity);
	void addHealth(Entity entity, const Health& health);

	TransformComponent* getTransform(Entity entity);
	RectangleShape* getRectangle(Entity entity);
	CircleShape* getCircle(Entity entity);
	Sprite* getSprite(Entity entity);
	Velocity* getVelocity(Entity entity);
	Health* getHealth(Entity entity);

	// System
	std::vector<Entity> getEntitiesWithTransformAndRectangle();
	std::vector<Entity> getEntitiesWithTransformAndCircle();
	std::vector<Entity> getEntitiesWithTransformAndSprite();
};