#include <Core/RessourceType.hpp>
#include <Core/Ressource.hpp>


Ressource::Ressource(RessourceType* res)
{

}

Ressource::~Ressource() noexcept
{
    delete res;
}

