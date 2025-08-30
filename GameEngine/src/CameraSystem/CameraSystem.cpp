#include "CameraSystem.hpp"

Camera2D CameraSystem::getCamera()
{
	return this->camera;
}

void CameraSystem::setUpCamera(Vector2 target, Vector2 offset, float rotation, float zoom)
{
	camera.target = target;
	camera.offset = offset;
	camera.rotation = rotation;
	camera.zoom = zoom;
}

void CameraSystem::followTarget(Vector2 target, Vector2 offset)
{
	camera.target = { target.x + offset.x, target.y + offset.y };
}

void CameraSystem::rotate(float deltaDegrees)
{
	camera.rotation += deltaDegrees;
}

void CameraSystem::zoom(float deltaZoom)
{
	camera.zoom += deltaZoom;
}

void CameraSystem::clampRotation(float min, float max)
{
	if (camera.rotation > max) camera.rotation = max;
	else if (camera.rotation < min) camera.rotation = min;
}

void CameraSystem::clampZoom(float min, float max)
{
	if (camera.zoom > max) camera.zoom = max;
	else if (camera.zoom < min) camera.zoom = min;
}