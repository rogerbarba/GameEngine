#include "raylib.h"
#include "Core.hpp"

Core::Core(int windowWidth, int windowHeight, std::string windowTitle, int targetFPS)
	: windowWidth(windowWidth), windowHeight(windowHeight), windowTitle(windowTitle), targetFPS(targetFPS) { }

void Core::Init()
{
	InitWindow(this->windowWidth, this->windowHeight, this->windowTitle.c_str());

	SetTargetFPS(this->targetFPS);

	InitAudioDevice();
}

void Core::DeInit()
{
	CloseWindow();

	CloseAudioDevice();

	resourceManager.unloadAll();
}

void Core::Run()
{
	while (!WindowShouldClose())
	{
		Update();

		Draw();
	}
}

void Core::Update()
{
	// ...
}

void Core::Draw()
{
	BeginDrawing();
	EndDrawing();
}