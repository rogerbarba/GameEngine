#include "Renderer.hpp"

void Renderer::render(EntityManager& entityManager, Camera2D camera, Options& options)
{
	ClearBackground(options.bgColor);

	BeginMode2D(camera);

	// Sprites
	std::vector<Entity> entitiesWithTransformAndSprite = entityManager.getEntitiesWithTransformAndSprite();
	for (const Entity& e : entitiesWithTransformAndSprite)
	{
		TransformComponent* transform = entityManager.getTransform(e);
		Sprite* sprite = entityManager.getSprite(e);

		Rectangle dest = {
			transform->position.x,
			transform->position.y,
			sprite->source.width * transform->scale.x,
			sprite->source.height * transform->scale.y
		};

		Vector2 origin = { 0, 0 };

		DrawTexturePro(*sprite->texture, sprite->source, dest, origin, transform->rotation, sprite->tint);
	}

	// Rectangles
	std::vector<Entity> entitiesWithTransformAndRectangle = entityManager.getEntitiesWithTransformAndRectangle();
	for (const Entity& e : entitiesWithTransformAndRectangle)
	{
		TransformComponent* transform = entityManager.getTransform(e);
		RectangleShape* rectangle = entityManager.getRectangle(e);

		Rectangle rec = {
			transform->position.x,
			transform->position.y,
			rectangle->width* transform->scale.x,
			rectangle->height* transform->scale.y
		};

		Vector2 origin = { 0, 0 };

		DrawRectanglePro(rec, origin, transform->rotation, rectangle->color);
	}

	// Circles
	std::vector<Entity> entitiesWithTransformAndCircle = entityManager.getEntitiesWithTransformAndCircle();
	for (const Entity& e : entitiesWithTransformAndCircle)
	{
		TransformComponent* transform = entityManager.getTransform(e);
		CircleShape* circle = entityManager.getCircle(e);

		DrawCircleV(transform->position, circle->radius * transform->scale.x, circle->color);
	}

	EndMode2D();
}