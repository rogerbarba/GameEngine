#include "../../SceneManager.hpp"
#include "GameScene.hpp"

GameScene::GameScene(Input& input, EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, Scripting& scripting)
	: Scene(entityManager, renderer, cameraSystem, scripting), input(input) { }

void GameScene::init()
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
	renderer.render(entityManager, cameraSystem.getCamera());

	if (paused)
	{
		// draw pause overlay
	}
}

void GameScene::deInit()
{
	// ...
}