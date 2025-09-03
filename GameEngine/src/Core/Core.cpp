#include "raylib.h"
#include "Core.hpp"
#include "../Scene/Scene.hpp"
#include "../Scene/Scenes/MenuScene/MenuScene.hpp"
#include "../Scene/Scenes/GameScene/GameScene.hpp"
#include "../Scene/Scenes/GameOverScene/GameOverScene.hpp"

Core::Core(int windowWidth, int windowHeight, const std::string& windowTitle, int targetFPS)
	: options{ windowWidth, windowHeight, windowTitle, targetFPS } { }

void Core::init()
{
	scripting.init(*this);
	sol::state& lua = scripting.getLua();

	lua.script_file("scripts/test.lua");
	// run script files and all here

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	InitWindow(options.windowWidth, options.windowHeight, options.windowTitle.c_str());

	SetTargetFPS(options.targetFPS);

	InitAudioDevice();

	sceneManager.changeScene(new MenuScene(this->entityManager, this->renderer, this->cameraSystem, this->scripting));
}

void Core::deInit()
{
	sceneManager.deInit();

	resourceManager.unloadAll();

	CloseWindow();

	CloseAudioDevice();
}

void Core::run()
{
	while (!WindowShouldClose())
	{
		update();

		draw();
	}
}

void Core::update()
{
	sceneManager.update();
}

void Core::draw()
{
	BeginDrawing();

	sceneManager.draw();

	EndDrawing();
}

void Core::expose(sol::state& lua)
{
	lua.new_usertype<Options>("Options",
		"windowWidth", &Options::windowWidth,
		"windowHeight", &Options::windowHeight,
		"windowTitle", &Options::windowTitle,
		"targetFPS", &Options::targetFPS
	);

	lua["options"] = &options;
}