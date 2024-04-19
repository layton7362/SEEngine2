#include "Core/Graph.hpp"
#include <algorithm>

bool Node::add_child(Node *child)
{
    if (child->parent != nullptr)
    {
        return false;
    }
    child->parent = this;
    return true;
}

bool Node::remove_child(Node *child)
{
    auto it = std::find(children.begin(), children.end(), child);
    if (it != children.end()) {
        children.erase(it);
        child->parent = nullptr;
        return true; 
    }
    return false; 
}

void Node::enter()
{

}

void Node::update()
{
}

SceneTree::SceneTree()
{
    nodes = vector<Node *>(1000);
}

void SceneTree::init()
{
}
void SceneTree::main_update()
{
}
void SceneTree::physik_update()
{
}
void SceneTree::render_update()
{
}