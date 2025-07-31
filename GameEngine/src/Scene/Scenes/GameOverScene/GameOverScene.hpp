#pragma once

#include "../../Scene.hpp"

class GameOverScene : public Scene
{
public:
	GameOverScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager);

	void update() override;

	void draw() override;

	~GameOverScene();
};