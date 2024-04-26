#include <exception>
#include <string.h>
#include <Core/File.hpp>
#include <Core/Log.hpp>
#include <Misc/Config.hpp>

Config *config = new Config();
// Config config2;
Config::Config()
{
    Log::info("Create Config.");
    this->read();
    Log::info("Create Config done.");
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
    if (data.empty())
    {
        throw std::invalid_argument("Config Json is empty.");
    }
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

InputNameMap Config::inputMap()
{
    static InputNameMap inputs;

    if (inputs.empty())
    {
        bool istype = (*config)["inputMap"].is_object();
        JsonObject obj = (*config)["inputMap"].as_object();
        auto size_outer = obj.size();
        for (JsonObject::value_type e_im : obj)
        {
            String key = e_im.key().data();
            JsonArray keyCodes = e_im.value().as_array();

            vector<unsigned int> valueVec(keyCodes.size());
            for (unsigned int i = 0; i < keyCodes.size(); i++)
            {
                auto val = keyCodes[i].as_int64();
                valueVec[i] = keyCodes.at(i).as_int64();
            }
            inputs.insert(std::make_pair(key, valueVec));
        }
    }
    return inputs;
}