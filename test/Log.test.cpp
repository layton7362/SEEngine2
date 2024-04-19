#include <Core/Log.hpp>
#include <Core/Log.hpp>
#include <Test/Test.hpp>


bool test_log_stack()
{
    Log::push(String("Erste Nachricht"));
    Log::push(String("Zweite Nachricht"));
    RET_IF_CMP_FAIL(Log::get_msg_stack_size(), 2)
    Log::print(Log::info);
    RET_IF_CMP_FAIL(Log::get_msg_stack_size(), 0)
    Log::push(String("Nachricht auf einen leeren stack"));
    RET_IF_CMP_FAIL(Log::get_msg_stack_size(), 1)
    Log::print(Log::info);
    RET_IF_CMP_FAIL(Log::get_msg_stack_size(), 0)

    return true;
}

int main_Log(const char* type)
{
    
    Log::info("====================");
    Log::info(type);
    Log::info("====================");
    assert(test_log_stack());

    Log::info(type);
    Log::info("Test ends successful");
    return 0;
}