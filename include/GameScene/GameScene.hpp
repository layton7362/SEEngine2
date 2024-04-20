#pragma once
#include <Interface.hpp>

class SceneTree;

class GameScene : public IDisposable
{
protected:
    SceneTree *tree;

public:
    GameScene(SceneTree &tree);
    virtual ~GameScene() noexcept;

    virtual void init() = 0;
    virtual void update(const float& delta ) = 0;
};