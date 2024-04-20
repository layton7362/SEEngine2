#pragma once

#include <ctime>
#include <string>
#include <iostream>
#include <filesystem>

class System
{
public:
    // TODO FIX
    static const char *getCurrentDirectory()
    {
        std::filesystem::path currentPath = std::filesystem::current_path();
        auto data = currentPath.string().c_str();

        return currentPath.string().c_str();
    }

    static const char *path()
    {
        return "";
    }

    void setPath(const char *path)
    {
    }

    inline static double getTime()
    {
        // auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> seconds = std::chrono::system_clock::now().time_since_epoch();
        return seconds.count();
    }
};
