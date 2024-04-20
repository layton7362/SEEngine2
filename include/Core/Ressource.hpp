#pragma once

class RessourceType;

class Ressource
{
    RessourceType *res;

public:
    Ressource(RessourceType* res);
    virtual ~Ressource() noexcept;
};