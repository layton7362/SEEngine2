#include <Core/Log.hpp>
#include <Core/Log.hpp>
#include <Test.hpp>


bool test_ToString()
{
    Log::info("ToString Done");
    return true;
}

int main_Path(const char* type)
{
    
    Log::info("====================");
    Log::info(type);
    Log::info("====================");
    assert(test_ToString());

    Log::info(type);
    Log::info("Test ends successful");
    return 0;
}