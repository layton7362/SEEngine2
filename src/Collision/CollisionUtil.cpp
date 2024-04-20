#include <Collision/CollisionUtil.hpp>

float distanceSquared(vec3 p1, vec3 p2)
{
    return dot(p1 - p2, p1 - p2);
}

bool CollisionUtil::collide(BoxShape &obj1, BoxShape &obj2)
{
    vec3 distance = obj2.position - obj1.position;
    vec3 halfSize1 = obj1.size * 0.5f;
    vec3 halfSize2 = obj2.size * 0.5f;

    bool xOverlap = std::abs(distance.x) <= (halfSize1.x + halfSize2.x);
    bool yOverlap = std::abs(distance.y) <= (halfSize1.y + halfSize2.y);
    bool zOverlap = std::abs(distance.z) <= (halfSize1.z + halfSize2.z);

    return xOverlap && yOverlap && zOverlap;
}

bool CollisionUtil::collide(Sphere &obj1, BoxShape &obj2)
{
    vec3 closestPointOnBox(
        clamp(obj1.position.x, obj2.position.x - obj2.size.x / 2.0f, obj2.position.x + obj2.size.x / 2.0f),
        clamp(obj1.position.y, obj2.position.y - obj2.size.y / 2.0f, obj2.position.y + obj2.size.y / 2.0f),
        clamp(obj1.position.z, obj2.position.z - obj2.size.z / 2.0f, obj2.position.z + obj2.size.z / 2.0f));

    float distanceSq = distanceSquared(obj1.position, closestPointOnBox);

    return distanceSq <= (obj1.radius * obj1.radius);
}

bool CollisionUtil::collide(Sphere &obj1, Sphere &obj2)
{
    float distanceSq = distanceSquared(obj1.position, obj2.position);

    float sumRadii = obj1.radius + obj2.radius;
    return distanceSq <= (sumRadii * sumRadii);
}