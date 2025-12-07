#ifndef GAME_OVER_STATE_HPP
#define GAME_OVER_STATE_HPP

#include "State.hpp"
#include "UI.hpp"

class GameOverState : public State
{
private:
    UI ui;
    int finalScore;
    float finalDistance;
    int finalNearMisses;
    int selectedOption;
    
    enum GameOverOption
    {
        RETURN_MENU = 0,
        RESTART = 1
    };
    
public:
    GameOverState(GameEngine* engine, int score, float distance, int nearMisses);
    
    void handleInput(const sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};

#endif
