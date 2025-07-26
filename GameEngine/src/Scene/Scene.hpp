#pragma once

#include "../Input/Input.hpp"
#include "../ResourceManager/ResourceManager.hpp"

// Forward declaration
class SceneManager;

class Scene
{
protected:
	Input& input;
	ResourceManager& resourceManager;
	SceneManager& sceneManager;

public:
	Scene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager);

	virtual void update() = 0;

	virtual void draw() = 0;

	virtual ~Scene() = default;
};