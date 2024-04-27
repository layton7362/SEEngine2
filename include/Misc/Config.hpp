#pragma once
#include <map>
#include <vector>
#include "JsonUtil.hpp"
#include <Types.hpp>
#include <Utils.hpp>

using std::map;
using std::vector;

using InputNameMap = map<String, vector<unsigned int>, StringComparator>;

class Config
{
    JsonObject data;

public:
    Config();
    virtual ~Config() noexcept;

    JsonValue operator[](const char *key);

    void read();
    double fps();
    const char *gameTitle();
    uvec2 windowSize();
    InputNameMap inputMap();
    vec3 temp();

};

