#pragma once
#include <vector>
#include <Core/Object.hpp>
#include <Types.hpp>

class Node : public Object
{
private:
    std::vector<Node *> children;

public:
    Node *parent = nullptr;
    String name;
    
    Node();
    virtual ~Node() noexcept;

    bool add_child(Node *child);
    bool remove_child(Node *child);

    virtual void enter();
    virtual void update(const float& delta );
    virtual void dispose() override;
};