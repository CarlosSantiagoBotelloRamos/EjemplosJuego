#ifndef VEHICLE_SELECT_STATE_HPP
#define VEHICLE_SELECT_STATE_HPP

#include "State.hpp"
#include "UI.hpp"

class VehicleSelectState : public State
{
private:
    UI ui;
    int selectedVehicle;
    float scrollOffset; // Para scroll horizontal
public:
    VehicleSelectState(GameEngine* engine);
    void handleInput(const sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};

#endif
