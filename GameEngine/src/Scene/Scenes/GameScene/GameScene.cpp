#include "GameScene.hpp"
#include "../../SceneManager.hpp"
#include "../MenuScene/MenuScene.hpp"
#include <iostream>

GameScene::GameScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager)
	: Scene(input, resourceManager, sceneManager, entityManager)
{
	// ...
}

void GameScene::update()
{
	// ...
}

void GameScene::draw()
{
	// ...
}

GameScene::~GameScene()
{
	// ...
}