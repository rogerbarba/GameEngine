#include "SceneManager.hpp"

void SceneManager::changeScene(Scene* scene)
{
    if (currentScene)
    {
        delete currentScene;
    }

    currentScene = scene;
}

void SceneManager::update()
{
    currentScene->update();
}

void SceneManager::draw()
{
    currentScene->draw();
}

SceneManager::~SceneManager()
{
    if (currentScene)
    {
        delete currentScene;

        currentScene = nullptr;
    }
}