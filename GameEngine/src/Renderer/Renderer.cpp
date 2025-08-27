#include "Renderer.hpp"

void Renderer::render(EntityManager& entityManager)
{
	BeginDrawing();
	
	// Sprites
	std::vector<Entity> entitiesWithTransformAndSprite = entityManager.getEntitiesWithTransformAndSprite();
	for (const Entity& e : entitiesWithTransformAndSprite)
	{
		Sprite* sprite = entityManager.getSprite(e);
		TransformComponent* transform = entityManager.getTransform(e);

		Rectangle dest = {
			transform->position.x,
			transform->position.y,
			sprite->source.width * transform->scale.x,
			sprite->source.height * transform->scale.y
		};

		Vector2 origin = { 0, 0 };

		DrawTexturePro(*sprite->texture, sprite->source, dest, origin, transform->rotation, sprite->tint);
	}

	// ...

	// ... also apply camera and HUD

	EndDrawing();
}