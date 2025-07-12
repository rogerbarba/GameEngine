#include "raylib.h"
#include "Core.hpp"

Core::Core(int windowWidth, int windowHeight, std::string windowTitle, int targetFPS)
	: windowWidth(windowWidth), windowHeight(windowHeight), windowTitle(windowTitle), targetFPS(targetFPS) { }

void Core::Init()
{
	InitWindow(this->windowWidth, this->windowHeight, this->windowTitle.c_str());

	SetTargetFPS(this->targetFPS);
}

void Core::Run()
{
	while (!WindowShouldClose())
	{
		Update();

		Draw();
	}
}

void Core::DeInit()
{
	CloseWindow();
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