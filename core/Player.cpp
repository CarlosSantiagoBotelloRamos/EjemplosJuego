#include "Player.hpp"
#include "LaneConfig.hpp"
#include <memory>
#include <cmath>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float LANE_WIDTH = 50.0f;
const float PLAYER_WIDTH = 40.0f;
const float PLAYER_HEIGHT = 60.0f;
const float MAX_VELOCITY = 500.0f;
const float ACCELERATION = 300.0f;
const float DECELERATION = 150.0f;
const float LANE_CHANGE_SPEED = 200.0f;

Player::Player(const std::string& imagePath, float startX, float startY)
    : velocity(0.0f),
      acceleration(ACCELERATION),
      maxVelocity(MAX_VELOCITY),
      deceleration(DECELERATION),
      lane(1),
      health(100.0f),
      imagePath(imagePath),
      isLaneChanging(false),
      laneAnimElapsed(0.0f)
{
    // Las posiciones de los carriles ya están definidas en el header
    car = std::make_unique<CarSprite>(imagePath, startY, lane, velocity, true);
    float x = getLaneX(lane);
    car->setPosition(x, startY);
    startX = x;
    targetX = x;
}

void Player::update(float deltaTime)
{
    // Aplicar deceleración
    if (velocity > 0)
    {
        velocity -= deceleration * deltaTime;
        if (velocity < 0)
            velocity = 0;
    }
    // Limitar velocidad máxima
    if (velocity > maxVelocity)
        velocity = maxVelocity;
    // Movimiento hacia adelante
    car->setVelocity(-velocity); // Player moves up
    // Movimiento por carriles inmediato (sin animación)
    if (isLaneChanging) {
        car->setPosition(targetX, car->getY());
        isLaneChanging = false;
        startX = targetX;
    }
    car->update(deltaTime);
    // Mantener dentro de pantalla verticalmente
    float y = car->getY();
    if (y < 0)
        car->setPosition(car->getX(), 0);
    if (y > WINDOW_HEIGHT)
        car->setPosition(car->getX(), WINDOW_HEIGHT - 60.0f);
}

void Player::accelerate()
{
    velocity = std::min(velocity + acceleration * 0.016f, maxVelocity);
}

void Player::brake()
{
    velocity = std::max(velocity - deceleration * 0.05f, 0.0f);
}

void Player::moveLeft()
{
    if (lane > 0) {
        --lane;
        targetX = getLaneX(lane);
        car->setPosition(targetX, car->getY());
        isLaneChanging = false;
        startX = targetX;
    }
}

void Player::moveRight()
{
    if (lane < NUM_LANES - 1) {
        ++lane;
        targetX = getLaneX(lane);
        car->setPosition(targetX, car->getY());
        isLaneChanging = false;
        startX = targetX;
    }
}

void Player::takeDamage(float damage)
{
    health -= damage;
    if (health < 0)
        health = 0;
}

bool Player::isAlive() const
{
    return health > 0;
}

sf::FloatRect Player::getBounds() const
{
    return car->getBounds();
}

float Player::getVelocity() const
{
    return velocity;
}

int Player::getLane() const
{
    return lane;
}

float Player::getX() const
{
    return car->getX();
}

float Player::getY() const
{
    return car->getY();
}

void Player::setHealth(float h)
{
    health = h;
}

float Player::getHealth() const
{
    return health;
}

void Player::render(sf::RenderWindow& window)
{
    car->render(window);
}
