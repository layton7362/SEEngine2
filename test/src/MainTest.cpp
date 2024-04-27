#include <stdio.h>
#include <Core/Log.hpp>

extern int main_Log(const char *type);
extern int main_String(const char *type);
extern int main_Path(const char *type);


int main()
{
    Log::info("!!!!!Start Tests!!!!!");
    Log::info("=====================");
    main_Log("Log");
    main_String("String");
    main_Path("Path");
    return 0;
}
