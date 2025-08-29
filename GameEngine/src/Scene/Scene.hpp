#pragma once

#include "../Input/Input.hpp"
#include "../ResourceManager/ResourceManager.hpp"
#include "../ECS/EntityManager.hpp"
#include "../Renderer/Renderer.hpp"
#include "../ECS/Entity.hpp"
#include "../ECS/Components.hpp"

// Forward declaration to avoid infinite loop with SceneManager.hpp
class SceneManager;

class Scene
{
protected:
	Input& input;
	ResourceManager& resourceManager;
	SceneManager& sceneManager;
	EntityManager& entityManager;
	Renderer& renderer;

public:
	Scene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager, Renderer& renderer);

	virtual void update() = 0;

	virtual void draw() = 0;

	virtual ~Scene() = default;
};