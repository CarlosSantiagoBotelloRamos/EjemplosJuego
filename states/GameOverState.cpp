#include "GameOverState.hpp"
#include "GameEngine.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"

GameOverState::GameOverState(GameEngine* engine, int score, float distance, int nearMisses)
    : State(engine),
      finalScore(score),
      finalDistance(distance),
      finalNearMisses(nearMisses),
      selectedOption(RETURN_MENU)
{
    ui.loadFont("assets/fonts/arial.ttf");
}

void GameOverState::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
        {
            selectedOption = RETURN_MENU;
        }
        else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
        {
            selectedOption = RESTART;
        }
        else if (event.key.code == sf::Keyboard::Return)
        {
            if (selectedOption == RETURN_MENU)
            {
                // Limpiar el stack de estados y volver al menú principal
                while (engine->getWindow().isOpen() && engine->getWindow().hasFocus()) {
                    engine->popState();
                    // Si solo queda el menú, salimos del bucle
                    if (engine->getWindow().isOpen() && engine->getWindow().hasFocus()) break;
                }
                // Resetear opción seleccionada del menú
                auto menuState = std::make_shared<MenuState>(engine);
                engine->pushState(menuState);
            }
            else if (selectedOption == RESTART)
            {
                // Reiniciar partida como "Start Game":
                // 1) Quitar Game Over
                engine->popState();
                // 2) Quitar el estado de juego anterior si existe
                engine->popState();
                // 3) Empujar un nuevo GameState con vehículo y mapa seleccionados
                auto gameState = std::make_shared<GameState>(engine,
                    engine->getSelectedVehicle(),
                    engine->getSelectedMap());
                engine->pushState(gameState);
            }
        }
    }
}

void GameOverState::update(float deltaTime)
{
    (void)deltaTime; // Evitar warning de parámetro no usado
    // Update logic if needed
}

void GameOverState::render(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
    
    ui.drawText(window, "GAME OVER", 300, 50, 48, sf::Color::Red);
    
    ui.drawText(window, "Final Score: " + std::to_string(finalScore), 250, 150, 28);
    ui.drawText(window, "Distance: " + std::to_string(static_cast<int>(finalDistance)) + "m", 250, 200, 28);
    ui.drawText(window, "Near Misses: " + std::to_string(finalNearMisses), 250, 250, 28);
    
    sf::Color menuColor = (selectedOption == RETURN_MENU) ? sf::Color::Yellow : sf::Color::White;
    ui.drawText(window, "Return to Menu", 280, 350, 28, menuColor);
    
    sf::Color restartColor = (selectedOption == RESTART) ? sf::Color::Yellow : sf::Color::White;
    ui.drawText(window, "Restart Game", 300, 400, 28, restartColor);
    
    ui.drawText(window, "Use LEFT/RIGHT arrows to navigate, ENTER to select", 120, 500, 16, sf::Color::Cyan);
}
