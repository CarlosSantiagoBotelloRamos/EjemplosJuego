#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <string>

class GameWindow
{
private:
    sf::RenderWindow window;

public:
    GameWindow() {}
    
    ~GameWindow() {}
    
    bool create(int width, int height, const std::string& title)
    {
        window.create(sf::VideoMode(width, height), title);
        window.setFramerateLimit(60);
        return window.isOpen();
    }
    
    bool isOpen() const
    {
        return window.isOpen();
    }
    
    void close()
    {
        window.close();
    }
    
    void clear(const sf::Color& color = sf::Color::Black)
    {
        window.clear(color);
    }
    
    void display()
    {
        window.display();
    }
    
    bool pollEvent(sf::Event& event)
    {
        return window.pollEvent(event);
    }
    
    void draw(const sf::Drawable& drawable)
    {
        window.draw(drawable);
    }
    
    sf::RenderWindow& getRenderWindow()
    {
        return window;
    }
    
    sf::Vector2u getSize() const
    {
        return window.getSize();
    }
};

#endif