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
    // Konstruktoren
    String() : data(nullptr), length(0) {}

    String(const char *str) : data(nullptr), length(strlen(str))
    {
        this->data = new char[this->length + 1];
        strcpy(this->data, str);
    }

    const char *c_str()
    {
        return data;
    }

    // void* operator&() = delete;

    // String& operator*() = delete;

    String(const String &other) : data(nullptr), length(other.length)
    {
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Destruktor
    ~String()
    {
        delete[] data;
    }

    // Zuweisungsoperator
    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Getter für die Länge des Strings
    size_t size() const
    {
        return length;
    }

    operator const char *() const
    {
        return data;
    }

    bool operator==(const String &other) const
    {
        return this == &other || strcmp(this->data, other.data) == 0;
    }

    bool operator!=(const String &other) const
    {
        return strcmp(this->data, other.data) != 0;
    }

    bool operator==(const char *other) const
    {
        return strcmp(this->data, other) == 0;
    }

    bool operator!=(const char *other) const
    {
        return strcmp(this->data, other) != 0;
    }

    String &operator+=(const String &other)
    {
        this->append(other);
        return *this;
    }

    String &operator+(const String &other)
    {
        this->append(other);
        return *this;
    }

    String &operator+(char other)
    {
        this->append(other);
        return *this;
    }

    String &append(const String &other)
    {
        size_t newLength = length + other.length;
        char *newData = new char[newLength + 1];
        strcpy(newData, data);
        strcat(newData, other.data);
        delete[] data;
        data = newData;
        length = newLength;
        return *this;
    }

    String &append(char c)
    {
        char *newData = new char[length + 2];
        strcpy(newData, data);
        newData[length] = c;
        newData[length + 1] = '\0';
        delete[] data;
        data = newData;
        length++;
        return *this;
    }

    // Methode zum Zugriff auf ein einzelnes Zeichen
    char char_at(size_t pos) const
    {
        if (pos >= length)
        {
            return '\0'; // Rückgabe von Nullzeichen für ungültige Positionen
        }
        return data[pos];
    }

    // Ausgabeoperator
    friend std::ostream &operator<<(std::ostream &os, const String &str)
    {
        os << str.data;
        return os;
    }

    static String convertToString(const int &value)
    {
        std::string str = std::to_string(value);
        return String(str.c_str());
    }

    static String convertToString(const float &value)
    {
        std::string str = std::to_string(value);
        return String(str.c_str());
    }
};
