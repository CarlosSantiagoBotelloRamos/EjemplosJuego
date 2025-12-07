#include "GameEngine.hpp"
#include "MenuState.hpp"
#include <iostream>

int main()
{
    try
    {
        GameEngine engine;
        
        // Crear y empujar el estado de menú inicial
        auto menuState = std::make_shared<MenuState>(&engine);
        engine.pushState(menuState);
        
        // Iniciar el juego
        engine.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
