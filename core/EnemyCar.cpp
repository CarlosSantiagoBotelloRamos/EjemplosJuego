#include "EnemyCar.hpp"
#include <memory>
#include <cmath>

const int WINDOW_WIDTH = 800;
const float LANE_WIDTH = 50.0f;

EnemyCar::EnemyCar(const std::string& imagePath, float startY, int lane, float speed)
    : imagePath(imagePath)
{
    // La posición se calcula automáticamente en CarSprite
    car = std::make_unique<CarSprite>(imagePath, startY, lane, speed, false);
}

void EnemyCar::update(float deltaTime)
{
    car->update(deltaTime);
}

sf::FloatRect EnemyCar::getBounds() const
{
    return car->getBounds();
}

float EnemyCar::getX() const
{
    return car->getX();
}

float EnemyCar::getY() const
{
    return car->getY();
}

int EnemyCar::getLane() const
{
    return car->getLane();
}

float EnemyCar::getVelocity() const
{
    return car->getVelocity();
}

bool EnemyCar::isOffScreen() const
{
    return car->isOffScreen(600.0f);
}

void EnemyCar::render(sf::RenderWindow& window)
{
    car->render(window);
}
