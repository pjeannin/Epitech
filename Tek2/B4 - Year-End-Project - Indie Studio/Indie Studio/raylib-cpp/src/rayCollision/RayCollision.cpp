#include "RayCollision.hpp"

raylib::RayCollision::RayCollision(::RayHitInfo const &ray) {
    *this = ray;
}

raylib::RayCollision::RayCollision(bool const Hit, float const Distance, ::Vector3 const Point, ::Vector3 const Normal)
{
    hit = Hit;
    distance = Distance;
    //point = Point;
    normal = Normal;
}

raylib::RayCollision::RayCollision(::Ray const &ray, ::Mesh const &mesh, const ::Matrix& transform) {
    *this = ::GetCollisionRayMesh(ray, mesh, transform);
}

raylib::RayCollision::RayCollision(::Ray const &ray, ::Model const &model) {
    *this = ::GetCollisionRayModel(ray, model);
}

raylib::RayCollision::RayCollision(::Ray const &ray, ::Vector3 const &p1, ::Vector3 const &p2, ::Vector3 const &p3) {
    *this = ::GetCollisionRayTriangle(ray, p1, p2, p3);
}

raylib::RayCollision &raylib::RayCollision::operator=(::RayHitInfo const &ray) {
    hit = ray.hit;
    distance = ray.distance;
    //point = ray.point;
    normal = ray.normal;
    return *this;
}