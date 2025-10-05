#include "HUD.hpp"

void HUD::drawTextDefault(const std::string& text, float posX, float posY, int fontSize, Color color)
{
	DrawText(text.c_str(), static_cast<int>(posX), static_cast<int>(posY), fontSize, color);
}

void HUD::drawText(Font font, const std::string& text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint)
{
	DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize, spacing, tint);
}

int HUD::measureTextDefault(const char* text, int fontSize)
{
	return MeasureText(text, fontSize);
}

Vector2 HUD::measureText(Font font, const char* text, float fontSize, float spacing)
{
	return MeasureTextEx(font, text, fontSize, spacing);
}