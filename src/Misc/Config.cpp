#include <exception>
#include <string.h>
#include <FileSystem/File.hpp>
#include <Core/Log.hpp>
#include <Global.hpp>
#include <Misc/Config.hpp>

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
        return;
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
    static const char *text = nullptr;
    if (!text)
    {
        text = data["gameTitle"].as_string().c_str();
    }
    return text;
}

const char *Config::renderEngine()
{
    static const char *text = nullptr;
    if (!text)
    {
        text = data["engine"].as_object()["render"].as_string().c_str();
    }
    return text;
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

vec3 Config::temp()
{
    JsonObject obj = data["temp"].as_object();
    double x = obj["x"].as_double();
    double y = obj["y"].as_double();
    double z = obj["z"].as_double();
    return vec3(x,y,z);
}
