#ifndef UI_HPP
#define UI_HPP

#include <SFML/Graphics.hpp>
#include <string>

class UI
{
private:
    sf::Font font;
    
public:
    UI();
    
    bool loadFont(const std::string& fontPath);
    
    void drawText(sf::RenderWindow& window, const std::string& text, 
                  float x, float y, int size = 24, const sf::Color& color = sf::Color::White);
    void drawButton(sf::RenderWindow& window, const std::string& text, 
                    float x, float y, float width, float height, 
                    const sf::Color& bgColor = sf::Color::Blue);
    void drawHUD(sf::RenderWindow& window, int score, float distance, 
                 float velocity, int nearMisses);
    
    const sf::Font& getFont() const;
};

#endif
