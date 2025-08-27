#include "../../SceneManager.hpp"
#include "MenuScene.hpp"
#include <iostream>

MenuScene::MenuScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager)
	: Scene(input, resourceManager, sceneManager, entityManager)
{
	// Player entity
	Entity player = entityManager.createEntity();
	entityManager.nameEntity(player, "player");
	entityManager.addTransform(player, {
		.position = { 0.0f, 0.0f },
	});
	//entityManager.addSprite(player, {
	//	...
	//});
}

void MenuScene::update()
{
	Entity player = entityManager.getNamedEntity("player");

	TransformComponent* playerTransform = entityManager.getTransform(player);

	std::cout << playerTransform->position.x << std::endl;
}

void MenuScene::draw()
{
	// ...
}

MenuScene::~MenuScene()
{
	// ...
}