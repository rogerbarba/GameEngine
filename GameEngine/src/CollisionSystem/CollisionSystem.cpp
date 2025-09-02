#include "CollisionSystem.hpp"

bool CollisionSystem::checkCollisionRecs(Rectangle rec1, Rectangle rec2)
{
	return CheckCollisionRecs(rec1, rec2);
}

bool CollisionSystem::checkCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2)
{
	return CheckCollisionCircles(center1, radius1, center2, radius2);
}

bool CollisionSystem::checkCollisionCircleRec(Vector2 center, float radius, Rectangle rec)
{
	return CheckCollisionCircleRec(center, radius, rec);
}

Rectangle CollisionSystem::getCollisionRec(Rectangle rec1, Rectangle rec2)
{
	return GetCollisionRec(rec1, rec2);
}
