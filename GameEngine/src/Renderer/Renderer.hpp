#pragma once

#include "../ECS/EntityManager.hpp"
#include "../CameraSystem/CameraSystem.hpp"
#include "../Scripting/options.hpp"

class Renderer
{
public:
	void render(EntityManager& entityManager, Camera2D camera, Options& options);
};