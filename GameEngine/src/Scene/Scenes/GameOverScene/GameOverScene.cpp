#include "../../SceneManager.hpp"
#include "GameOverScene.hpp"

GameOverScene::GameOverScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, HUD& hud, Audio& audio)
	: Scene(input, resourceManager, sceneManager, entityManager, renderer, cameraSystem, hud, audio)
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