#include "Scene.hpp"
#include "SceneManager.hpp"

Scene::Scene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, HUD& hud)
    : input(input), resourceManager(resourceManager), sceneManager(sceneManager), entityManager(entityManager), renderer(renderer), cameraSystem(cameraSystem), hud(hud) { }