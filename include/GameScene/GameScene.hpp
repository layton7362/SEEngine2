#pragma once

#include <Interface.hpp>


class GameScene : public IDisposable
{
protected:
    class SceneTree *tree;

public:
    GameScene(class SceneTree &tree)
    {
        this->tree = &tree;
    }

    virtual ~GameScene() noexcept {};

    virtual void init() = 0;
    virtual void update() = 0;
};