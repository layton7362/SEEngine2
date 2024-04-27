#pragma once

#include <stdio.h>
#include <Types.hpp>
#include <Nodes/Object3D.hpp>

#define isSubclass(base, class) dynamic_cast<base *>(class) != nullptr
#define checkIsSubclass(base, class) static_assert(std::is_base_of<base, class>::value, "Ressource: R must be a subclass of RessourceType");
#define toSubclass(base, class) dynamic_cast<base *>(class)

#define DisposeAndDelete(obj) \
    if (obj != nullptr)       \
    {                         \
        obj->dispose();       \
        delete obj;           \
        obj = nullptr;        \
    }

template <typename T>
inline static bool isBetween(T val, float max, float min = 0)
{
    return val >= min && val <= max;
}

static bool isBigEndian()
{
    unsigned int num = 1;
    ubyte *ptr = reinterpret_cast<ubyte *>(&num);
    return (ptr[0] == 0);
}

static int convertToInt(byte *buffer, int len)
{
    int a = 0;
    if (!isBigEndian())
        for (int i = 0; i < len; i++)
            ((byte *)&a)[i] = buffer[i];
    else
        for (int i = 0; i < len; i++)
            ((byte *)&a)[3 - i] = buffer[i];
    return a;
}

static void printMatrix(mat4 &m)
{
    printf("%f\t%f\t%f\t%f\n", m[0][0], m[1][0], m[2][0], m[3][0]);
    printf("%f\t%f\t%f\t%f\n", m[0][1], m[1][1], m[2][1], m[3][1]);
    printf("%f\t%f\t%f\t%f\n", m[0][2], m[1][2], m[2][2], m[3][2]);
    printf("%f\t%f\t%f\t%f\n", m[0][3], m[1][3], m[2][3], m[3][3]);
    printf("=====================================================\n");
}


struct StringComparator {
    bool operator()(const String& str1, const String& str2) const {
        return str1 < str2; 
    }
};