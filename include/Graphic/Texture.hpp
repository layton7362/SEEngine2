#pragma once
#include <Types.hpp>
#include <Core/ResourceType.hpp>

class Texture : public ResourceType
{
public:
    uvec2 size;
    String path;
public:
    Texture();
    virtual ~Texture() noexcept;


    void load(String path);
};
