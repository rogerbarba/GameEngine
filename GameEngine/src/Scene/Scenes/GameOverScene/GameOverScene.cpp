#include "../../SceneManager.hpp"
#include "GameOverScene.hpp"

GameOverScene::GameOverScene(EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, Scripting& scripting)
	: Scene(entityManager, renderer, cameraSystem, scripting) { }

void GameOverScene::init()
{
	// ...
}

void GameOverScene::update()
{
	// ...
}

void GameOverScene::draw()
{
	renderer.render(entityManager, cameraSystem.getCamera());
}

void GameOverScene::deInit()
{
	// ...
}