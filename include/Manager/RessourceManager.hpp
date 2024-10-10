#pragma once

#include <Types.hpp>
#include <Utils.hpp>
#include <Structs.hpp>
#include <Core/Log.hpp>
#include <Core/Ressource.hpp>

class RessourceErrorCode
{
public:
    enum Type
    {
        OK = 0,
        RESSOURCE_COULD_NOT_BE_FREED = 1,
        RESSOURCE_COULD_NOT_BE_LOAD = 2,
        RESSOURCE_COULD_NOT_BE_SAVE = 3,
    };

private:
    RessourceErrorCode() = delete;
    ~RessourceErrorCode() = delete;
};

class RessourceExt
{
    inline static const char* Mesh = "mesh";
    inline static const char* Material = "material";
    inline static const char* VShader = "vs";
    inline static const char* FShader = "fs";
};

class RessourceManager
{
private:
    RessourceManager() = delete;
    virtual ~RessourceManager() = delete;

public:
    template <typename R>
    static ResultInt<R> load(StringUnique res);

    template <typename R>
    static RessourceErrorCode::Type save(Ressource<R> &);

private:
    template <typename R>
    static RessourceErrorCode::Type free(Ressource<R> &);
};

template <typename R>
ResultInt<R> RessourceManager::load(StringUnique resPath)
{
    checkIsSubclass(RessourceType, R)
    R obj;
    return {obj, RessourceErrorCode::OK};
}

template <typename R>
RessourceErrorCode::Type RessourceManager::save(Ressource<R> &res)
{
    checkIsSubclass(RessourceType, R)
    return RessourceErrorCode::OK;
}

template <typename R>
RessourceErrorCode::Type RessourceManager::free(Ressource<R> &res)
{
    checkIsSubclass(RessourceType, R) if (*(res.counter) == 0 && res.resType != nullptr)
    {
        delete res.resType;
        return RessourceErrorCode::OK;
    }
    Log::warning("Ressource Could not be freed!");
    return RessourceErrorCode::RESSOURCE_COULD_NOT_BE_FREED;
}
