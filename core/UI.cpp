#include "UI.hpp"

UI::UI()
{
}

bool UI::loadFont(const std::string& fontPath)
{
    if (!font.loadFromFile(fontPath))
    {
        return false;
    }
    return true;
}

void UI::drawText(sf::RenderWindow& window, const std::string& text, 
                  float x, float y, int size, const sf::Color& color)
{
    sf::Text displayText(text, font, size);
    displayText.setFillColor(color);
    displayText.setPosition(x, y);
    window.draw(displayText);
}

void UI::drawButton(sf::RenderWindow& window, const std::string& text, 
                    float x, float y, float width, float height, 
                    const sf::Color& bgColor)
{
    sf::RectangleShape button(sf::Vector2f(width, height));
    button.setFillColor(bgColor);
    button.setPosition(x, y);
    window.draw(button);
    
    sf::Text buttonText(text, font, 20);
    buttonText.setFillColor(sf::Color::White);
    float textX = x + (width - buttonText.getLocalBounds().width) / 2;
    float textY = y + (height - buttonText.getLocalBounds().height) / 2;
    buttonText.setPosition(textX, textY);
    window.draw(buttonText);
}

void UI::drawHUD(sf::RenderWindow& window, int score, float distance, 
                 float velocity, int nearMisses)
{
    drawText(window, "Score: " + std::to_string(score), 10, 10, 20);
    drawText(window, "Distance: " + std::to_string(static_cast<int>(distance)) + "m", 10, 35, 20);
    drawText(window, "Speed: " + std::to_string(static_cast<int>(velocity)), 10, 60, 20);
    drawText(window, "Near Misses: " + std::to_string(nearMisses), 10, 85, 20);
}

const sf::Font& UI::getFont() const
{
    return font;
}
