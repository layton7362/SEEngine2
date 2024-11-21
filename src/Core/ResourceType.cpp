#include <Core/ResourceType.hpp>
#include <Utils.hpp>

ResourceType::ResourceType()
{
}

ResourceType::~ResourceType()
{
    
}

void ResourceType::increaseCounter()
{
    instance_counter++;
}
void ResourceType::decreaseCounter()
{
    checkIsConditionOk(instance_counter > 0, "instance_counter must be > 0!")
    instance_counter--;
}

unsigned int ResourceType::getCounter()
{
    return this->instance_counter;
}
