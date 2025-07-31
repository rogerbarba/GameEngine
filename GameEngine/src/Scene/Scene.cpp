#include "Scene.hpp"
#include "SceneManager.hpp"

Scene::Scene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager)
    : input(input), resourceManager(resourceManager), sceneManager(sceneManager), entityManager(entityManager) { }