#pragma once

#include "raylib.h"

class CollisionSystem
{
public:
    bool checkCollisionRecs(Rectangle rec1, Rectangle rec2);
    bool checkCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);
    bool checkCollisionCircleRec(Vector2 center, float radius, Rectangle rec);
    Rectangle getCollisionRec(Rectangle rec1, Rectangle rec2);
};