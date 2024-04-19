#pragma once

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
};