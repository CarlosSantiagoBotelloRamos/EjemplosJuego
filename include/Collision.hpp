#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <SFML/Graphics.hpp>

class Collision
{
public:
    static bool rectangleCollision(const sf::RectangleShape& a, const sf::RectangleShape& b);
    static float distanceBetween(float x1, float y1, float x2, float y2);
    static bool isNearMiss(const sf::RectangleShape& a, const sf::RectangleShape& b, float threshold = 100.0f);
};

#endif
