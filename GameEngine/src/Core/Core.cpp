#include "raylib.h"
#include "Core.hpp"
#include "../Scene/Scenes/MenuScene/MenuScene.hpp"

Core::Core(int windowWidth, int windowHeight, const std::string& windowTitle, int targetFPS)
	: options{ windowWidth, windowHeight, windowTitle, targetFPS } { }

void Core::init()
{
	scripting.init(*this);
	scripting.load();

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	InitWindow(options.windowWidth, options.windowHeight, options.windowTitle.c_str());

	SetTargetFPS(options.targetFPS);

	InitAudioDevice();

	sceneManager.changeScene(new MenuScene(this->entityManager, this->renderer, this->cameraSystem, this->scripting));
}

void Core::deInit()
{
	sceneManager.deInit();

	resourceManager.unloadAll();

	CloseWindow();

	CloseAudioDevice();
}

void Core::run()
{
	while (!WindowShouldClose())
	{
		update();

		draw();
	}
}

void Core::update()
{
	sceneManager.update();
}

void Core::draw()
{
	BeginDrawing();

	sceneManager.draw();

	EndDrawing();
}

void Core::expose(sol::state& lua)
{
	exposeOptions(lua);
	exposeRaylibStructs(lua);
	exposeRaylibColors(lua);
	exposeKeysAndButtons(lua);

	exposeInput(lua);
	exposeResourceManager(lua);
	exposeSceneManager(lua);
	exposeEntityManager(lua);
	exposeRenderer(lua);
	exposeCameraSystem(lua);
	exposeHUD(lua);
	exposeAudio(lua);
	exposeCollisionSystem(lua);
}

void Core::exposeOptions(sol::state& lua)
{
	lua.new_usertype<Options>("Options",
		"windowWidth", &Options::windowWidth,
		"windowHeight", &Options::windowHeight,
		"windowTitle", &Options::windowTitle,
		"targetFPS", &Options::targetFPS
	);

	lua["options"] = &options;
}

void Core::exposeRaylibStructs(sol::state& lua)
{
	// Vector2
	lua.new_usertype<Vector2>("Vector2",
		"x", &Vector2::x,
		"y", &Vector2::y
	);
	lua.set_function("Vector2", [](float x, float y) {
		return Vector2{ x, y };
	});

	// Color
	lua.new_usertype<Color>("Color",
		sol::constructors<Color(), Color(unsigned char, unsigned char, unsigned char, unsigned char)>(),
		"r", &Color::r,
		"g", &Color::g,
		"b", &Color::b,
		"a", &Color::a
	);
	lua.set_function("Color", [](unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
		return Color{ r, g, b, a };
	});

	// Rectangle
	lua.new_usertype<Rectangle>("Rectangle",
		sol::constructors<Rectangle(), Rectangle(float, float, float, float)>(),
		"x", &Rectangle::x,
		"y", &Rectangle::y,
		"width", &Rectangle::width,
		"height", &Rectangle::height
	);
	lua.set_function("Rectangle", [](float x, float y, float width, float height) {
		return Rectangle{ x, y, width, height };
	});

	// Camera2D
	lua.new_usertype<Camera2D>("Camera2D",
		"offset", &Camera2D::offset,
		"target", &Camera2D::target,
		"rotation", &Camera2D::rotation,
		"zoom", &Camera2D::zoom
	);
}

void Core::exposeRaylibColors(sol::state& lua)
{
	lua["LIGHTGRAY"] = LIGHTGRAY;
	lua["GRAY"] = GRAY;
	lua["DARKGRAY"] = DARKGRAY;
	lua["YELLOW"] = YELLOW;
	lua["GOLD"] = GOLD;
	lua["ORANGE"] = ORANGE;
	lua["PINK"] = PINK;
	lua["RED"] = RED;
	lua["MAROON"] = MAROON;
	lua["GREEN"] = GREEN;
	lua["LIME"] = LIME;
	lua["DARKGREEN"] = DARKGREEN;
	lua["SKYBLUE"] = SKYBLUE;
	lua["BLUE"] = BLUE;
	lua["DARKBLUE"] = DARKBLUE;
	lua["PURPLE"] = PURPLE;
	lua["VIOLET"] = VIOLET;
	lua["DARKPURPLE"] = DARKPURPLE;
	lua["BEIGE"] = BEIGE;
	lua["BROWN"] = BROWN;
	lua["DARKBROWN"] = DARKBROWN;
	lua["WHITE"] = WHITE;
	lua["BLACK"] = BLACK;
	lua["BLANK"] = BLANK;
	lua["MAGENTA"] = MAGENTA;
	lua["RAYWHITE"] = RAYWHITE;
}

void Core::exposeKeysAndButtons(sol::state& lua)
{
	// Keyboard keys
	lua["KEY"] = lua.create_table_with(
		"NULL", KEY_NULL, "APOSTROPHE", KEY_APOSTROPHE, "COMMA", KEY_COMMA, "MINUS", KEY_MINUS, "PERIOD", KEY_PERIOD, "SLASH", KEY_SLASH,
		"ZERO", KEY_ZERO, "ONE", KEY_ONE, "TWO", KEY_TWO, "THREE", KEY_THREE, "FOUR", KEY_FOUR, "FIVE", KEY_FIVE, "SIX", KEY_SIX, "SEVEN", KEY_SEVEN,
		"EIGHT", KEY_EIGHT, "NINE", KEY_NINE, "SEMICOLON", KEY_SEMICOLON, "EQUAL", KEY_EQUAL,
		"A", KEY_A, "B", KEY_B, "C", KEY_C, "D", KEY_D, "E", KEY_E, "F", KEY_F, "G", KEY_G, "H", KEY_H, "I", KEY_I, "J", KEY_J,
		"K", KEY_K, "L", KEY_L, "M", KEY_M, "N", KEY_N, "O", KEY_O, "P", KEY_P, "Q", KEY_Q, "R", KEY_R, "S", KEY_S, "T", KEY_T, "U", KEY_U,
		"V", KEY_V, "W", KEY_W, "X", KEY_X, "Y", KEY_Y, "Z", KEY_Z,
		"LEFT_BRACKET", KEY_LEFT_BRACKET, "BACKSLASH", KEY_BACKSLASH, "RIGHT_BRACKET", KEY_RIGHT_BRACKET, "GRAVE", KEY_GRAVE,
		"SPACE", KEY_SPACE, "ESCAPE", KEY_ESCAPE, "ENTER", KEY_ENTER, "TAB", KEY_TAB, "BACKSPACE", KEY_BACKSPACE,
		"INSERT", KEY_INSERT, "DELETE", KEY_DELETE, "RIGHT", KEY_RIGHT, "LEFT", KEY_LEFT, "DOWN", KEY_DOWN, "UP", KEY_UP,
		"PAGE_UP", KEY_PAGE_UP, "PAGE_DOWN", KEY_PAGE_DOWN, "HOME", KEY_HOME, "END", KEY_END,
		"CAPS_LOCK", KEY_CAPS_LOCK, "SCROLL_LOCK", KEY_SCROLL_LOCK, "NUM_LOCK", KEY_NUM_LOCK, "PRINT_SCREEN", KEY_PRINT_SCREEN, "PAUSE", KEY_PAUSE,
		"F1", KEY_F1, "F2", KEY_F2, "F3", KEY_F3, "F4", KEY_F4, "F5", KEY_F5, "F6", KEY_F6, "F7", KEY_F7, "F8", KEY_F8, "F9", KEY_F9,
		"F10", KEY_F10, "F11", KEY_F11, "F12", KEY_F12,
		"LEFT_SHIFT", KEY_LEFT_SHIFT, "LEFT_CONTROL", KEY_LEFT_CONTROL, "LEFT_ALT", KEY_LEFT_ALT, "LEFT_SUPER", KEY_LEFT_SUPER,
		"RIGHT_SHIFT", KEY_RIGHT_SHIFT, "RIGHT_CONTROL", KEY_RIGHT_CONTROL, "RIGHT_ALT", KEY_RIGHT_ALT, "RIGHT_SUPER", KEY_RIGHT_SUPER,
		"KB_MENU", KEY_KB_MENU,
		"KP_0", KEY_KP_0, "KP_1", KEY_KP_1, "KP_2", KEY_KP_2, "KP_3", KEY_KP_3, "KP_4", KEY_KP_4, "KP_5", KEY_KP_5, "KP_6", KEY_KP_6,
		"KP_7", KEY_KP_7, "KP_8", KEY_KP_8, "KP_9", KEY_KP_9, "KP_DECIMAL", KEY_KP_DECIMAL, "KP_DIVIDE", KEY_KP_DIVIDE, "KP_MULTIPLY", KEY_KP_MULTIPLY,
		"KP_SUBTRACT", KEY_KP_SUBTRACT, "KP_ADD", KEY_KP_ADD, "KP_ENTER", KEY_KP_ENTER, "KP_EQUAL", KEY_KP_EQUAL
	);

	// Mouse buttons
	lua["MOUSE_BUTTON"] = lua.create_table_with(
		"LEFT", MOUSE_BUTTON_LEFT, "RIGHT", MOUSE_BUTTON_RIGHT, "MIDDLE", MOUSE_BUTTON_MIDDLE,
		"SIDE", MOUSE_BUTTON_SIDE, "EXTRA", MOUSE_BUTTON_EXTRA, "FORWARD", MOUSE_BUTTON_FORWARD, "BACK", MOUSE_BUTTON_BACK
	);
}

void Core::exposeInput(sol::state& lua)
{
	lua.new_usertype<Input>("Input",
		"isKeyPressed", &Input::isKeyPressed,
		"isKeyDown", &Input::isKeyDown,
		"isKeyReleased", &Input::isKeyReleased,
		"isKeyUp", &Input::isKeyUp

		// TODO ...
	);
}

void Core::exposeResourceManager(sol::state& lua)
{
	// TODO: ...
}

void Core::exposeSceneManager(sol::state& lua)
{
	// TODO: ...
}

void Core::exposeEntityManager(sol::state& lua)
{
	// TODO: ...
}

void Core::exposeRenderer(sol::state& lua)
{
	// TODO: ...
}

void Core::exposeCameraSystem(sol::state& lua)
{
	// TODO: ...
}

void Core::exposeHUD(sol::state& lua)
{
	// TODO: ...
}

void Core::exposeAudio(sol::state& lua)
{
	// TODO: ...
}

void Core::exposeCollisionSystem(sol::state& lua)
{
	// TODO: ...
}


