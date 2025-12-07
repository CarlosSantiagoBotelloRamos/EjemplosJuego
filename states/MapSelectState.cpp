#include "MapSelectState.hpp"
#include "GameEngine.hpp"
#include "MenuState.hpp"

MapSelectState::MapSelectState(GameEngine* engine)
    : State(engine),
      selectedMap(0)
{
    ui.loadFont("assets/fonts/arial.ttf");
}

void MapSelectState::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
        {
            selectedMap = (selectedMap - 1 + 3) % 3;
        }
        else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
        {
            selectedMap = (selectedMap + 1) % 3;
        }
        else if (event.key.code == sf::Keyboard::Return)
        {
            engine->setSelectedMap(selectedMap);
            engine->popState();
        }
        else if (event.key.code == sf::Keyboard::Escape)
        {
            engine->popState();
        }
    }
}

void MapSelectState::update(float deltaTime)
{
    (void)deltaTime; // Evitar warning de parámetro no usado
    // Update logic if needed
}

void MapSelectState::render(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
    
    ui.drawText(window, "SELECT MAP", 300, 50, 40, sf::Color::Green);
    
    // Map 1
    sf::Color color1 = (selectedMap == 0) ? sf::Color::Yellow : sf::Color::White;
    ui.drawText(window, "Highway", 100, 200, 28, color1);
    ui.drawText(window, "Normal difficulty", 100, 240, 16, color1);
    
    // Map 2
    sf::Color color2 = (selectedMap == 1) ? sf::Color::Yellow : sf::Color::White;
    ui.drawText(window, "City Street", 400, 200, 28, color2);
    ui.drawText(window, "Hard difficulty", 400, 240, 16, color2);
    
    // Map 3
    sf::Color color3 = (selectedMap == 2) ? sf::Color::Yellow : sf::Color::White;
    ui.drawText(window, "Mountain Road", 600, 200, 28, color3);
    ui.drawText(window, "Insane difficulty", 600, 240, 16, color3);
    
    ui.drawText(window, "Use LEFT/RIGHT arrows to select, ENTER to confirm", 110, 450, 16, sf::Color::Cyan);
    ui.drawText(window, "Press ESC to go back", 250, 500, 16, sf::Color::Cyan);
}
