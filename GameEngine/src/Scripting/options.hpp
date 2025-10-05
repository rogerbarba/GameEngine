#pragma once

#include "raylib.h"
#include <string>

struct Options
{
	int windowWidth = 800;
	int windowHeight = 600;
	std::string windowTitle = "Window";
	int targetFPS = 60;
	Color bgColor = WHITE;
	bool allowWindowResize = false;
};