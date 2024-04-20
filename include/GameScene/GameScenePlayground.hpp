#pragma once
#include <GameScene/GameScene.hpp>

class Object3D;

class GameScenePlayground : public GameScene
{
private:
    Object3D *player;
    Object3D *obj;

public:
    GameScenePlayground(SceneTree &tree);

    virtual void init() override;
    virtual void update(const float &delta) override;
    virtual void dispose() override;
};
