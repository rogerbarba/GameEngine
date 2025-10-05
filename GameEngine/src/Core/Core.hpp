#pragma once

#include <string>
#include "sol/sol.hpp"
#include "../Scripting/options.hpp"
#include "../Scripting/utils.hpp"
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

#include "../Scene/Scenes/MenuScene/MenuScene.hpp"
#include "../Scene/Scenes/GameScene/GameScene.hpp"
#include "../Scene/Scenes/GameOverScene/GameOverScene.hpp"

class Core
{
private:
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
	Scripting scripting;

	Options options;
	Utils utils;
	MenuScene* menuScene;
	GameScene* gameScene;
	GameOverScene* gameOverScene;

public:
	Core();

	void init();

	void run();

	void deInit();

	void expose(sol::state& lua);

	void exposeOptions(sol::state& lua);
	void exposeUtils(sol::state& lua);
	void exposeRaylibStructs(sol::state& lua);
	void exposeRaylibColors(sol::state& lua);
	void exposeKeysAndButtons(sol::state& lua);

	void exposeInput(sol::state& lua);
	void exposeResourceManager(sol::state& lua);
	void exposeSceneManager(sol::state& lua);
	void exposeEntityManager(sol::state& lua);
	void exposeRenderer(sol::state& lua);
	void exposeCameraSystem(sol::state& lua);
	void exposeHUD(sol::state& lua);
	void exposeAudio(sol::state& lua);
	void exposeCollisionSystem(sol::state& lua);
};