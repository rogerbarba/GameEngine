#include "MenuScene.hpp"
#include "../../SceneManager.hpp"
#include "../GameScene/GameScene.hpp"
#include <iostream>

MenuScene::MenuScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager)
	: Scene(input, resourceManager, sceneManager)
{
	/*std::cout << "currentScene: MenuScene" << std::endl;
	
	resourceManager.loadTexture("astronaut", "assets/astronaut.jpg");*/
}

void MenuScene::update()
{
	/*Texture2D& astronautTexture = resourceManager.getTexture("astronaut");

	if (input.isKeyPressed(KEY_ONE))
	{
		sceneManager.changeScene(new GameScene(this->input, this->resourceManager, this->sceneManager));
	}*/
}

void MenuScene::draw()
{
	// ...
}

MenuScene::~MenuScene()
{
	// ...
}