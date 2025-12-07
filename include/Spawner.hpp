#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include "EnemyCar.hpp"
#include <vector>
#include <memory>

// Spawner now supports random car images for enemies
#include <vector>
#include <string>
#include <memory>

class Spawner {
private:
    std::vector<std::shared_ptr<EnemyCar>> cars;
    std::vector<std::string> carImages;
    float spawnTimer;
    float spawnInterval;
    float difficulty;
    int map;
public:
    Spawner(int selectedMap = 0);
    void update(float deltaTime);
    void spawn();
    std::vector<std::shared_ptr<EnemyCar>>& getCars();
    void removeCar(size_t index);
    void increaseDifficulty();
    void setMap(int mapId);
    void render(sf::RenderWindow& window);
    void setCarImages(const std::vector<std::string>& images);
};

#endif
