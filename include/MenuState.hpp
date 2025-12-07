#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include "State.hpp"
#include "UI.hpp"
#include <memory>

class MenuState : public State
{
private:
    UI ui;
    int selectedOption;
    enum MenuOption
    {
        START_GAME = 0,
        VEHICLE_SELECT = 1,
        MAP_SELECT = 2,
        QUIT = 3
    };
    
public:
    MenuState(GameEngine* engine);
    
    void handleInput(const sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};

#endif
