#pragma once

#include "../Input/Input.hpp"
#include "../ResourceManager/ResourceManager.hpp"
#include "../ECS/EntityManager.hpp"
#include "../ECS/Entity.h"
#include "../ECS/Components.h"

// Forward declaration to avoid infinite loop with SceneManager.hpp
class SceneManager;

class Scene
{
protected:
	Input& input;
	ResourceManager& resourceManager;
	SceneManager& sceneManager;
	EntityManager& entityManager;

public:
	Scene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager);

	virtual void update() = 0;

	virtual void draw() = 0;

	virtual ~Scene() = default;
};