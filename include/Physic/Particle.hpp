#pragma once
#include <Types.hpp>

class Particle
{
public:
    vec3 position;
    vec3 velocity;
    vec3 acceleration;

    float damping;
    float inverseMass;

public:
    Particle();
    virtual ~Particle() noexcept;

    void integrator(float time);
};
