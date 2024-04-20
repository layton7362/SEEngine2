#include <Nodes/Object3D.hpp>

Object3D::Object3D()
{
}

Object3D::~Object3D()
{
}

void Object3D::enter()
{
    GLint loc = glGetUniformLocation(material->getProgramId(), "transformation");
    addUniform(loc, UniformCall(TraitUniform::setMatrix4(loc, transformation)));
}

void Object3D::update(const float &delta) 
{
  
}

void Object3D::dispose() 
{
    if(disposed){
        return;
    }

    // Ressource Counter of Mesh change
  
}