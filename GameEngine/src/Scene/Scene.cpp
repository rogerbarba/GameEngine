#include "Scene.hpp"
#include "SceneManager.hpp"

Scene::Scene(EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, Scripting& scripting, Options& options)
    : entityManager(entityManager), renderer(renderer), cameraSystem(cameraSystem), scripting(scripting), options(options) { }