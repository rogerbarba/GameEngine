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

	// Delete entity from namedEntities if it is named
	for (const auto& pair : namedEntities)
	{
		if (pair.second == entity)
		{
			namedEntities.erase(pair.first);
		}
	}

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
	auto it = transforms.find(entity);
	return (it != transforms.end()) ? &it->second : nullptr;
}

Sprite* EntityManager::getSprite(Entity entity)
{
	auto it = sprites.find(entity);
	return (it != sprites.end()) ? &it->second : nullptr;
}

Velocity* EntityManager::getVelocity(Entity entity)
{
	auto it = velocities.find(entity);
	return (it != velocities.end()) ? &it->second : nullptr;
}

Health* EntityManager::getHealth(Entity entity)
{
	auto it = healths.find(entity);
	return (it != healths.end()) ? &it->second : nullptr;
}

std::vector<Entity> EntityManager::getEntitiesWithTransform()
{
	std::vector<Entity> result;
	for (const auto& pair : transforms)
	{
		if (aliveEntities.find(pair.first) != aliveEntities.end())
		{
			result.emplace_back(pair.first);
		}
	}
	return result;
}

std::vector<Entity> EntityManager::getEntitiesWithSprite()
{
	std::vector<Entity> result;
	for (const auto& pair : sprites)
	{
		if (aliveEntities.find(pair.first) != aliveEntities.end())
		{
			result.emplace_back(pair.first);
		}
	}
	return result;
}

std::vector<Entity> EntityManager::getEntitiesWithVelocity()
{
	std::vector<Entity> result;
	for (const auto& pair : velocities)
	{
		if (aliveEntities.find(pair.first) != aliveEntities.end())
		{
			result.emplace_back(pair.first);
		}
	}
	return result;
}

std::vector<Entity> EntityManager::getEntitiesWithHealth()
{
	std::vector<Entity> result;
	for (const auto& pair : healths)
	{
		if (aliveEntities.find(pair.first) != aliveEntities.end())
		{
			result.emplace_back(pair.first);
		}
	}
	return result;
}
