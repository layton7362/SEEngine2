#pragma once

#include <GameScene/GameScene.hpp>

class GameScenePlayground : public GameScene
{

public:
    GameScenePlayground(SceneTree &tree);

    virtual void init() override;
    virtual void update(const float& delta ) override;
    virtual void dispose() override;
};
