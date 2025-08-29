#pragma once

#include "raylib.h"

class Camera
{
private:
	Camera2D camera;
	Vector2 target;
	Vector2 offset;
	float rotation;
	float zoom;
};