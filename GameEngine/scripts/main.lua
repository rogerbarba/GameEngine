options.windowWidth = 800
options.windowHeight = 600
options.windowTitle = "Lua and Sol2"
options.targetFPS = 60

-- MenuScene
function MenuSceneInit()
	print("MenuScene started")
end

function MenuSceneUpdate()
    if input:isKeyPressed(KEY.A) then
        sceneManager:changeScene(gameScene)
    end
end

function MenuSceneDraw()
    -- ...
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
end

function GameSceneDraw()
    -- ...
end

function GameSceneDeInit()
    print("GameScene ended")
end