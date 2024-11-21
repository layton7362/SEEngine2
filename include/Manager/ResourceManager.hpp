#pragma once

#include <Types.hpp>
#include <Utils.hpp>
#include <Structs.hpp>
#include <Core/Log.hpp>
#include <Core/Resource.hpp>

class ResourceErrorCode
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
    ResourceErrorCode() = delete;
    ~ResourceErrorCode() = delete;
};

class ResourceExt
{
    inline static const char* Mesh = "mesh";
    inline static const char* Material = "material";
    inline static const char* VShader = "vs";
    inline static const char* FShader = "fs";
};

class ResourceManager
{
private:
    ResourceManager() = delete;
    virtual ~ResourceManager() = delete;

public:
    template <typename R>
    static ResultInt<R> load(StringUnique res);

    template <typename R>
    static ResourceErrorCode::Type save(Resource<R> &);

private:
    template <typename R>
    static ResourceErrorCode::Type free(Resource<R> &);
};

template <typename R>
ResultInt<R> ResourceManager::load(StringUnique resPath)
{
    checkIsSubclass(ResourceType, R)
    R obj;
    return {obj, ResourceErrorCode::OK};
}

template <typename R>
ResourceErrorCode::Type ResourceManager::save(Resource<R> &res)
{
    checkIsSubclass(ResourceType, R)
    return ResourceErrorCode::OK;
}

template <typename R>
ResourceErrorCode::Type ResourceManager::free(Resource<R> &res)
{
    checkIsSubclass(ResourceType, R) if (*(res.counter) == 0 && res.resType != nullptr)
    {
        delete res.resType;
        return ResourceErrorCode::OK;
    }
    Log::warning("Resource Could not be freed!");
    return ResourceErrorCode::RESSOURCE_COULD_NOT_BE_FREED;
}
