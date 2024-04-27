#pragma once

class File;
class String;

class Path
{
public:
    Path();
    virtual ~Path() noexcept;
    String toString(Path&);
    static String getExtension(Path& path);
    static String getExtension(String& path);
};
