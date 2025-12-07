#include "MenuState.hpp"
#include "GameEngine.hpp"
#include "GameState.hpp"
#include "VehicleSelectState.hpp"
#include "MapSelectState.hpp"
#include <iostream>

MenuState::MenuState(GameEngine* engine)
        : State(engine),
            selectedOption(START_GAME)
{
    if (!ui.loadFont("assets/fonts/arial.ttf")) {
        std::cerr << "[ERROR] No se pudo cargar la fuente assets/fonts/arial.ttf.\n";
        std::cerr << "Asegúrate de que el archivo existe y es una fuente TTF válida.\n";
        std::cerr << "Puedes copiar una fuente desde C:/Windows/Fonts/.\n" << std::endl;
        if (engine) engine->quit();
    }
}

void MenuState::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Up)
        {
            selectedOption = (selectedOption - 1 + 4) % 4;
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            selectedOption = (selectedOption + 1) % 4;
        }
        else if (event.key.code == sf::Keyboard::Return)
        {
            switch (selectedOption)
            {
                case START_GAME:
                {
                    auto gameState = std::make_shared<GameState>(engine, 
                        engine->getSelectedVehicle(), 
                        engine->getSelectedMap());
                    engine->pushState(gameState);
                    break;
                }
                case VEHICLE_SELECT:
                {
                    auto vehicleState = std::make_shared<VehicleSelectState>(engine);
                    engine->pushState(vehicleState);
                    break;
                }
                case MAP_SELECT:
                {
                    auto mapState = std::make_shared<MapSelectState>(engine);
                    engine->pushState(mapState);
                    break;
                }
                case QUIT:
                    engine->quit();
                    break;
            }
        }
    }
}

void MenuState::update(float deltaTime)
{
    (void)deltaTime; // Evitar warning de parámetro no usado
    // Update logic if needed
}

void MenuState::render(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
    
    ui.drawText(window, "TRAFFIC RACER", 300, 50, 48, sf::Color::Green);
    
    // Menú
    sf::Color startColor = (selectedOption == START_GAME) ? sf::Color::Yellow : sf::Color::White;
    ui.drawText(window, "Start Game", 350, 150, 28, startColor);
    
    sf::Color vehicleColor = (selectedOption == VEHICLE_SELECT) ? sf::Color::Yellow : sf::Color::White;
    ui.drawText(window, "Select Vehicle", 320, 200, 28, vehicleColor);
    
    sf::Color mapColor = (selectedOption == MAP_SELECT) ? sf::Color::Yellow : sf::Color::White;
    ui.drawText(window, "Select Map", 340, 250, 28, mapColor);
    
    sf::Color quitColor = (selectedOption == QUIT) ? sf::Color::Yellow : sf::Color::White;
    ui.drawText(window, "Quit", 370, 300, 28, quitColor);
    
    ui.drawText(window, "Use UP/DOWN arrows to navigate, ENTER to select", 130, 450, 16, sf::Color::Cyan);
}
