#pragma once

#include "../../Scene.hpp"

class MenuScene : public Scene
{
public:
	MenuScene(EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, Scripting& scripting, Options& options);

	void init() override;

	void update() override;

	void draw() override;

	void deInit() override;
};