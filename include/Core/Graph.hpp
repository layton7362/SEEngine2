#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Graphic/Mesh.hpp>
#include <Graphic/Material.hpp>
#include <vector>

using std::vector;
using namespace glm;

class Node
{
private:
    vector<Node*> children;
    Node* parent = nullptr;

public:
    bool add_child(Node* child);
    bool remove_child(Node* child);

    virtual void enter();
    virtual void update();
};

class Node3D : public Node
{

protected:
    mat4 transformation;

public:

    void translate(const glm::vec3 &translation)
    {
        transformation = glm::translate(transformation, translation);
    }

    void scale(const glm::vec3 &scale)
    {
        transformation = glm::scale(transformation, scale);
    }

    void rotate(float angle, const glm::vec3 &axis)
    {
        transformation = glm::rotate(transformation, angle, axis);
    }
};

class Object3D : public Node3D
{
protected:
    Mesh *mesh;
    Material *material;
    
public:
};

class SceneTree
{
private:
    vector<Node *> nodes;

public:
    SceneTree();
    ~SceneTree();

    void init();
    void main_update();
    void physik_update();
    void render_update();
};