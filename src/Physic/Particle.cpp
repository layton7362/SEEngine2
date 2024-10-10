
#include <math.h>
#include <Physic/Particle.hpp>



Particle::Particle()
{
}

Particle::~Particle()
{
}

void Particle::integrator(float time)
{
    if (inverseMass <= 0.0f) return;

    // Last Part is very small, so it hase only small impakt
    // position += time * velocity + acceleration * time * time * 0.5;
    position += time * velocity + acceleration * time * time * 0.5f;
    
    velocity = velocity * powf(damping, time) + acceleration * time;
}
