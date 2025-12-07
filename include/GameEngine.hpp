#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>

class State;

class GameEngine
{
private:
    sf::RenderWindow window;
    std::stack<std::shared_ptr<State>> states;
    sf::Clock clock;
    bool running;
    
    // Selecciones del jugador
    int selectedVehicle;
    int selectedMap;
    
public:
    GameEngine();
    ~GameEngine();
    
    void run();
    void handleInput();
    void update(float deltaTime);
    void render();
    
    void pushState(std::shared_ptr<State> state);
    void popState();
    
    sf::RenderWindow& getWindow();
    
    void setSelectedVehicle(int vehicle);
    void setSelectedMap(int map);
    int getSelectedVehicle() const;
    int getSelectedMap() const;
    
    void quit();
};

#endif
