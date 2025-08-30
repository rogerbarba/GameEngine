#pragma once

#include "raylib.h"
#include <string>

class HUD
{
public:
	void drawTextDefault(const std::string& text, int posX, int posY, int fontSize, Color color);
	void drawText(Font font, const std::string& text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint);
};