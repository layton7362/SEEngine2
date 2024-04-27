#pragma once

class File;
class String;

class Path
{
    vector<String> data;
public:
    Path();
    Path(String path);
    ~Path() noexcept;
    String toString();
    static String getExtension(Path& path);
    static String getExtension(String& path);

    static Path currentPath();
};
