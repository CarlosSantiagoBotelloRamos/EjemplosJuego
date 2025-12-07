#include "Collision.hpp"
#include <cmath>

bool Collision::rectangleCollision(const sf::RectangleShape& a, const sf::RectangleShape& b)
{
    return a.getGlobalBounds().intersects(b.getGlobalBounds());
}

float Collision::distanceBetween(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

bool Collision::isNearMiss(const sf::RectangleShape& a, const sf::RectangleShape& b, float threshold)
{
    if (rectangleCollision(a, b))
        return false;
    
    sf::Vector2f centerA = a.getPosition() + sf::Vector2f(a.getSize().x / 2, a.getSize().y / 2);
    sf::Vector2f centerB = b.getPosition() + sf::Vector2f(b.getSize().x / 2, b.getSize().y / 2);
    
    float dist = distanceBetween(centerA.x, centerA.y, centerB.x, centerB.y);
    
    return dist < threshold && dist > 0;
}
