#include <glm/glm.hpp>
#include <Interface.hpp>

using namespace glm;

class Shape
{
public:
    vec3 position;
    vec3 globalPosition;
};

class Sphere : public Shape
{
};

class Box : public Shape
{
};

class PhysicWorld : public IDisposable
{
public:
    virtual void dispose() override;
};
