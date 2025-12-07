#include "VehicleSelectState.hpp"
#include "GameEngine.hpp"
#include "MenuState.hpp"

// Helper: get car image list
#include <filesystem>
#include <vector>
std::vector<std::string> getCarImageListVS() {
    std::vector<std::string> images;
    std::string dir = "assets/cars/";
    for (const auto& entry : std::filesystem::directory_iterator(dir)) {
        if (entry.path().extension() == ".png") {
            images.push_back(entry.path().string());
        }
    }
    return images;
}

VehicleSelectState::VehicleSelectState(GameEngine* engine)
    : State(engine),
      selectedVehicle(0),
      scrollOffset(0.0f)
{
    ui.loadFont("assets/fonts/arial.ttf");
}

void VehicleSelectState::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        auto carImages = getCarImageListVS();
        int total = static_cast<int>(carImages.size());
        if (total == 0) total = 1;
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
        {
            selectedVehicle = (selectedVehicle - 1 + total) % total;
        }
        else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
        {
            selectedVehicle = (selectedVehicle + 1) % total;
        }
        else if (event.key.code == sf::Keyboard::Return)
        {
            engine->setSelectedVehicle(selectedVehicle);
            engine->popState();
        }
        else if (event.key.code == sf::Keyboard::Escape)
        {
            engine->popState();
        }
    }
}

void VehicleSelectState::update(float deltaTime)
{
    (void)deltaTime; // Evitar warning de parámetro no usado
    // Update logic if needed
}

void VehicleSelectState::render(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
    ui.drawText(window, "SELECT VEHICLE", 280, 50, 40, sf::Color::Green);
    auto carImages = getCarImageListVS();
    int total = static_cast<int>(carImages.size());
    if (total == 0) {
        ui.drawText(window, "No car images found!", 300, 300, 28, sf::Color::Red);
    } else {
        // Tamaño ampliado para los sprites
        float bigScaleX = 220.0f * 0.75f; // 25% más delgado
        float bigScaleY = 330.0f;
        float smallScaleX = 120.0f * 0.75f;
        float smallScaleY = 180.0f;
        float centerX = 400.0f;
        float centerY = 200.0f;
        for (int i = 0; i < total; ++i) {
            sf::Texture tex;
            if (tex.loadFromFile(carImages[i])) {
                sf::Sprite spr(tex);
                float scaleX, scaleY, x, y;
                if (i == selectedVehicle) {
                    scaleX = bigScaleX / tex.getSize().x;
                    scaleY = bigScaleY / tex.getSize().y;
                    x = centerX - bigScaleX / 2.0f;
                    y = centerY - bigScaleY / 2.0f;
                    spr.setColor(sf::Color(255, 255, 100));
                } else {
                    scaleX = smallScaleX / tex.getSize().x;
                    scaleY = smallScaleY / tex.getSize().y;
                    float offset = (i - selectedVehicle) * 250.0f;
                    x = centerX - smallScaleX / 2.0f + offset;
                    y = centerY - smallScaleY / 2.0f + 80.0f;
                    spr.setColor(sf::Color(180, 180, 180));
                }
                spr.setScale(scaleX, scaleY);
                spr.setPosition(x, y);
                window.draw(spr);
                ui.drawText(window, std::filesystem::path(carImages[i]).stem().string(), x, y + (i == selectedVehicle ? bigScaleY + 10 : smallScaleY + 10), (i == selectedVehicle ? 28 : 18), (i == selectedVehicle) ? sf::Color::Yellow : sf::Color::White);
            }
        }
    }
    ui.drawText(window, "Use LEFT/RIGHT arrows to select, ENTER to confirm", 110, 450, 16, sf::Color::Cyan);
    ui.drawText(window, "Press ESC to go back", 250, 500, 16, sf::Color::Cyan);
}
