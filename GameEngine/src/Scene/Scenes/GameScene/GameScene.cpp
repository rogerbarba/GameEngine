#include "GameScene.hpp"
#include "../../SceneManager.hpp"
#include "../MenuScene/MenuScene.hpp"
#include <iostream>

GameScene::GameScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager)
	: Scene(input, resourceManager, sceneManager)
{
	/*std::cout << "currentScene: GameScene" << std::endl;*/
}

void GameScene::update()
{
	/*if (input.isKeyPressed(KEY_ONE))
	{
		sceneManager.changeScene(new MenuScene(this->input, this->resourceManager, this->sceneManager));
	}*/
}

void GameScene::draw()
{
	// ...
}

GameScene::~GameScene()
{
	// ...
}