#include "EntityManager.hpp"

Entity EntityManager::createEntity()
{
	Entity entity = nextID++;

	aliveEntities.emplace(entity);

	return entity;
}

void EntityManager::destroyEntity(Entity entity)
{
	aliveEntities.erase(entity);
	transforms.erase(entity);
	velocities.erase(entity);
	sprites.erase(entity);
	healths.erase(entity);
}

void EntityManager::nameEntity(Entity entity, const std::string& name)
{
	namedEntities.emplace(name, entity);
}

Entity EntityManager::getNamedEntity(const std::string& name)
{
	return namedEntities.at(name);
}

void EntityManager::unnameEntity(const std::string& name)
{
	namedEntities.erase(name);
}

void EntityManager::addTransform(Entity entity, const TransformComponent& transform)
{
	transforms.emplace(entity, transform);
}

void EntityManager::addSprite(Entity entity, const Sprite& sprite)
{
	sprites.emplace(entity, sprite);
}

void EntityManager::addVelocity(Entity entity, const Velocity& velocity)
{
	velocities.emplace(entity, velocity);
}

void EntityManager::addHealth(Entity entity, const Health& health)
{
	healths.emplace(entity, health);
}

TransformComponent* EntityManager::getTransform(Entity entity)
{
	return &transforms.at(entity);
}

Sprite* EntityManager::getSprite(Entity entity)
{
	return &sprites.at(entity);
}

Velocity* EntityManager::getVelocity(Entity entity)
{
	return &velocities.at(entity);
}

Health* EntityManager::getHealth(Entity entity)
{
	return &healths.at(entity);
}