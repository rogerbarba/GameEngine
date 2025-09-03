#include "../../SceneManager.hpp"
#include "MenuScene.hpp"

MenuScene::MenuScene(EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, Scripting& scripting)
	: Scene(entityManager, renderer, cameraSystem, scripting) { }

void MenuScene::init()
{
	sol::function initFunction = scripting.getLua()["MenuSceneInit"];
	if (initFunction.valid())
	{
		initFunction();
	}
}

void MenuScene::update()
{
	sol::function updateFunction = scripting.getLua()["MenuSceneUpdate"];
	if (updateFunction.valid())
	{
		updateFunction();
	}
}

void MenuScene::draw()
{
	renderer.render(entityManager, cameraSystem.getCamera());

	sol::function drawFunction = scripting.getLua()["MenuSceneDraw"];
	if (drawFunction.valid())
	{
		drawFunction();
	}
}

void MenuScene::deInit()
{
	sol::function deInitFunction = scripting.getLua()["MenuSceneDeInit"];
	if (deInitFunction.valid())
	{
		deInitFunction();
	}
}