#ifndef CAR_SPRITE_HPP
#define CAR_SPRITE_HPP

#include <SFML/Graphics.hpp>
#include <string>

class CarSprite {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    float velocity;
    int lane;
    bool isPlayer;

public:
    CarSprite(const std::string& imagePath, float startY, int lane, float speed, bool player = false);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    float getX() const;
    float getY() const;
    int getLane() const;
    float getVelocity() const;
    void setVelocity(float v);
    void setPosition(float x, float y);
    void setScale(float scaleX, float scaleY);
    bool isOffScreen(float windowHeight = 600.0f) const;
    sf::Sprite& getSprite();
};

#endif
