#include <Core/Thread.hpp>
#include <Core/Log.hpp>

Thread::Thread()
{
}

Thread::~Thread()
{
}

void Thread::run()
{
    
    if (!program)
    {
        Log::warning("Try to start a empty Thread.");
        return;
    }

    program();
}