#pragma once
#include <map>
#include <vector>
#include "JsonUtil.hpp"
#include <Types.hpp>

using std::map;
using std::vector;

struct StringComparator {
    bool operator()(const String& str1, const String& str2) const {
        return str1 < str2; 
    }
};

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
};

extern Config *config;