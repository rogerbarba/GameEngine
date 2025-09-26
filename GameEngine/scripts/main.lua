-- Options
options.windowWidth = 800
options.windowHeight = 600
options.windowTitle = "Lua and Sol2"
options.targetFPS = 60
options.bgColor = WHITE

-- Resources
local astronautTex
local montserratFont
local gameBonusSound
local sultansOfSwingSong

-- Entities
local player
local playerTransform

-- Variables
local musicPlaying = false

-- MenuScene
function MenuSceneInit()
    print("MenuScene started")

    -- Resources
    astronautTex = resourceManager:loadTexture("player", "assets/astronaut.jpg")
    montserratFont = resourceManager:loadFont("montserrat", "assets/Montserrat-Regular.otf")
    gameBonusSound = resourceManager:loadSound("gameBonus", "assets/game-bonus.mp3")
    sultansOfSwingSong = resourceManager:loadMusic("sultansOfSwing", "assets/sultans-of-swing.mp3")

    -- Player entity
    player = entityManager:createEntity()
    entityManager:nameEntity(player, "player")
    entityManager:addTransform(player, Transform(Vector2(400.0, 300.0), 0.0, Vector2(1.0, 1.0)))
    entityManager:addCircle(player, Circle(30.0, RED))

    -- Camera
    playerTransform = entityManager:getTransform(player)
    local playerPosition = playerTransform.position
    cameraSystem:setUpCamera(playerPosition, playerPosition, 0.0, 1.0)
end

function MenuSceneUpdate()
    if input:isKeyPressed(KEY.A) then
        sceneManager:changeScene(gameScene)
    end

    if input:isKeyPressed(KEY.P) then
        audio:playSound(gameBonusSound)
    end
end

function MenuSceneDraw()
    hud:drawText(montserratFont, "We're in MenuScene", Vector2(100, 200), Vector2(0, 0), 0.0, 32.0, 1.0, BLUE)
end

function MenuSceneDeInit()
    print("MenuScene ended")
end

-- GameScene
function GameSceneInit()
    print("GameScene started")
end

function GameSceneUpdate()
    if input:isKeyPressed(KEY.A) then
        sceneManager:changeScene(menuScene)
    end

    if input:isKeyPressed(KEY.P) then
        audio:playMusic(sultansOfSwingSong)
        musicPlaying = true
    end

    audio:updateMusic(sultansOfSwingSong)
end

function GameSceneDraw()
    hud:drawText(montserratFont, "We're in GameScene", Vector2(100, 200), Vector2(0, 0), 0.0, 32.0, 1.0, GREEN)
end

function GameSceneDeInit()
    print("GameScene ended")
end