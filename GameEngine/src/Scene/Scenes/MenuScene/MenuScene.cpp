#include "../../SceneManager.hpp"
#include "MenuScene.hpp"

MenuScene::MenuScene(Input& input, ResourceManager& resourceManager, SceneManager& sceneManager, EntityManager& entityManager, Renderer& renderer, CameraSystem& cameraSystem, HUD& hud, Audio& audio, CollisionSystem& collisionSystem)
	: Scene(input, resourceManager, sceneManager, entityManager, renderer, cameraSystem, hud, audio, collisionSystem)
{
	// Resources
	resourceManager.loadFont("Montserrat", "assets/Montserrat-Regular.otf");
	resourceManager.loadSound("GameBonus", "assets/game-bonus.mp3");
	resourceManager.loadMusic("SultansOfSwing", "assets/sultans-of-swing.mp3");

	// Entities
	Entity box = entityManager.createEntity();
	entityManager.addTransform(box, {
		.position = { 100.0f, 20.0f },
	});
	entityManager.addRectangle(box, {
		.width = 20.0f,
		.height = 40.0f,
		.color = GREEN
	});

	Entity player = entityManager.createEntity();
	entityManager.nameEntity(player, "player");
	entityManager.addTransform(player, {
		.position = { 0.0f, 0.0f },
	});
	entityManager.addRectangle(player, {
		.width = 50.0f,
		.height = 50.0f,
		.color = RED
	});
	
	// Set up camera
	TransformComponent* playerTransform = entityManager.getTransform(player);
	Vector2 target = playerTransform->position;

	Vector2 offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };

	cameraSystem.setUpCamera(target, offset, 0.0f, 1.0f);
}

void MenuScene::update()
{
	Entity player = entityManager.getNamedEntity("player");
	TransformComponent* playerTransform = entityManager.getTransform(player);
	Vector2 target = playerTransform->position;

	if (input.isKeyDown(KEY_RIGHT)) playerTransform->position.x += 2.0f;
	if (input.isKeyDown(KEY_LEFT)) playerTransform->position.x -= 2.0f;
	if (input.isKeyDown(KEY_UP)) playerTransform->position.y -= 2.0f;
	if (input.isKeyDown(KEY_DOWN)) playerTransform->position.y += 2.0f;

	cameraSystem.followTarget(target, { 25.0f, 25.0f });

	Sound gameBonusSound = resourceManager.getSound("GameBonus");
	if (input.isKeyPressed(KEY_Q)) audio.playSound(gameBonusSound);

	Music sultansOfSwingMusic = resourceManager.getMusic("SultansOfSwing");
	if (input.isKeyPressed(KEY_M))
	{
		if (audio.isMusicPlaying(sultansOfSwingMusic)) audio.stopMusic(sultansOfSwingMusic);
		audio.playMusic(sultansOfSwingMusic);
	}
	if (input.isKeyPressed(KEY_P))
	{
		audio.isMusicPlaying(sultansOfSwingMusic) ? audio.pauseMusic(sultansOfSwingMusic) : audio.resumeMusic(sultansOfSwingMusic);
	}
	if (input.isKeyPressed(KEY_O)) audio.stopMusic(sultansOfSwingMusic);

	audio.updateMusic(sultansOfSwingMusic);
}

void MenuScene::draw()
{
	renderer.setBackgroundColor(WHITE);

	renderer.render(entityManager, cameraSystem.getCamera());

	hud.drawTextDefault("Hola, aixo es Raylib.", 20, 20, 24, RED);

	Font montserrat = resourceManager.getFont("Montserrat");
	hud.drawText(montserrat, "This is Montserrat", { 200.0f, 200.0f }, { 0.0f, 0.0f }, 0.0f, 24, 1, BLUE);
}

MenuScene::~MenuScene()
{
	// ...
}