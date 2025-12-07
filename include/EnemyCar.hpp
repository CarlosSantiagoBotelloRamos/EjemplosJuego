#ifndef ENEMY_CAR_HPP
#define ENEMY_CAR_HPP

#include <SFML/Graphics.hpp>

// EnemyCar now uses CarSprite for sprite-based rendering
#include "CarSprite.hpp"
#include <memory>
#include <string>

class EnemyCar {
private:
    std::unique_ptr<CarSprite> car;
    std::string imagePath;
public:
    EnemyCar(const std::string& imagePath, float startY, int lane, float speed);
    void update(float deltaTime);
    sf::FloatRect getBounds() const;
    float getX() const;
    float getY() const;
    int getLane() const;
    float getVelocity() const;
    bool isOffScreen() const;
    void render(sf::RenderWindow& window);
};

#endif
