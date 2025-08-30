#include "../../SceneManager.hpp"
#include "GameOverScene.hpp"

GameOverScene::GameOverScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem)
	: Scene(input, resourceManager, sceneManager, entityManager, renderer, cameraSystem)
{
	// ...
}

void GameOverScene::update()
{
	// ...
}

void GameOverScene::draw()
{
	// ...
}

GameOverScene::~GameOverScene()
{
	// ...
}