#include "raylib.h"
#include "Core.hpp"
#include "../Scene/Scene.hpp"
#include "../Scene/Scenes/MenuScene/MenuScene.hpp"
#include "../Scene/Scenes/GameScene/GameScene.hpp"
#include "../Scene/Scenes/GameOverScene/GameOverScene.hpp"

Core::Core(int windowWidth, int windowHeight, const std::string& windowTitle, int targetFPS)
	: windowWidth(windowWidth), windowHeight(windowHeight), windowTitle(windowTitle), targetFPS(targetFPS)
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	
	InitWindow(this->windowWidth, this->windowHeight, this->windowTitle.c_str());

	SetTargetFPS(this->targetFPS);

	InitAudioDevice();

	sceneManager.changeScene(new MenuScene(this->input, this->resourceManager, this->sceneManager, this->entityManager, this->renderer, this->cameraSystem, this->hud));
}

Core::~Core()
{
	CloseWindow();

	CloseAudioDevice();

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