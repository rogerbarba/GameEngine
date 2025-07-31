#pragma once

#include "raylib.h"

// Not simply named Component because it interferes with a raylib.h definition
struct TransformComponent
{
	Vector2 position;
	float rotation = 0.0f;
	Vector2 scale = { 1.0f, 1.0f };
};

struct Sprite
{
	Texture2D* texture;
	Rectangle source;
	Color tint = WHITE;
};

struct Velocity
{
	Vector2 velocity;
};

struct Health
{
	int current;
	int max;
};