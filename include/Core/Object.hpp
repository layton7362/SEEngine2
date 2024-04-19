#pragma once

#include <Interface.hpp>

class Object: public IDisposable{
    
public:
    Object();
    virtual ~Object() noexcept; 
    virtual void dispose(){};
};
