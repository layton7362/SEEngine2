#pragma once

#include <boost/json/object.hpp>
#include <boost/json/array.hpp>
#include <boost/json/array.hpp>
#include <boost/json/value.hpp>

using JsonValue = boost::json::value;
using JsonObject = boost::json::object;
using JsonArray = boost::json::array;
using JsonString = boost::json::string;
// using JsonScalar = boost::json::scalar;

class JsonUtil
{
    JsonUtil() = delete;
    virtual ~JsonUtil() noexcept = delete;

public:
    static const char *toString(JsonObject &);
    static const char *toString(JsonArray &);
    static const char *toString(JsonString &);
    static const char *toString(JsonValue &);
    static JsonValue toJson(const char *);
    static void pretty_print(std::ostream &os, JsonValue const &jv, std::string *indent = nullptr);
};
