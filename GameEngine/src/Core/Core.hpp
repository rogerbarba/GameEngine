#pragma once

#include <string>
#include "../Input/Input.hpp"
#include "../ResourceManager/ResourceManager.hpp"
#include "../Scene/SceneManager.hpp"
#include "../ECS/EntityManager.hpp"
#include "../Renderer/Renderer.hpp"
#include "../CameraSystem/CameraSystem.hpp"
#include "../HUD/HUD.hpp"
#include "../Audio/Audio.hpp"
#include "../CollisionSystem/CollisionSystem.hpp"

class Core
{
private:
	int windowWidth;
	int windowHeight;
	std::string windowTitle;
	int targetFPS;

	void update();
	void draw();

	Input input;
	ResourceManager resourceManager;
	SceneManager sceneManager;
	EntityManager entityManager;
	Renderer renderer;
	CameraSystem cameraSystem;
	HUD hud;
	Audio audio;
	CollisionSystem collisionSystem;

public:
	Core(int windowWidth, int windowHeight, const std::string& windowTitle, int targetFPS);

	void run();

	~Core();
};