#pragma once

#include "Object.hpp"

class RessourceType : public Object
{
    template <typename T>
    friend class Ressource;
    friend class RessourceManager;

protected:
    unsigned int instance_counter = 0;

    void increaseCounter()
    {
        instance_counter++;
    }
    void decreaseCounter()
    {
        instance_counter--;
    }
    unsigned int getCounter()
    {
        return this->instance_counter;
    }

public:
    RessourceType();
    virtual ~RessourceType();
};
