#include <Nodes/SceneTree.hpp>
#include <GameScene/GameScene.hpp>

GameScene::GameScene(SceneTree &tree)
{
    this->tree = &tree;
}

GameScene::~GameScene() noexcept {

};