#pragma once

#include <cstring>
#include <iostream>
#include <cstddef>

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

    size_t size() const;
    String &append(const String &other);
    String &append(char c);
    const char *c_str();
    char char_at(size_t pos) const;

    static String convertToString(const float &value);
        static String convertToString(const int &value);

    friend std::ostream &operator<<(std::ostream &os, const String &str);
};
