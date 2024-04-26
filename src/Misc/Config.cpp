#include <Core/File.hpp>
#include <Core/Log.hpp>
#include <exception>
#include <Misc/Config.hpp>

Config::Config()
{
    read();
}

Config::~Config()
{
}

void Config::read()
{
    FileData fileData = File::readFile("_res/config.json");
    if (!fileData.success)
    {
        Log::error("Could not load Config!");
    }
    JsonValue value = JsonUtil::toJson(fileData.data);
    data = value.as_object();
}

JsonValue Config::operator[](const char *key)
{
    JsonValue *result = data.if_contains(key);
    if (!result)
    {
        throw std::invalid_argument("Wrong key in Config Json.");
    }
    return *result;
}

double Config::fps()
{
    return data["fps"].as_double();
}

const char *Config::gameTitle()
{
    static const char *gt = nullptr;
    if (!gt)
    {
        gt = data["gameTitle"].as_string().c_str();
    }
    return gt;
}

uvec2 Config::windowSize()
{
    static uvec2 size = uvec2(-1, -1);
    if (size == uvec2(-1, -1))
    {
        size.x = data["window"].as_object()["width"].as_int64();
        size.y = data["window"].as_object()["height"].as_int64();
    }
    return size;
}
