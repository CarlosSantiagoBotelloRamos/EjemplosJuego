#include "../include/CarSprite.hpp"
#include "../include/LaneConfig.hpp"
#include <iostream>

CarSprite::CarSprite(const std::string& imagePath, float startY, int lane, float speed, bool player)
    : velocity(speed), lane(lane), isPlayer(player)
{
    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "[ERROR] No se pudo cargar la imagen: " << imagePath << std::endl;
    }
    sprite.setTexture(texture);
    // Escalado para 50px de ancho (carriles de 50px)
    float scaleX = 50.0f / texture.getSize().x;
    float scaleY = 90.0f / texture.getSize().y; // Proporción ajustada
    sprite.setScale(scaleX, scaleY);
    
    // Centrar origen del sprite
    sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);

    // Usar posiciones de carril compartidas y simétricas
    float xPos = getLaneX(lane);
    sprite.setPosition(xPos, startY);
}

void CarSprite::update(float deltaTime)
{
    float dy = isPlayer ? -velocity * deltaTime : velocity * deltaTime;
    sprite.move(0, dy);
}

void CarSprite::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::FloatRect CarSprite::getBounds() const
{
    return sprite.getGlobalBounds();
}

float CarSprite::getX() const { return sprite.getPosition().x; }
float CarSprite::getY() const { return sprite.getPosition().y; }
int CarSprite::getLane() const { return lane; }
float CarSprite::getVelocity() const { return velocity; }
void CarSprite::setVelocity(float v) { velocity = v; }
void CarSprite::setPosition(float x, float y) { sprite.setPosition(x, y); }
void CarSprite::setScale(float scaleX, float scaleY) { sprite.setScale(scaleX, scaleY); }
bool CarSprite::isOffScreen(float windowHeight) const { return sprite.getPosition().y > windowHeight || sprite.getPosition().y + sprite.getGlobalBounds().height < 0; }
sf::Sprite& CarSprite::getSprite() { return sprite; }
