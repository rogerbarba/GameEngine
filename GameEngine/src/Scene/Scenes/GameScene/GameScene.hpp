#pragma once

#include "../../Scene.hpp"

class GameScene : public Scene
{
private:
	bool paused = false;

public:
	GameScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, HUD& hud);

	void update() override;

	void draw() override;

	~GameScene();
};