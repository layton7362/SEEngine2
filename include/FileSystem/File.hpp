#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <Core/String.hpp>
#include <Core/Log.hpp>

struct FileData
{
    String data;
    String path;
    bool success;
};

class File
{
private:
    // Verhindert den Standardkonstruktor
    File() {}

    // Verhindert den Destruktor
    ~File() {}

public:
    static FileData readFile(const char *path)
    {
        std::ifstream file(path);
        if (!file.is_open())
        {
            return FileData{"", path, false};
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        std::string content = buffer.str();

        char *result = new char[content.size() + 1];
        std::copy(content.begin(), content.end(), result);
        result[content.size()] = '\0'; 

        return FileData{result, path, true};
    }

    static bool write(const char *path, const char *content)
    {
        std::ofstream file(path);
        if (!file.is_open())
        {
            std::cerr << "Error: Could not open file " << path << " for writing" << std::endl;
            return false;
        }

        try
        {
            file << content; // Inhalt in die Datei schreiben
            file.close();
            return true;
        }
        catch (...)
        {
            file.close();
            throw; // Wirf die Ausnahme erneut, um die Fehlerbehandlung zu delegieren
        }
    }
};
