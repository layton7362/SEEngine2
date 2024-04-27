#pragma once

#include <cstring>
#include <iostream>
#include <cstddef>
#include <vector>

using std::vector;

class String
{
private:
    char *data;
    size_t length;

public:
    String();
    String(const String &other);
    String(const char *str);
    String(const int &other);
    String(const float &other);
    ~String();

    operator const char *() const;

    bool operator==(const String &other) const;
    bool operator==(const char *other) const;

    bool operator!=(const String &other) const;
    bool operator!=(const char *other) const;

    String &operator=(const String &other);

    String &operator+=(const String &other);

    String &operator+(const String &other);
    String &operator+(char other);
    bool operator<(const String &other) const;

    size_t size() const;
    String &append(const String &other);
    String &append(char c);

    bool contain(String &str) const;
    bool contain(String &&str) const;

    template <typename T1, typename T2>
    String replace(T1 search, T2 replace) const;

    vector<String> split(const char *delimeter) const;

    const char *c_str();
    char char_at(size_t pos) const;

    static String convertToString(const float &value);
    static String convertToString(const int &value);

    friend std::ostream &operator<<(std::ostream &os, const String &str);
};

template <typename T1, typename T2>
String String::replace(T1 search, T2 replace) const
{
    String result(*this);
    size_t searchLen = std::strlen(search);
    size_t replaceLen = std::strlen(replace);

    char *pos = std::strstr(result.data, search);
    while (pos != nullptr)
    {
        std::memmove(pos + replaceLen, pos + searchLen, result.length - (pos - result.data) - searchLen + 1);
        std::memcpy(pos, replace, replaceLen);
        pos = std::strstr(pos + replaceLen, search);
        result.length += (replaceLen - searchLen);
    }

    return result;
}
