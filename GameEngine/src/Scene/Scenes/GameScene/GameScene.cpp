#include "../../SceneManager.hpp"
#include "GameScene.hpp"

GameScene::GameScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager)
	: Scene(input, resourceManager, sceneManager, entityManager)
{
	// ...
}

void GameScene::update()
{
	if (input.isKeyPressed(KEY_ESCAPE))
	{
		paused = !paused;
	}

	if (paused)
	{
		// handle pause menu input logic

		return;
	}

	// ...
}

void GameScene::draw()
{
	// ...

	if (paused)
	{
		// draw pause overlay
	}
}

GameScene::~GameScene()
{
	// ...
}