// Ejemplo de cómo cargar sprites en Traffic Racer
// Este archivo muestra cómo integrar imágenes y texturas

#ifndef SPRITE_MANAGER_HPP
#define SPRITE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class SpriteManager
{
private:
    std::map<std::string, sf::Texture> textures;
    
public:
    SpriteManager();
    
    bool loadTexture(const std::string& name, const std::string& path);
    
    const sf::Texture& getTexture(const std::string& name) const;
    
    bool hasTexture(const std::string& name) const;
    
    // Ejemplo de uso en Player
    // sf::Sprite playerSprite(spriteManager.getTexture("player"));
    // playerSprite.setPosition(x, y);
    // window.draw(playerSprite);
};

/*
INSTRUCCIONES PARA CARGAR SPRITES:

1. Crea la estructura de assets:
   assets/
   ├── cars/
   │   ├── player.png      (64x80px - color azul)
   │   ├── enemy_red.png   (64x80px - color rojo)
   │   ├── enemy_yellow.png (64x80px - color amarillo)
   │   └── enemy_green.png  (64x80px - color verde)
   ├── road/
   │   ├── road_bg.png     (800x600 - carretera)
   │   └── road_lines.png  (800x600 - líneas de carril)
   └── fonts/
       └── arial.ttf

2. Para descargar assets gratuitos:
   - OpenGameArt.org - https://opengameart.org/
   - FreePik - https://www.freepik.com/
   - Kenney.nl - https://kenney.nl/
   - Itch.io - https://itch.io/

3. Tamaños recomendados:
   - Sprites de coches: 64x80 píxeles
   - Fondo de carretera: 800x600 píxeles
   - Líneas de carril: 4x40 píxeles (repetir)

4. Formatos soportados por SFML:
   - PNG (recomendado - permite transparencia)
   - JPG
   - BMP
   - GIF (sin animación)
   - TGA
   - PSD
*/

#endif
