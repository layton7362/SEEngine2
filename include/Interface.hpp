#pragma once

class IDisposable
{
public:
    bool disposed = false;
    virtual void dispose() = 0;
};

