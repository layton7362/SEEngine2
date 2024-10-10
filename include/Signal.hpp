#pragma once

#include <vector>

using CallbackFn = void(*)(void*args...);

class Signal
{
    
    std::vector<CallbackFn> callbacks;

    void add(CallbackFn fn);   
    void remove(CallbackFn fn);   
    void call(void* args...);

};


