#pragma once

#include "raylib.h"
#include <string>

struct Options
{
	int windowWidth;
	int windowHeight;
	std::string windowTitle;
	int targetFPS;
	Color bgColor;
};