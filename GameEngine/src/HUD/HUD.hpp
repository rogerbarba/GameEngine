#pragma once

#include "raylib.h"
#include <string>

class HUD
{
public:
	void drawTextDefault(const std::string& text, float posX, float posY, int fontSize, Color color);
	void drawText(Font font, const std::string& text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint);

	int measureTextDefault(const char* text, int fontSize);
	Vector2 measureText(Font font, const char* text, float fontSize, float spacing);
};