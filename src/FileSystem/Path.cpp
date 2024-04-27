#include <Types.hpp>
#include <FileSystem/Path.hpp>

Path::Path()
{
}

Path::~Path()
{
}

String Path::toString()
{
    String res;
    for (String &substr : path)
    {
        res += substr;
    }
    return res;
}

String Path::getExtension(Path &path)
{
    String str = path.toString();
    return getExtension(str);
}

String Path::getExtension(String &path)
{
    vector<String> splitted = path.split(".");
    return splitted[splitted.size() - 1];
}