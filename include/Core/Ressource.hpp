#pragma once

#include <stdexcept>
#include <Core/RessourceType.hpp>
#include <Core/Ressource.hpp>
#include <type_traits>
#include<Core/Log.hpp>

template <class R>
class Ressource
{
    friend class RessourceManager;
private:
    R *resType = nullptr;
    int *counter = nullptr;

public:
    Ressource();
    Ressource(Ressource<R> &ressource);

    virtual ~Ressource() noexcept;
    bool isValid();
    R get();

    R *operator->() const { return this->resType; }
    R &operator*() const { return *this->resTypec; }
};

template <class R>
Ressource<R>::Ressource()
{
    static_assert(std::is_base_of<RessourceType, R>::value, "Ressource: R must be a subclass of RessourceType");
    this->resType = new R();
    this->counter = new int{1};
}

template <class R>
Ressource<R>::Ressource(Ressource<R>& ressource)
{
    if (&ressource != nullptr)
    {
        this->resType = ressource.resType;
        this->counter = ressource.counter;
        *(this->counter) += 1;
    }
}

template <class R>
Ressource<R>::~Ressource() noexcept
{
    *(this->counter) = *(this->counter) - 1;
    if (*(this->counter) <= 0)
    {
        delete this->counter;
        delete this->resType;

        this->resType = nullptr;
        this->counter = nullptr;
    }
}
template <class R>
bool Ressource<R>::isValid()
{
    return this->resType != nullptr;
}

template <class R>
R Ressource<R>::get()
{
    return this->resType;
}
