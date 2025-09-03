options.windowWidth = 800
options.windowHeight = 600
options.windowTitle = "This is the first window with Lua and Sol2"
options.targetFPS = 60

function MenuSceneInit()
	print("MenuScene started")
end

function MenuSceneUpdate()
	print("MenuScene is being updated at 60 FPS");
end

function MenuSceneDraw()
    print("MenuScene is being drawed at 60 FPS");
end

function MenuSceneDeInit()
    print("Menu scene ended")
end