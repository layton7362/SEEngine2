#pragma once

#include <stdexcept>
#include <type_traits>

#include <Core/Log.hpp>
#include <Utils.hpp>
#include <Core/ResourceType.hpp>

template <class R>
class Resource
{
    static_assert(!std::is_pointer<R>::value, "Must not be a pointer.");

    friend class ResourceManager;

private:
    R *resType = nullptr;
    bool init = false;

public:
    const char *name = "";

    Resource()
    {
    }

    template <typename T>
    Resource(Resource<T> &ressource)
    {
        if (&ressource != nullptr)
        {
            this->resType = ressource.resType;
            this->resType->increaseCounter();
            init = true;
        }
    }

    ~Resource() noexcept
    {
        if (!init)
        {
            return;
        }
        this->resType->decreaseCounter();
        if (this->resType->getCounter() <= 0)
        {
            delete this->resType;
            this->resType = nullptr;
            init = false;
        }
    }

    R *operator->() const
    {
        return this->resType;
    }

    R &operator*() const
    {
        return *this->resTypec;
    }

    template <typename Sub>
    Resource<R> &operator=(Resource<Sub> &other)
    {
        this->set(other.get());
        return *this;
    }

    template <typename Sub>
    Resource<R> &operator=(Resource<Sub> &&other)
    {
        this->set(other.get());
        return *this;
    }

    bool isValid()
    {
        return this->resType != nullptr;
    }

    R *get()
    {
        return this->resType;
    }

    template <typename S>
    void set(S *newResType)
    {
        checkIsSubclass(R, S);
        isNullptrRetVoid(newResType);
        if (!isNullptr(this->resType))
        {
            this->resType->decreaseCounter();
            if (this->resType->getCounter() <= 0)
            {
                delete this->resType;
                this->resType = nullptr;
                init = false;
            }
        }
        this->resType = newResType;
        this->resType->increaseCounter();
        this->init = true;
    }

    void clearUnsafe()
    {
        init = false;
        resType = nullptr;
    }

    template <typename Sub>
    Sub *toSubtype()
    {
        return dynamic_cast<Sub *>(this->resType);
    }
    
    template <typename Sub>
    Sub *as()
    {
        return dynamic_cast<Sub *>(this->resType);
    }

    inline static Resource<R> create()
    {
        R *data = new R();
        Resource<R> res;
        res.set(data);
        return res;
    }

    template <typename Sub>
    inline static Resource<R> create()
    {
        checkIsSubclass(R, Sub);
        R *data = new Sub();
        Resource<R> res;
        res.set(data);
        return res;
    }
};

template <typename R>
using Res = Resource<R>;
