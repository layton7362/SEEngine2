#pragma once

class Object
{
public:
    virtual ~Object() noexcept;
};

class Resource : public Object
{
public:
    
    virtual ~Resource() noexcept;
};