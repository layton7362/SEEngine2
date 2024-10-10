#pragma once

#include "Object.hpp"

class RessourceType : public Object
{
    template <typename R>
    friend class Ressource;
    friend class RessourceManager;

protected:
    unsigned int instance_counter = 0;


public:
    RessourceType();
    virtual ~RessourceType();

    void increaseCounter();
    void decreaseCounter();
    unsigned int getCounter();
};
