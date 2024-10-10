#pragma once

#include <thread>

class Thread: public std::thread
{
    void (*program)();
    
public:
    Thread();
    virtual ~Thread() noexcept;

    void run();
};
