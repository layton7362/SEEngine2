#include <algorithm>
#include <Utils.hpp>
#include <Manager/InputManager.hpp>
#include <Core/Log.hpp>

InputManager::InputManager()
{
    Log::info("Create InputManager");
    inputNames = config->inputMap();
    Log::info("Create InputManager Done");
}

InputManager::~InputManager()
{
}

bool InputManager::isPressed(int keyCode)
{
    if (isBetween(keyCode, MAX, 0))
    {
        return pressedKeys[keyCode];
    }
    return false;
}

bool InputManager::isPressed(String name)
{
    // auto result = inputNames.insert(std::make_pair("name", 0));
    if (inputNames.find(name) == inputNames.end())
    {
        return false;
    }
    for (auto &keyCode : inputNames[name])
    {
        if (isPressed(keyCode))
        {
            return true;
        }
    }
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