#include "../../SceneManager.hpp"
#include "GameScene.hpp"

GameScene::GameScene(EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, Scripting& scripting)
	: Scene(entityManager, renderer, cameraSystem, scripting) { }

void GameScene::init()
{
	sol::function initFunction = scripting.getLua()["GameSceneInit"];
	if (initFunction.valid())
	{
		initFunction();
	}
}

void GameScene::update()
{
	sol::function updateFunction = scripting.getLua()["GameSceneUpdate"];
	if (updateFunction.valid())
	{
		updateFunction();
	}
}

void GameScene::draw()
{
	renderer.render(entityManager, cameraSystem.getCamera());

	sol::function drawFunction = scripting.getLua()["GameSceneDraw"];
	if (drawFunction.valid())
	{
		drawFunction();
	}
}

void GameScene::deInit()
{
	sol::function deInitFunction = scripting.getLua()["GameSceneDeInit"];
	if (deInitFunction.valid())
	{
		deInitFunction();
	}
}