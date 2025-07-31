#include "EntityManager.hpp"

Entity EntityManager::createEntity()
{
	Entity entity = nextID++;

	aliveEntities.emplace(entity);

	return entity;
}

void EntityManager::nameEntity(Entity entity, const std::string& name)
{
	namedEntities.emplace(name, entity);
}

Entity EntityManager::getNamedEntity(const std::string& name)
{
	return namedEntities.at(name);
}

void EntityManager::destroyEntity(Entity entity)
{
	aliveEntities.erase(entity);
	transforms.erase(entity);
	velocities.erase(entity);
	sprites.erase(entity);
}

void EntityManager::addTransform(Entity entity, const Transform& transform)
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

Transform* EntityManager::getTransform(Entity entity)
{
	if (transforms.find(entity) != transforms.end())
	{
		return &transforms.at(entity);
	}
}

Sprite* EntityManager::getSprite(Entity entity)
{
	if (sprites.find(entity) != sprites.end())
	{
		return &sprites.at(entity);
	}
}

Velocity* EntityManager::getVelocity(Entity entity)
{
	if (velocities.find(entity) != velocities.end())
	{
		return &velocities.at(entity);
	}
}

Health* EntityManager::getHealth(Entity entity)
{
	if (healths.find(entity) != healths.end())
	{
		return &healths.at(entity);
	}
}