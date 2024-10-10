#include <Core/RessourceType.hpp>
#include <Utils.hpp>

RessourceType::RessourceType()
{
}

RessourceType::~RessourceType()
{
    
}

void RessourceType::increaseCounter()
{
    instance_counter++;
}
void RessourceType::decreaseCounter()
{
    checkIsConditionOk(instance_counter > 0, "instance_counter must be > 0!")
    instance_counter--;
}

unsigned int RessourceType::getCounter()
{
    return this->instance_counter;
}
