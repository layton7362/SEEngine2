#pragma once
#include <GameScene/GameScene.hpp>

class Object3D;

class GameScenePlayground : public GameScene
{
private:
    Object3D *obj;
    Object3D *obj2;

public:
    GameScenePlayground(SceneTree &tree);

    virtual void init() override;
    virtual void update(const float &delta) override;
    virtual void dispose() override;
};
