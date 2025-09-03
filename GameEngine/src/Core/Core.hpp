#pragma once

#include "sol/sol.hpp"
#include "../Scripting/options.hpp"
#include "../Scripting/Scripting.hpp"
#include "../Input/Input.hpp"
#include "../ResourceManager/ResourceManager.hpp"
#include "../Scene/SceneManager.hpp"
#include "../ECS/EntityManager.hpp"
#include "../Renderer/Renderer.hpp"
#include "../CameraSystem/CameraSystem.hpp"
#include "../HUD/HUD.hpp"
#include "../Audio/Audio.hpp"
#include "../CollisionSystem/CollisionSystem.hpp"
#include <string>

class Core
{
private:
	Options options;

	void update();
	void draw();

	Input input;
	ResourceManager resourceManager;
	SceneManager sceneManager;
	EntityManager entityManager;
	Renderer renderer;
	CameraSystem cameraSystem;
	Scripting scripting;

public:
	Core(int windowWidth = 800, int windowHeight = 600, const std::string& windowTitle = "Window", int targetFPS = 60);

	void init();

	void run();

	void deInit();

	void expose(sol::state& lua);
};