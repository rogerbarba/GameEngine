#include "EntityManager.hpp"

Entity& EntityManager::createEntity()
{
	Entity entity = nextID++;

	aliveEntities.emplace(entity);

	Entity& r = entity;
	return r;
}

void EntityManager::destroyEntity(Entity entity)
{
	if (!aliveEntities.contains(entity))
		return;

	aliveEntities.erase(entity);

	// Erase from namedEntities safely
	for (auto it = namedEntities.begin(); it != namedEntities.end(); )
	{
		if (it->second == entity)
			it = namedEntities.erase(it);
		else
			++it;
	}

	transforms.erase(entity);
	rectangles.erase(entity);
	circles.erase(entity);
	sprites.erase(entity);
	velocities.erase(entity);
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

void EntityManager::addRectangle(Entity entity, const RectangleShape& rectangle)
{
	rectangles.emplace(entity, rectangle);
}

void EntityManager::addCircle(Entity entity, const CircleShape& circle)
{
	circles.emplace(entity, circle);
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

RectangleShape* EntityManager::getRectangle(Entity entity)
{
	auto it = rectangles.find(entity);
	return (it != rectangles.end()) ? &it->second : nullptr;
}

CircleShape* EntityManager::getCircle(Entity entity)
{
	auto it = circles.find(entity);
	return (it != circles.end()) ? &it->second : nullptr;
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

std::vector<Entity> EntityManager::getEntitiesWithTransformAndRectangle()
{
	std::vector<Entity> result;
	for (const auto& pair : transforms)
	{
		Entity e = pair.first;
		if (aliveEntities.find(e) != aliveEntities.end() && rectangles.find(e) != rectangles.end())
		{
			result.emplace_back(e);
		}
	}
	return result;
}

std::vector<Entity> EntityManager::getEntitiesWithTransformAndCircle()
{
	std::vector<Entity> result;
	for (const auto& pair : transforms)
	{
		Entity e = pair.first;
		if (aliveEntities.find(e) != aliveEntities.end() && circles.find(e) != circles.end())
		{
			result.emplace_back(e);
		}
	}
	return result;
}

std::vector<Entity> EntityManager::getEntitiesWithTransformAndSprite()
{
	std::vector<Entity> result;
	for (const auto& pair : transforms)
	{
		Entity e = pair.first;
		if (aliveEntities.find(e) != aliveEntities.end() && sprites.find(e) != sprites.end())
		{
			result.emplace_back(e);
		}
	}
	return result;
}
