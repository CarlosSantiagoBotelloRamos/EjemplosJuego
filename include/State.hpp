#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class GameEngine;

class State
{
public:
    virtual ~State() = default;
    
    virtual void handleInput(const sf::Event& event) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    
protected:
    GameEngine* engine;
    
    State(GameEngine* engine) : engine(engine) {}
};

#endif
