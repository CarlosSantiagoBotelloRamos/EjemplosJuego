#include "GameEngine.hpp"
#include "State.hpp"

GameEngine::GameEngine() 
    : window(sf::VideoMode(800, 600), "Traffic Racer"),
      running(true),
      selectedVehicle(0),
      selectedMap(0)
{
    window.setFramerateLimit(60);
}

GameEngine::~GameEngine() = default;

void GameEngine::run()
{
    while (running && window.isOpen())
    {
        handleInput();
        
        float deltaTime = clock.restart().asSeconds();
        update(deltaTime);
        render();
    }
}

void GameEngine::handleInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            running = false;
        
        if (!states.empty())
            states.top()->handleInput(event);
    }
}

void GameEngine::update(float deltaTime)
{
    if (!states.empty())
        states.top()->update(deltaTime);
}

void GameEngine::render()
{
    window.clear(sf::Color::Black);
    
    if (!states.empty())
        states.top()->render(window);
    
    window.display();
}

void GameEngine::pushState(std::shared_ptr<State> state)
{
    states.push(state);
}

void GameEngine::popState()
{
    if (!states.empty())
        states.pop();
}

sf::RenderWindow& GameEngine::getWindow()
{
    return window;
}

void GameEngine::setSelectedVehicle(int vehicle)
{
    selectedVehicle = vehicle;
}

void GameEngine::setSelectedMap(int map)
{
    selectedMap = map;
}

int GameEngine::getSelectedVehicle() const
{
    return selectedVehicle;
}

int GameEngine::getSelectedMap() const
{
    return selectedMap;
}

void GameEngine::quit()
{
    running = false;
}
