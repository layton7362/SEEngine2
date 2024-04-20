#pragma once

#include <vector>
#include <Core/Object.hpp>
    
using std::vector;

class Node : public Object
{
private:
    vector<Node *> children;

public:
    Node *parent = nullptr;

    Node();
    virtual ~Node() noexcept;

    bool add_child(Node *child);
    bool remove_child(Node *child);

    virtual void enter();
    virtual void update(const float& delta );
    virtual void dispose() override{};
};