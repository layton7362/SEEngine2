#include <Utils.hpp>
#include <Manager/InputManager.hpp>

bool InputManager::isPressed(int keyCode)
{
    if (isBetween(keyCode, MAX, 0))
    {
        return pressedKeys[keyCode];
    }
    return false;
}

bool InputManager::isPressed(const char *name)
{
    return false;
}

bool InputManager::isJustPressed(int keyCode)
{
    if (isBetween(keyCode, MAX, 0))
    {
        return !previousKeys[keyCode] && pressedKeys[keyCode];
    }
    return false;
}

bool InputManager::isReleased(int keyCode)
{
    if (isBetween(keyCode, MAX, 0))
    {
        return previousKeys[keyCode] && !pressedKeys[keyCode];
    }
    return false;
}