#pragma once

#include "raylib.h"

class Input
{
public:
    // Keys
    bool isKeyPressed(int key);
    bool isKeyDown(int key);
    bool isKeyReleased(int key);
    bool isKeyUp(int key);

    // Mouse buttons
    bool isMouseButtonPressed(int button);
    bool isMouseButtonDown(int button);
    bool isMouseButtonReleased(int button);
    bool isMouseButtonUp(int button);

    // Mouse movement
    int getMouseX();
    int getMouseY();
    Vector2 getMousePosition();
    Vector2 getMouseDelta();
    float getMouseWheelMove();
    Vector2 getMouseWheelMoveV();

    // Mouse control
    void setMousePosition(int x, int y);
    void setMouseOffset(int offsetX, int offsetY);
    void setMouseScale(float scaleX, float scaleY);
    void setMouseCursor(int cursor);
};