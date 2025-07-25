#include "raylib.h"
#include "Core.hpp"
#include "../Scene/Scene.hpp"
#include "../Scene/Scenes/MenuScene.hpp"
// ... other scences

Core::Core(int windowWidth, int windowHeight, std::string windowTitle, int targetFPS)
	: windowWidth(windowWidth), windowHeight(windowHeight), windowTitle(windowTitle), targetFPS(targetFPS) { }

void Core::init()
{
	InitWindow(this->windowWidth, this->windowHeight, this->windowTitle.c_str());

	SetTargetFPS(this->targetFPS);

	InitAudioDevice();

	sceneManager.changeScene(new MenuScene(this->input, this->resourceManager, this->sceneManager));
}

void Core::deInit()
{
	CloseWindow();

	CloseAudioDevice();

	sceneManager.deInit();

	resourceManager.unloadAll();
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