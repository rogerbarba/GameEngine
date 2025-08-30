#include "HUD.hpp"

void HUD::drawTextDefault(const std::string& text, int posX, int posY, int fontSize, Color color)
{
	DrawText(text.c_str(), posX, posY, fontSize, color);
}

void HUD::drawText(Font font, const std::string& text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint)
{
	DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize, spacing, tint);
}