#pragma once

#include "../Scene.hpp"

class MenuScene : public Scene
{
public:
	MenuScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager)
		: Scene(input, resourceManager, sceneManager) { }

	void init() override;

	void update() override;

	void draw() override;

	void deInit() override;
};