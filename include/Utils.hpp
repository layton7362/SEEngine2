#pragma once

#define isSubclass(base, class) dynamic_cast<base*>(class) != nullptr

#define ToSubclass(base, class) dynamic_cast<base*>(class)

template <typename T>
inline static bool isBetween(T val ,float max, float min = 0){
    return  val >= min && val <= max;
}

#define DisposeAndDelete(obj) \
    if (obj != nullptr)       \
    {                         \
        obj->dispose();       \
        delete obj;           \
        obj = nullptr;        \
    }

