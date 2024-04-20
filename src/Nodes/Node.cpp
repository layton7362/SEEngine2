#include <algorithm>

#include <Nodes/Node.hpp>

Node::Node()
{
        
}

Node::~Node()
{
        
}

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
    if (it != children.end())
    {
        children.erase(it);
        child->parent = nullptr;
        return true;
    }
    return false;
}

void Node::enter()
{
}

void Node::update(const float& delta )
{
}