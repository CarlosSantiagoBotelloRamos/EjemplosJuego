#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "State.hpp"
#include "Player.hpp"
#include "Spawner.hpp"
#include "Score.hpp"
#include "UI.hpp"
#include <memory>


class GameState : public State
{
private:
    std::unique_ptr<Player> player;
    std::unique_ptr<Spawner> spawner;
    std::unique_ptr<Score> score;
    UI ui;
    float nearMissThreshold;

    // Fondo animado
    sf::Texture roadTexture;
    sf::Sprite roadSprite1;
    sf::Sprite roadSprite2;
    float roadScrollY;
    float roadScrollSpeed;

public:
    GameState(GameEngine* engine, int selectedVehicle, int selectedMap);

    void handleInput(const sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    void checkCollisions();
    void checkNearMisses();
    //void drawRoad(sf::RenderWindow& window); // Ya no se usa
};

#endif
