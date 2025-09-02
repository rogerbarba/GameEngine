#pragma once

#include "../../Scene.hpp"

class MenuScene : public Scene
{
public:
	MenuScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, HUD& hud, Audio& audio, CollisionSystem& collisionSystem);

	void update() override;

	void draw() override;

	~MenuScene();
};