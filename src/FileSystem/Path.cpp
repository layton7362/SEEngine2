#include <Types.hpp>
#include <FileSystem/Path.hpp>

Path::Path()
{
}

Path::~Path()
{
}

String Path::getExtension(Path& path)
{
    return getExtension(path.toString());
}

String Path::getExtension(String& path)
{
    return ""
}