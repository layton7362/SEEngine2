#pragma once

#include <Misc/Config.hpp>
#include <Types.hpp>

struct KeyCode
{
    enum Type
    {
        SPACE = 32,

        ASTERISK = 42,
        PLUS = 43,
        MINUS = 45,
        SLASH = 47,

        NUMBER_0 = 48,
        NUMBER_1 = 49,
        NUMBER_2 = 50,
        NUMBER_3 = 51,
        NUMBER_4 = 52,
        NUMBER_5 = 53,
        NUMBER_6 = 54,
        NUMBER_7 = 55,
        NUMBER_8 = 56,
        NUMBER_9 = 57,

        A = 65,
        B = 66,
        C = 67,
        D = 68,
        E = 69,
        F = 70,
        G = 71,
        H = 72,
        I = 73,
        J = 74,
        K = 75,
        L = 76,
        M = 77,
        N = 78,
        O = 79,
        P = 80,
        Q = 81,
        R = 82,
        S = 83,
        T = 84,
        U = 85,
        V = 86,
        W = 87,
        X = 88,
        Y = 89,
        Z = 90,

        ENTER = 257,
        BACKSPACE  = 259,
        
        DEL = 261,
        ARROW_RIGHT = 262,
        ARROW_LEFT = 263,
        ARROW_DOWN = 264,
        ARROW_UP = 265,

        NUMBER_BLOCK_0 = 320,
        NUMBER_BLOCK_1,
        NUMBER_BLOCK_2,
        NUMBER_BLOCK_3,
        NUMBER_BLOCK_4,
        NUMBER_BLOCK_5,
        NUMBER_BLOCK_6,
        NUMBER_BLOCK_7,
        NUMBER_BLOCK_8,
        NUMBER_BLOCK_9,
        NUMBER_BLOCK_COMMA = 330,
        NUMBER_BLOCK_DIVICE = 330,
        NUMBER_BLOCK_MULTI = 330,
        NUMBER_BLOCK_MINUX = 333,
        NUMBER_BLOCK_PLUS,
        NUMBER_BLOCK_ENTER,


        F1 = 290,
        F2 = 291,
        F3 = 292,
        F4 = 293,
        F5 = 294,
        F6 = 295,
        F7 = 296,
        F8 = 297,
        F9 = 298,
        F10 = 299,
        F11 = 300,
        F12 = 301,

    };
    enum Mod
    {
        SHIFT = 340,
        CTRL = 341,
        ALT = 342,
    };
};


#define MAX 400
class InputManager final 
{
public:
    bool pressedKeys[MAX] {false};
    bool previousKeys[MAX]{false};

    InputNameMap inputNames;

public:
    bool isPressed(int keyCode);
    bool isPressed(String name);
    bool isJustPressed(int keyCode);
    bool isReleased(int keyCode);

    InputManager();
    ~InputManager() noexcept;
};

extern InputManager* Input;