#include "Score.hpp"

Score::Score()
    : points(0),
      distanceTraveled(0.0f),
      nearMisses(0),
      maxVelocity(0.0f),
      collisions(0),
      timeAlive(0.0f)
{
}

void Score::update(float deltaTime, float playerVelocity)
{
    timeAlive += deltaTime;
    
    // Añadir puntos por tiempo vivo (1 punto cada segundo)
    addPoints(static_cast<int>(deltaTime));
    
    // Añadir puntos por velocidad
    addPoints(static_cast<int>(playerVelocity / 100.0f));
    
    // Actualizar distancia
    distanceTraveled += (playerVelocity * deltaTime) / 100.0f;
}

void Score::addPoints(int pts)
{
    points += pts;
}

void Score::recordNearMiss()
{
    nearMisses++;
    addPoints(50); // Bonus por esquivar
}

void Score::recordCollision()
{
    collisions++;
    points -= 100; // Penalización por colisión
    if (points < 0)
        points = 0;
}

void Score::updateDistance(float distance)
{
    distanceTraveled = distance;
}

void Score::updateMaxVelocity(float velocity)
{
    if (velocity > maxVelocity)
        maxVelocity = velocity;
}

int Score::getPoints() const
{
    return points;
}

float Score::getDistance() const
{
    return distanceTraveled;
}

int Score::getNearMisses() const
{
    return nearMisses;
}

float Score::getMaxVelocity() const
{
    return maxVelocity;
}

int Score::getCollisions() const
{
    return collisions;
}

float Score::getTimeAlive() const
{
    return timeAlive;
}

void Score::reset()
{
    points = 0;
    distanceTraveled = 0.0f;
    nearMisses = 0;
    maxVelocity = 0.0f;
    collisions = 0;
    timeAlive = 0.0f;
}
