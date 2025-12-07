#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

// Player now uses CarSprite for sprite-based rendering
#include "CarSprite.hpp"
#include <memory>

class Player {
private:
    std::unique_ptr<CarSprite> car;
    float velocity;
    float acceleration;
    float maxVelocity;
    float deceleration;
    int lane; // índice de carril (0-3)
    float health;
    std::string imagePath;
    // Movimiento por carriles
    static constexpr int NUM_LANES = 4;
    float visualWidth = 150.0f;
    float laneAnimTime = 0.0f; // 0 => cambio inmediato
    float laneAnimElapsed = 0.0f;
    bool isLaneChanging = false;
    float startX = 0.0f;

    float targetX = 0.0f;

public:
    Player(const std::string& imagePath, float startX, float startY);
    void update(float deltaTime);
    void accelerate();
    void brake();
    void moveLeft();
    void moveRight();
    void takeDamage(float damage);
    bool isAlive() const;
    sf::FloatRect getBounds() const;
    float getVelocity() const;
    int getLane() const;
    float getX() const;
    float getY() const;
    void setHealth(float h);
    float getHealth() const;
    void render(sf::RenderWindow& window);
};

#endif
