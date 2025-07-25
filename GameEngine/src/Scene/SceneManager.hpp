#pragma once

#include "Scene.hpp"

class SceneManager
{
private:
	Scene* currentScene = nullptr;

public:
	void changeScene(Scene* scene);

	void update();

	void draw();

	void deInit();
};