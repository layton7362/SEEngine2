#include <algorithm> 
#include <Signal.hpp>

void Signal::add(CallbackFn fn)
{
    callbacks.push_back(fn);
}

void Signal::remove(CallbackFn fn)
{
    std::vector<CallbackFn>::iterator it = std::remove(callbacks.begin(), callbacks.end(), fn);
    
    if (it != callbacks.end())
    {
        callbacks.erase(it, callbacks.end());
    }
}

void Signal::call(void* args...)
{
    for (CallbackFn callback : callbacks)
    {
        callback(args);
    }
}
