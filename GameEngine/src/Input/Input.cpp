#include "Input.hpp"

bool Input::isKeyPressed(int key) { return IsKeyPressed(key); }
bool Input::isKeyDown(int key) { return IsKeyDown(key); }
bool Input::isKeyReleased(int key) { return IsKeyReleased(key); }
bool Input::isKeyUp(int key) { return IsKeyUp(key); }

bool Input::isMouseButtonPressed(int button) { return IsMouseButtonPressed(button); }
bool Input::isMouseButtonDown(int button) { return IsMouseButtonDown(button); }
bool Input::isMouseButtonReleased(int button) { return IsMouseButtonReleased(button); }
bool Input::isMouseButtonUp(int button) { return IsMouseButtonUp(button); }

int Input::getMouseX() { return GetMouseX(); }
int Input::getMouseY() { return GetMouseY(); }
Vector2 Input::getMousePosition() { return GetMousePosition(); }
Vector2 Input::getMouseDelta() { return GetMouseDelta(); }
float Input::getMouseWheelMove() { return GetMouseWheelMove(); }
Vector2 Input::getMouseWheelMoveV() { return GetMouseWheelMoveV(); }

void Input::setMousePosition(int x, int y) { SetMousePosition(x, y); }
void Input::setMouseOffset(int offsetX, int offsetY) { SetMouseOffset(offsetX, offsetY); }
void Input::setMouseScale(float scaleX, float scaleY) { SetMouseScale(scaleX, scaleY); }
void Input::setMouseCursor(int cursor) { SetMouseCursor(cursor); }