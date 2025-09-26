#pragma once

#include "../ECS/EntityManager.hpp"
#include "../Renderer/Renderer.hpp"
#include "../CameraSystem/CameraSystem.hpp"
#include "../Scripting/Scripting.hpp"
#include "../Scripting/options.hpp"

class Scene
{
protected:
	EntityManager& entityManager;
	Renderer& renderer;
	CameraSystem& cameraSystem;
	Scripting& scripting;
	Options& options;

public:
	Scene(EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, Scripting& scripting, Options& options);

	virtual void init() = 0;

	virtual void update() = 0;

	virtual void draw() = 0;

	virtual void deInit() = 0;

	virtual ~Scene() = default;
};