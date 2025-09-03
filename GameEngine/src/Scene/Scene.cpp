#include "Scene.hpp"
#include "SceneManager.hpp"

Scene::Scene(EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, Scripting& scripting)
    : entityManager(entityManager), renderer(renderer), cameraSystem(cameraSystem), scripting(scripting) { }