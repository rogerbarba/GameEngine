#pragma once

#include "../../Scene.hpp"

class GameScene : public Scene
{
public:
	GameScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager);

	void update() override;

	void draw() override;

	~GameScene();
};