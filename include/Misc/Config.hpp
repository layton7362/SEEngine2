#pragma once

#include "JsonUtil.hpp"
#include <Types.hpp>

class Config
{
    JsonObject data;

public:
    Config();
    virtual ~Config() noexcept;

    void read();
    JsonValue operator[](const char *key);
    double fps();
    const char* gameTitle();
    uvec2 windowSize();
};

static Config config;