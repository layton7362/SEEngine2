#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <list>
#include <Core/String.hpp>

class Log
{

private:
    //  Members

    inline static std::list<String> msg_list;

    //  Members end

    Log() {}
    ~Log() {}

    static void setConsoleColor(const char *color)
    {
        std::cout << "\033[" << color << "m";
    }

public:
    static void push(String str)
    {
        Log::msg_list.push_back(str);
    }

    static void print(void (*log)(const char *))
    {
        for (const String &str : msg_list)
        {
            log(str);
        }
        msg_list.clear();
    }

    static size_t get_msg_stack_size()
    {
        return Log::msg_list.size();
    }

    // Statische Methode zum Schreiben einer Meldung in eine Logdatei
    static void write(const char *message, const char *filename = "log.txt")
    {
        std::ofstream file(filename, std::ios::app); // Datei im Anhänge-Modus öffnen
        if (file.is_open())
        {
            // Aktuelles Datum und Uhrzeit ermitteln
            std::time_t now = std::time(nullptr);
            std::tm *currentTime = std::localtime(&now);
            char timestamp[20];
            std::strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", currentTime);

            // Meldung mit Zeitstempel in die Datei schreiben
            file << timestamp << " " << message << std::endl;
            file.close();
        }
        else
        {
            std::cerr << "Error: Could not open log file " << filename << std::endl;
        }
    }

    // Statische Methode zum Löschen einer Logdatei
    static void clear(const char *filename = "log.txt")
    {
        std::ofstream file(filename, std::ios::trunc); // Datei im Überschreib-Modus öffnen
        if (!file.is_open())
        {
            std::cerr << "Error: Could not open log file " << filename << std::endl;
        }
    }

    static void warning(const char *message)
    {
        setConsoleColor("33");                                          // Gelbe Textfarbe
        std::cout << "[WARNING] " << message << "\033[0m" << std::endl; // Zurücksetzen der Textfarbe
    }

    static void info(const char *message)
    {
        setConsoleColor("32");                                       // Grüne Textfarbe
        std::cout << "[INFO] " << message << "\033[0m" << std::endl; // Zurücksetzen der Textfarbe
    }

    static void error(const char *message)
    {
        setConsoleColor("31");                                        // Rote Textfarbe
        std::cerr << "[ERROR] " << message << "\033[0m" << std::endl; // Zurücksetzen der Textfarbe
    }
};
