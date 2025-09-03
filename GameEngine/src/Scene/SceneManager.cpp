#include "SceneManager.hpp"

void SceneManager::changeScene(Scene* scene)
{
    if (currentScene)
    {
        currentScene->deInit();
    }

    currentScene = scene;
    currentScene->init();
}

void SceneManager::init()
{
    if (currentScene)
        currentScene->init();
}

void SceneManager::update()
{
    currentScene->update();
}

void SceneManager::draw()
{
    currentScene->draw();
}

void SceneManager::deInit()
{
    if (currentScene)
    {
        currentScene->deInit();
        delete currentScene;
        currentScene = nullptr;
    }
}