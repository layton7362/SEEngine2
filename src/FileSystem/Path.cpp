
#include <filesystem>
#include <Types.hpp>
#include <FileSystem/Path.hpp>

Path::Path()
{

}

Path::Path(String path)
{
}

Path::~Path()
{
}

String Path::toString()
{
    String res = "";
    for (String &substr : data)
    {   
        res += substr + "/" ;
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

Path Path::currentPath()
{   
    using  std::filesystem::current_path;
    String str  = current_path().string().c_str();
    Path path;
    path.data = str.split("\\");
    return path;
}