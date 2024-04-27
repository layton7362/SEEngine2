#pragma once
#include <Types.hpp>

class Texture : public RessourceType
{
public:
    uvec2 size;
    String path;

public:
    Texture();
    virtual ~Texture() noexcept;
};
