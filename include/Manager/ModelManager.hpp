#pragma once

class ModelManager
{
    
public:
    ModelManager();
    virtual ~ModelManager() noexcept;

    void loadModel(const char* path);
};


