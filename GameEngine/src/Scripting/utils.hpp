#pragma once

#include "raylib.h"

struct Utils
{
	int getScreenWidth()
	{
		return GetScreenWidth();
	}

	int getScreenHeight()
	{
		return GetScreenHeight();
	}

	float getFrameTime()
	{
		return GetFrameTime();
	}
};