#pragma once
#include <Types.hpp>
#include <Core/RessourceType.hpp>

class Texture : public RessourceType
{
public:
    uvec2 size;
    String path;

public:
    Texture();
    virtual ~Texture() noexcept;


    void load(String path);
};
