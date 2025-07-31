#pragma once

#include "../../Scene.hpp"

class PauseScene : public Scene
{
public:
	PauseScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager);

	void update() override;

	void draw() override;

	~PauseScene();
};