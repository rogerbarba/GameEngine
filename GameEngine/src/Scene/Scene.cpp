#include "Scene.hpp"
#include "SceneManager.hpp"

Scene::Scene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager)
    : input(input), resourceManager(resourceManager), sceneManager(sceneManager) { }