#pragma once

#include "raylib.h"

class CameraSystem
{
private:
	Camera2D camera;
	
public:
	Camera2D getCamera();
	
	void setUpCamera(Vector2 target, Vector2 offset, float rotation, float zoom);

	void followTarget(Vector2 target, Vector2 offset);
	void rotate(float deltaDegrees);
	void zoom(float deltaZoom);
	void clampRotation(float min, float max);
	void clampZoom(float min, float max);
};