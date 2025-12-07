// Extensión opcional: Soporte para controles de Gamepad/Joystick
// Este archivo muestra cómo agregar soporte para controles Xbox, PlayStation, etc.

#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <SFML/Window.hpp>

class InputHandler
{
public:
    enum class InputDevice
    {
        KEYBOARD,
        GAMEPAD,
        UNKNOWN
    };
    
    // Detectar cual entrada está siendo usada
    static InputDevice getActiveDevice();
    
    // Controles de teclado (ya implementados)
    static bool isAccelerating();
    static bool isBraking();
    static bool isMovingLeft();
    static bool isMovingRight();
    
    // Controles de gamepad (nuevos - ejemplo)
    static bool isGamepadConnected();
    static float getGamepadLeftStickX();
    static float getGamepadLeftStickY();
    static bool isGamepadButtonPressed(sf::Joystick::Button button);
};

/*
INSTRUCCIONES PARA IMPLEMENTAR GAMEPAD:

1. Incluir en core/Player.cpp:
   #include "InputHandler.hpp"

2. Modificar Player::update() para usar:
   if (sf::Joystick::isConnected(0)) {
       float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
       velocity += ACCELERATION * x * deltaTime;
   }

3. Botones de controles comunes:
   - Xbox: A=0, B=1, X=2, Y=3
   - PlayStation: Square=0, X=1, Circle=2, Triangle=3
   - Trigger izquierdo: Axis LZ
   - Trigger derecho: Axis RZ
   - Stick analógico: Axis X, Y

4. Ejemplo completo de integración en GameState::handleInput():
   
   // Teclado
   if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
       player->accelerate();
   
   // O Gamepad
   if (sf::Joystick::isConnected(0)) {
       float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
       if (y < -50) // Stick hacia arriba
           player->accelerate();
   }

NOTA: Este es un ejemplo conceptual. Para implementación completa,
ver documentación de SFML Joystick en:
https://www.sfml-dev.org/tutorials/2.5/window-inputs.html
*/

#endif
