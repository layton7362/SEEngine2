#pragma once

#define isSubclass(base, class) dynamic_cast<base*>(class) != nullptr
#define checkIsSubclass(base, class) static_assert(std::is_base_of<base, class>::value, "Ressource: R must be a subclass of RessourceType");
#define toSubclass(base, class) dynamic_cast<base*>(class)

#define DisposeAndDelete(obj) \
    if (obj != nullptr)       \
    {                         \
        obj->dispose();       \
        delete obj;           \
        obj = nullptr;        \
    }

template <typename T>
inline static bool isBetween(T val ,float max, float min = 0){
    return  val >= min && val <= max;
}
