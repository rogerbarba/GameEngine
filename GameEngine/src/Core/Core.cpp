#include "raylib.h"
#include "Core.hpp"

Core::Core(int windowWidth, int windowHeight, std::string windowTitle, int targetFPS)
	: windowWidth(windowWidth), windowHeight(windowHeight), windowTitle(windowTitle), targetFPS(targetFPS) { }

void Core::init()
{
	InitWindow(this->windowWidth, this->windowHeight, this->windowTitle.c_str());

	SetTargetFPS(this->targetFPS);

	InitAudioDevice();
}

void Core::deInit()
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
	// ...
}

void Core::draw()
{
	BeginDrawing();
	EndDrawing();
}