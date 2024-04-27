#include <Core/String.hpp>
#include <string>


String::String() : data(nullptr), length(0)
{
}

String::String(const char *str) : data(nullptr), length(strlen(str))
{
    this->data = new char[this->length + 1];
    strcpy(this->data, str);
}

String::String(const String &other) : data(nullptr), length(other.length)
{
    data = new char[length + 1];
    strcpy(data, other.data);
}

String::String(const float &other) : String(convertToString(other))
{
}

String::String(const int &other) : String(convertToString(other))
{
}

String::~String()
{
    delete[] data;
}

String::operator const char *() const
{
    return data;
}

bool String::operator==(const String &other) const
{
    return this == &other || strcmp(this->data, other.data) == 0;
}

bool String::operator==(const char *other) const
{
    return strcmp(this->data, other) == 0;
}

bool String::operator!=(const String &other) const
{
    return strcmp(this->data, other.data) != 0;
}

bool String::operator!=(const char *other) const
{
    return strcmp(this->data, other) != 0;
}

String &String::operator=(const String &other)
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

String &String::operator+=(const String &other)
{
    this->append(other);
    return *this;
}

String &String::operator+(const String &other)
{
    this->append(other);
    return *this;
}

String &String::operator+(char other)
{
    this->append(other);
    return *this;
}

bool String::operator<(const String &other) const
{
    return std::strcmp(data, other.data) < 0;
}

size_t String::size() const
{
    return length;
}

const char *String::c_str()
{
    return data;
}

String &String::append(const String &other)
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

String &String::append(char c)
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

vector<String> String::split(const char *delimiter)
{
    vector<String> result;
    size_t pos = 0;
    std::string str = this->data;
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        result.push_back(str.substr(0, pos).c_str());
        str.erase(0, pos + std::strlen(delimiter));
    }
    result.push_back(data); 
    return result;
}

String String::convertToString(const float &value)
{
    std::string str = std::to_string(value);
    return String(str.c_str());
}

String String::convertToString(const int &value)
{
    std::string str = std::to_string(value);
    return String(str.c_str());
}

char String::char_at(size_t pos) const
{
    if (pos >= length)
    {
        return '\0';
    }
    return data[pos];
}

std::ostream &operator<<(std::ostream &os, const String &str)
{
    os << str.data;
    return os;
}
