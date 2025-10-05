-- Options
options.windowWidth = 800
options.windowHeight = 600
options.windowTitle = "Pong Game"
options.targetFPS = 60
options.bgColor = WHITE
options.allowWindowResize = false

-- Resources
local paddleHitSound
local scoreLeftSound
local scoreRightSound
local gameOverSound

-- Entities
local ball
local ballVelocity = Vector2(200.0, 200.0)

local paddleLeft
local paddleRight

-- Variables
local screenWidth
local screenHeight
local screenCenter

local scoreLeft = 0
local scoreRight = 0
local winningScore = 3

-- MenuScene
function MenuSceneInit()
    print("MenuScene started")

    screenWidth = utils:getScreenWidth()
    screenHeight = utils:getScreenHeight()
    screenCenter = Vector2(screenWidth / 2, screenHeight / 2)

    -- Sound effects
    paddleHitSound = resourceManager:loadSound("paddleHit", "assets/paddleHit.mp3")
    scoreLeftSound = resourceManager:loadSound("scoreLeft", "assets/scoreLeft.mp3")
    scoreRightSound = resourceManager:loadSound("scoreRight", "assets/scoreRight.mp3")
    gameOverSound = resourceManager:loadSound("gameOver", "assets/gameOver.mp3")

    -- Camera
    cameraSystem:setUpCamera(screenCenter, screenCenter, 0.0, 1.0)
end

function MenuSceneUpdate()
    if input:isKeyPressed(KEY.P) then
        sceneManager:changeScene(gameScene)
    end
end

function MenuSceneDraw()
    -- Title
    local text = "Treball de Recerca - Pong Game"
    local fontSize = 32
    local textWidth = hud:measureTextDefault(text, fontSize)
    local x = (screenWidth - textWidth) / 2
    local y = screenCenter.y - 150

    hud:drawTextDefault(text, x, y, fontSize, BLACK)

    -- Subtitle
    local text = "Roger Barba"
    local fontSize = 24
    local textWidth = hud:measureTextDefault(text, fontSize)
    local x = (utils:getScreenWidth() - textWidth) / 2
    local y = screenCenter.y - 100

    hud:drawTextDefault(text, x, y, fontSize, GRAY)

    -- Play text
    local text = "- Press 'P' to start the game -"
    local fontSize = 28
    local textWidth = hud:measureTextDefault(text, fontSize)
    local x = (screenWidth - textWidth) / 2
    local y = screenCenter.y

    hud:drawTextDefault(text, x, y, fontSize, BLUE)
end

function MenuSceneDeInit()
    print("MenuScene ended")

    -- ...
end

-- GameScene
function GameSceneInit()
    print("GameScene started")

    -- ball entity
    ball = entityManager:createEntity()
    entityManager:nameEntity(ball, "ball")
    entityManager:addTransform(ball, Transform(screenCenter, 0.0, Vector2(1.0, 1.0)))
    entityManager:addCircle(ball, Circle(16.0, BLUE))
    entityManager:addVelocity(ball, Velocity(ballVelocity))

    -- paddleLeft entity
    paddleLeft = entityManager:createEntity()
    entityManager:nameEntity(paddleLeft, "paddleLeft")
    entityManager:addTransform(paddleLeft, Transform(Vector2(50.0, screenCenter.y), 0.0, Vector2(1.0, 1.0)))
    entityManager:addRectangle(paddleLeft, Rectangle(20.0, 100.0, RED))

    -- paddleRight entity
    paddleRight = entityManager:createEntity()
    entityManager:nameEntity(paddleRight, "paddleRight")
    entityManager:addTransform(paddleRight, Transform(Vector2(screenWidth - 50.0, screenCenter.y), 0.0, Vector2(1.0, 1.0)))
    entityManager:addRectangle(paddleRight, Rectangle(20.0, 100.0, GREEN))

    -- Camera
    cameraSystem:setUpCamera(screenCenter, screenCenter, 0.0, 1.0)
end

function GameSceneUpdate()
    -- Ball movement
    local dt = utils:getFrameTime()
    local transform = entityManager:getTransform(ball)
    local vel = entityManager:getVelocity(ball)

    transform.position.x = transform.position.x + vel.velocity.x * dt
    transform.position.y = transform.position.y + vel.velocity.y * dt

    -- Bouncing with vertical walls
    if transform.position.y - 16 <= 0 or transform.position.y + 16 >= screenHeight then
        vel.velocity.y = -vel.velocity.y
    end

    -- Paddle movement
    local paddleSpeed = 300
    local transformL = entityManager:getTransform(paddleLeft)
    local transformR = entityManager:getTransform(paddleRight)

    -- paddleLeft: W/S
    if input:isKeyDown(KEY.W) then transformL.position.y = transformL.position.y - paddleSpeed * dt end
    if input:isKeyDown(KEY.S) then transformL.position.y = transformL.position.y + paddleSpeed * dt end

    -- paddleRight: Up/Down
    if input:isKeyDown(KEY.UP) then transformR.position.y = transformR.position.y - paddleSpeed * dt end
    if input:isKeyDown(KEY.DOWN) then transformR.position.y = transformR.position.y + paddleSpeed * dt end

    -- Ball–Paddle Collision
    local ballTransform = entityManager:getTransform(ball)
    local ballCircle = entityManager:getCircle(ball)

    local paddleLTrans = entityManager:getTransform(paddleLeft)
    local paddleLRect = entityManager:getRectangle(paddleLeft)
    local paddleRTrans = entityManager:getTransform(paddleRight)
    local paddleRRect = entityManager:getRectangle(paddleRight)

    -- Build rectangles for both paddles
    local leftRec = Rec(paddleLTrans.position.x, paddleLTrans.position.y,
                              paddleLRect.width, paddleLRect.height)
    local rightRec = Rec(paddleRTrans.position.x, paddleRTrans.position.y,
                               paddleRRect.width, paddleRRect.height)

    -- Check collision paddleLeft
    if collisionSystem:checkCollisionCircleRec(ballTransform.position, ballCircle.radius, leftRec) then
        audio:playSound(paddleHitSound)
        vel.velocity.x = -vel.velocity.x
    end

    -- Check collision paddleRight
    if collisionSystem:checkCollisionCircleRec(ballTransform.position, ballCircle.radius, rightRec) then
        audio:playSound(paddleHitSound)
        vel.velocity.x = -vel.velocity.x
    end

    -- Prevent paddles to cross vertical walls
    if transformL.position.y < 0 then
        transformL.position.y = 0
    elseif transformL.position.y + paddleLRect.height > screenHeight then
        transformL.position.y = screenHeight - paddleLRect.height
    end

    if transformR.position.y < 0 then
        transformR.position.y = 0
    elseif transformR.position.y + paddleRRect.height > screenHeight then
        transformR.position.y = screenHeight - paddleRRect.height
    end

    -- Points counter
    if ballTransform.position.x - ballCircle.radius <= 0 then
        -- Right player scores
        scoreRight = scoreRight + 1
        transform.position = Vector2(screenCenter.x, screenCenter.y)
        vel.velocity = Vector2(-ballVelocity.x, ballVelocity.y) -- send ball to the left
        audio:playSound(scoreRightSound)
    elseif ballTransform.position.x + ballCircle.radius >= screenWidth then
        -- Left player scores
        scoreLeft = scoreLeft + 1
        transform.position = Vector2(screenCenter.x, screenCenter.y)
        vel.velocity = Vector2(ballVelocity.x, ballVelocity.y) -- send ball to the right
        audio:playSound(scoreLeftSound)
    end

    if scoreLeft >= winningScore or scoreRight >= winningScore then
        audio:playSound(gameOverSound)
        sceneManager:changeScene(gameOverScene)
    end
end

function GameSceneDraw()
    -- Draw score (centered at top)
    local fontSize = 40
    local textLeft = tostring(scoreLeft)
    local textRight = tostring(scoreRight)

    local textWidthLeft = hud:measureTextDefault(textLeft, fontSize)
    local textWidthRight = hud:measureTextDefault(textRight, fontSize)

    -- Left score
    hud:drawTextDefault(textLeft, screenCenter.x - 100 - textWidthLeft, 20, fontSize, BLACK)
    -- Right score
    hud:drawTextDefault(textRight, screenCenter.x + 100, 20, fontSize, BLACK)
end

function GameSceneDeInit()
    print("GameScene ended")

    if ball then entityManager:destroyEntity(ball) end
    ball = nil
    if paddleLeft then entityManager:destroyEntity(paddleLeft) end
    paddleLeft = nil
    if paddleRight then entityManager:destroyEntity(paddleRight) end
    paddleRight = nil
end

-- GameOverScene
local winnerText = ""
local winnerColor = BLACK

function GameOverSceneInit()
    print("GameOverScene started")

    -- Determine winner
    if scoreLeft > scoreRight then
        winnerText = "Left Player Wins!"
        winnerColor = RED
    elseif scoreRight > scoreLeft then
        winnerText = "Right Player Wins!"
        winnerColor = GREEN
    else
        winnerText = "Draw!"
    end

    -- Camera
    cameraSystem:setUpCamera(screenCenter, screenCenter, 0.0, 1.0)
end

function GameOverSceneUpdate()
    if input:isKeyPressed(KEY.R) then
        -- Reset scores
        scoreLeft = 0
        scoreRight = 0
        -- Go back to game
        sceneManager:changeScene(gameScene)
    end
end

function GameOverSceneDraw()
    local fontSize = 48
    local text = "GAME OVER"
    local textWidth = hud:measureTextDefault(text, fontSize)
    hud:drawTextDefault(text, (screenWidth - textWidth) / 2, screenCenter.y - 100, fontSize, BLACK)

    local winnerFontSize = 32
    local winnerWidth = hud:measureTextDefault(winnerText, winnerFontSize)
    hud:drawTextDefault(winnerText, (screenWidth - winnerWidth) / 2, screenCenter.y, winnerFontSize, winnerColor)

    local restartText = "Press 'R' to play again"
    local restartFontSize = 28
    local restartWidth = hud:measureTextDefault(restartText, restartFontSize)
    hud:drawTextDefault(restartText, (screenWidth - restartWidth) / 2, screenCenter.y + 80, restartFontSize, BLUE)
end

function GameOverSceneDeInit()
    print("GameOverScene ended")
end