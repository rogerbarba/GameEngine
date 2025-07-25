#pragma once

#include "../Input/Input.hpp"
#include "../ResourceManager/ResourceManager.hpp"

class Scene
{
protected:
	Input& input;
	ResourceManager& resourceManager;

public:
	Scene(Input& input, ResourceManager& resourceManager)
		: input(input), resourceManager(resourceManager) { }

	virtual void init() = 0;

	virtual void update() = 0;

	virtual void draw() = 0;

	virtual void deInit() = 0;
};