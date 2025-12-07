#ifndef MAP_SELECT_STATE_HPP
#define MAP_SELECT_STATE_HPP

#include "State.hpp"
#include "UI.hpp"

class MapSelectState : public State
{
private:
    UI ui;
    int selectedMap;
    
public:
    MapSelectState(GameEngine* engine);
    
    void handleInput(const sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};

#endif
