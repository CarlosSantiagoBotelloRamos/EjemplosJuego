#include "Spawner.hpp"
#include <random>
#include <ctime>

static std::mt19937 rng(std::time(nullptr));

const float BASE_SPAWN_INTERVAL = 2.0f;
const float INITIAL_SPEED = 150.0f;

Spawner::Spawner(int selectedMap)
        : spawnTimer(0.0f),
            spawnInterval(BASE_SPAWN_INTERVAL),
            difficulty(1.0f),
            map(selectedMap)
{
}

void Spawner::update(float deltaTime)
{
    spawnTimer += deltaTime;
    
    if (spawnTimer >= spawnInterval)
    {
        spawn();
        spawnTimer = 0.0f;
    }
    
    // Actualizar autos enemigos
    for (auto& car : cars)
    {
        car->update(deltaTime);
    }
    
    // Remover autos que salieron de pantalla
    for (size_t i = 0; i < cars.size(); )
    {
        if (cars[i]->isOffScreen())
        {
            cars.erase(cars.begin() + i);
        }
        else
        {
            i++;
        }
    }
}

void Spawner::spawn()
{
    // Seleccionar carril aleatorio (4 carriles)
    std::uniform_int_distribution<> laneDist(0, 3);
    int lane = laneDist(rng);
    // Velocidad basada en dificultad
    float speed = INITIAL_SPEED * difficulty;
    std::uniform_real_distribution<> speedVar(0.8f, 1.2f);
    speed *= speedVar(rng);
    // Seleccionar imagen aleatoria
    std::string imagePath = "assets/cars/Police car.png";
    if (!carImages.empty()) {
        std::uniform_int_distribution<> imgDist(0, static_cast<int>(carImages.size()) - 1);
        imagePath = carImages[imgDist(rng)];
    }
    cars.push_back(std::make_shared<EnemyCar>(imagePath, -60.0f, lane, speed));
}
void Spawner::setCarImages(const std::vector<std::string>& images)
{
    carImages = images;
}

std::vector<std::shared_ptr<EnemyCar>>& Spawner::getCars()
{
    return cars;
}

void Spawner::removeCar(size_t index)
{
    if (index < cars.size())
        cars.erase(cars.begin() + index);
}

void Spawner::increaseDifficulty()
{
    difficulty += 0.1f;
    spawnInterval = std::max(0.5f, spawnInterval - 0.1f);
}

void Spawner::setMap(int mapId)
{
    map = mapId;
}

void Spawner::render(sf::RenderWindow& window)
{
    for (auto& car : cars)
    {
        car->render(window);
    }
}
