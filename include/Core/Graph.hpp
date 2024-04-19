#include <vector>
#include <glm/glm.hpp>
#include <Graphic/Mesh.hpp>
#include <Graphic/Material.hpp>

using std::vector;
using namespace glm;

class Node
{
public:
    bool add_child(const Node &child);
    bool remove_child(const Node &child);

    virtual void enter() = 0;
    virtual void update() = 0;
};

class Node3D : public Node
{
protected:
    mat4 transformation;
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