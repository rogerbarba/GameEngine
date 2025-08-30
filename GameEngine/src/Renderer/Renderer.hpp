#pragma once

#include "../ECS/EntityManager.hpp"
#include "../CameraSystem/CameraSystem.hpp"

class Renderer
{
public:
	void render(EntityManager& entityManager, Camera2D camera);
};