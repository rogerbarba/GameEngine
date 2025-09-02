#include "sol/sol.hpp"
#include "../../SceneManager.hpp"
#include "MenuScene.hpp"

MenuScene::MenuScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, HUD& hud, Audio& audio, CollisionSystem& collisionSystem)
	: Scene(input, resourceManager, sceneManager, entityManager, renderer, cameraSystem, hud, audio, collisionSystem)
{
	// Scripting test
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	lua.script_file("scripts/test.lua");
	
	// Resources
	resourceManager.loadSound("gameBonus", "assets/game-bonus.mp3");

	// Entities
	Entity box = entityManager.createEntity();
	entityManager.nameEntity(box, "box");
	entityManager.addTransform(box, {
		.position = { 0.0f, 100.0f },
	});
	entityManager.addRectangle(box, {
		.width = 2000.0f,
		.height = 500.0f,
		.color = GREEN
	});

	Entity player = entityManager.createEntity();
	entityManager.nameEntity(player, "player");
	entityManager.addTransform(player, {
		.position = { 0.0f, -100.0f },
	});
	entityManager.addRectangle(player, {
		.width = 50.0f,
		.height = 50.0f,
		.color = RED
	});
	entityManager.addVelocity(player, {
		.velocity = { 0.0f, 0.0f }
	});
	
	// Set up camera
	TransformComponent* playerTransform = entityManager.getTransform(player);
	Vector2 target = playerTransform->position;

	Vector2 offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };

	cameraSystem.setUpCamera(target, offset, 0.0f, 1.0f);
}

void MenuScene::update()
{
	// Get
	Entity player = entityManager.getNamedEntity("player");
	TransformComponent* playerTransform = entityManager.getTransform(player);
	Velocity* playerVelocity = entityManager.getVelocity(player);
	Rectangle playerRectangle = {
		.x = playerTransform->position.x,
		.y = playerTransform->position.y,
		.width = entityManager.getRectangle(player)->width,
		.height = entityManager.getRectangle(player)->height
	};

	Entity box = entityManager.getNamedEntity("box");
	Rectangle boxRectangle = {
		.x = entityManager.getTransform(box)->position.x,
		.y = entityManager.getTransform(box)->position.y,
		.width = entityManager.getRectangle(box)->width,
		.height = entityManager.getRectangle(box)->height
	};

	Sound gameBonusSound = resourceManager.getSound("gameBonus");

	// Logic
	playerVelocity->velocity.x = 0.0f;
	if (input.isKeyDown(KEY_RIGHT)) playerVelocity->velocity.x = 1.0f;
	if (input.isKeyDown(KEY_LEFT)) playerVelocity->velocity.x = -1.0f;
	if (input.isKeyDown(KEY_UP)) playerVelocity->velocity.y = -10.0f;

	playerVelocity->velocity.y += 0.5f;

	playerTransform->position.x += playerVelocity->velocity.x;
	playerTransform->position.y += playerVelocity->velocity.y;

	cameraSystem.followTarget(playerTransform->position, { 25.0f, 25.0f });

	if (collisionSystem.checkCollisionRecs(playerRectangle, boxRectangle))
	{
		playerTransform->position.y = (boxRectangle.y + 1) - playerRectangle.height;

		playerVelocity->velocity.y = 0.0f;
	}
}

void MenuScene::draw()
{
	renderer.setBackgroundColor(WHITE);

	renderer.render(entityManager, cameraSystem.getCamera());
}

MenuScene::~MenuScene()
{
	// ...
}