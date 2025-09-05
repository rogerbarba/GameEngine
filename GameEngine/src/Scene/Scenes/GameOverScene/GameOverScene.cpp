#include "../../SceneManager.hpp"
#include "GameOverScene.hpp"

GameOverScene::GameOverScene(EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, Scripting& scripting)
	: Scene(entityManager, renderer, cameraSystem, scripting) { }

void GameOverScene::init()
{
	sol::function initFunction = scripting.getLua()["GameOverSceneInit"];
	if (initFunction.valid())
	{
		initFunction();
	}
}

void GameOverScene::update()
{
	sol::function updateFunction = scripting.getLua()["GameOverSceneUpdate"];
	if (updateFunction.valid())
	{
		updateFunction();
	}
}

void GameOverScene::draw()
{
	renderer.render(entityManager, cameraSystem.getCamera());

	sol::function drawFunction = scripting.getLua()["GameOverSceneDraw"];
	if (drawFunction.valid())
	{
		drawFunction();
	}
}

void GameOverScene::deInit()
{
	sol::function deInitFunction = scripting.getLua()["GameOverSceneDeInit"];
	if (deInitFunction.valid())
	{
		deInitFunction();
	}
}