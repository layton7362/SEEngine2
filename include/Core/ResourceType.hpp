#pragma once

#include "Object.hpp"

class ResourceType : public Object
{
    template <typename R>
    friend class Resource;
    friend class ResourceManager;

protected:
    unsigned int instance_counter = 0;


public:
    ResourceType();
    virtual ~ResourceType();

    void increaseCounter();
    void decreaseCounter();
    unsigned int getCounter();
};
