#include "GameState.hpp"
#include "GameEngine.hpp"
#include "GameOverState.hpp"
#include "Collision.hpp"
#include <iostream>

// Helper: get car image list
#include <filesystem>
std::vector<std::string> getCarImageList() {
    std::vector<std::string> images;
    std::string dir = "assets/cars/";
    for (const auto& entry : std::filesystem::directory_iterator(dir)) {
        if (entry.path().extension() == ".png") {
            images.push_back(entry.path().string());
        }
    }
    return images;
}

GameState::GameState(GameEngine* engine, int selectedVehicle, int selectedMap)
    : State(engine),
      nearMissThreshold(150.0f)
{
    // Selección de vehículo
    auto carImages = getCarImageList();
    std::string playerImage = carImages.empty() ? "assets/cars/Police car.png" : carImages[selectedVehicle % carImages.size()];
    player = std::make_unique<Player>(playerImage, 100.0f, 500.0f);
    spawner = std::make_unique<Spawner>(selectedMap);
    spawner->setCarImages(carImages);
    score = std::make_unique<Score>();

    ui.loadFont("assets/fonts/arial.ttf");

    // Fondo animado
    if (!roadTexture.loadFromFile("assets/road/road_bg.png")) {
        // Si no se carga, usar color negro
        std::cerr << "[ERROR] No se pudo cargar assets/road/road_bg.png\n";
    }
    roadSprite1.setTexture(roadTexture);
    roadSprite2.setTexture(roadTexture);
    // Escalar el fondo para cubrir toda la ventana dinámicamente
    auto winSize = engine->getWindow().getSize();
    float scaleX = static_cast<float>(winSize.x) / roadTexture.getSize().x;
    float scaleY = static_cast<float>(winSize.y) / roadTexture.getSize().y;
    roadSprite1.setScale(scaleX, scaleY);
    roadSprite2.setScale(scaleX, scaleY);
    // Posicionar en 0,0
    roadSprite1.setPosition(0, 0);
    roadSprite2.setPosition(0, -static_cast<float>(winSize.y)); // Usar alto de ventana
    roadScrollY = 0.0f;
    roadScrollSpeed = 200.0f; // Puedes ajustar la velocidad
}

void GameState::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            engine->popState();
            return;
        }
    }
    
    // Movimiento por toque único de flecha (no repetido) y muestra la posición X del jugador
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
                player->accelerate();
            }
            if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
                player->brake();
            }
            if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
                player->moveLeft();
            }
            if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
                player->moveRight();
            }
        }
}

void GameState::update(float deltaTime)
{
    // Fondo animado: scroll infinito
    float bgHeight = static_cast<float>(engine->getWindow().getSize().y); // Alto de ventana
    roadScrollY += roadScrollSpeed * deltaTime;
    if (roadScrollY >= bgHeight)
        roadScrollY -= bgHeight;
    roadSprite1.setPosition(0, roadScrollY);
    roadSprite2.setPosition(0, roadScrollY - bgHeight);

    player->update(deltaTime);
    spawner->update(deltaTime);
    score->update(deltaTime, player->getVelocity());
    score->updateMaxVelocity(player->getVelocity());

    // Aumentar dificultad cada 30 segundos
    if (static_cast<int>(score->getTimeAlive()) % 30 == 0 && score->getTimeAlive() > 0)
    {
        spawner->increaseDifficulty();
    }

    checkCollisions();
    checkNearMisses();

    // Si el jugador muere
    if (!player->isAlive())
    {
        engine->popState();
        auto gameOverState = std::make_shared<GameOverState>(engine,
            score->getPoints(),
            score->getDistance(),
            score->getNearMisses());
        engine->pushState(gameOverState);
    }
}

void GameState::render(sf::RenderWindow& window)
{
    window.clear();

    // Fondo animado infinito
    window.draw(roadSprite2);
    window.draw(roadSprite1);

    // Si el fondo no cubre toda la ventana, dibuja más sprites
    if (roadScrollY < 0) {
        sf::Sprite extraSprite(roadTexture);
        auto winSize = engine->getWindow().getSize();
        float scaleX = static_cast<float>(winSize.x) / roadTexture.getSize().x;
        float scaleY = static_cast<float>(winSize.y) / roadTexture.getSize().y;
        float bgHeight = static_cast<float>(winSize.y);
        extraSprite.setScale(scaleX, scaleY);
        extraSprite.setPosition(0, roadScrollY + bgHeight);
        window.draw(extraSprite);
    }

    // Dibujar vehículos
    spawner->render(window);
    player->render(window);

    // Dibujar HUD
    ui.drawHUD(window, score->getPoints(), score->getDistance(),
               player->getVelocity(), score->getNearMisses());

    ui.drawText(window, "Health: " + std::to_string(static_cast<int>(player->getHealth())) + "%",
                650, 10, 16);
    ui.drawText(window, "Press ESC to quit", 650, 35, 12);
}

void GameState::checkCollisions()
{
    auto& cars = spawner->getCars();
    for (size_t i = 0; i < cars.size(); ++i)
    {
        if (player->getBounds().intersects(cars[i]->getBounds()))
        {
            player->takeDamage(50.0f);
            score->recordCollision();
            spawner->removeCar(i);
            break;
        }
    }
}

void GameState::checkNearMisses()
{
    auto& cars = spawner->getCars();
    for (size_t i = 0; i < cars.size(); ++i)
    {
        float dist = std::abs(player->getY() - cars[i]->getY());
        if (dist < nearMissThreshold && !player->getBounds().intersects(cars[i]->getBounds()))
        {
            score->recordNearMiss();
        }
    }
}


