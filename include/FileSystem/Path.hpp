#pragma once

class File;
class String;

class Path
{
    vector<String> path;
public:
    Path();
    ~Path() noexcept;
    String toString();
    static String getExtension(Path& path);
    static String getExtension(String& path);
};
