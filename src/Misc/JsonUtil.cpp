#include <Misc/JsonUtil.hpp>

#include <boost/json/src.hpp>


const char *JsonUtil::toString(JsonObject &json_data)
{
    auto d = boost::json::serialize(json_data);
    return boost::json::serialize(json_data).c_str();
}

const char *JsonUtil::toString(JsonArray &json_data)
{
    return boost::json::serialize(json_data).c_str();
}

const char *JsonUtil::toString(JsonString &json_data)
{
    return boost::json::serialize(json_data).c_str();
}

const char *JsonUtil::toString(JsonValue &json_data)
{
    return boost::json::serialize(json_data).c_str();
}

JsonValue JsonUtil::toJson(const char *c_string)
{
    return boost::json::parse(c_string);
}