#pragma once

#include "../../Scene.hpp"
#include "../../../Input/Input.hpp"

class GameScene : public Scene
{
private:
	Input& input;

	bool paused = false;

public:
	GameScene(Input& input, EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, Scripting& scripting);

	void init() override;

	void update() override;

	void draw() override;

	void deInit() override;
};