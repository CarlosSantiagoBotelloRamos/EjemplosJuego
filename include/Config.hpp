// Archivo de configuración para futuras extensiones de Traffic Racer
// Este archivo centraliza constantes y configuraciones del juego

#ifndef CONFIG_HPP
#define CONFIG_HPP

// ============================================
// VENTANA DEL JUEGO
// ============================================
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr int WINDOW_FPS = 60;
constexpr const char* WINDOW_TITLE = "Traffic Racer";

// ============================================
// CONFIGURACIÓN DEL JUGADOR
// ============================================
constexpr float PLAYER_WIDTH = 40.0f;
constexpr float PLAYER_HEIGHT = 60.0f;
constexpr float PLAYER_START_X = 380.0f;
constexpr float PLAYER_START_Y = 500.0f;
constexpr float PLAYER_MAX_VELOCITY = 500.0f;
constexpr float PLAYER_ACCELERATION = 300.0f;
constexpr float PLAYER_DECELERATION = 150.0f;
constexpr float PLAYER_LANE_CHANGE_SPEED = 200.0f;
constexpr float PLAYER_INITIAL_HEALTH = 100.0f;

// ============================================
// CONFIGURACIÓN DE ENEMIGOS
// ============================================
constexpr float ENEMY_WIDTH = 40.0f;
constexpr float ENEMY_HEIGHT = 60.0f;
constexpr float ENEMY_INITIAL_SPEED = 150.0f;
constexpr int NUM_LANES = 3;
constexpr float LANE_WIDTH = WINDOW_WIDTH / NUM_LANES;

// ============================================
// CONFIGURACIÓN DE SPAWNER
// ============================================
constexpr float BASE_SPAWN_INTERVAL = 2.0f;
constexpr float MIN_SPAWN_INTERVAL = 0.5f;
constexpr float DIFFICULTY_INCREASE_TIME = 30.0f; // Aumentar cada 30 segundos
constexpr float DIFFICULTY_MULTIPLIER = 0.1f;

// ============================================
// CONFIGURACIÓN DE PUNTUACIÓN
// ============================================
constexpr int POINTS_PER_SECOND = 1;
constexpr int POINTS_PER_SPEED_UNIT = 1;
constexpr int NEAR_MISS_BONUS = 50;
constexpr int COLLISION_PENALTY = 100;
constexpr float COLLISION_DAMAGE = 50.0f;
constexpr float NEAR_MISS_THRESHOLD = 150.0f;

// ============================================
// CONFIGURACIÓN VISUAL
// ============================================
namespace Colors
{
    // SFML Colors: sf::Color::Red, sf::Color::Green, etc.
    // Player color: GREEN (0, 255, 0)
    // Enemy color: RED (255, 0, 0)
    // Background: BLACK (0, 0, 0)
    // UI text: WHITE (255, 255, 255)
    // Road lines: WHITE (255, 255, 255)
    // Lane dividers: YELLOW (255, 255, 0)
}

// ============================================
// CONFIGURACIÓN DE ASSETS (futuro)
// ============================================
constexpr const char* FONT_PATH = "assets/fonts/arial.ttf";
constexpr const char* PLAYER_SPRITE_PATH = "assets/cars/player.png";
constexpr const char* ENEMY_SPRITE_PATH = "assets/cars/enemy_red.png";
constexpr const char* ROAD_BG_PATH = "assets/road/road_bg.png";

// ============================================
// CONFIGURACIÓN DE AUDIO (futuro)
// ============================================
constexpr const char* MENU_MUSIC = "assets/music/menu.ogg";
constexpr const char* GAME_MUSIC = "assets/music/game.ogg";
constexpr const char* COLLISION_SOUND = "assets/audio/collision.ogg";
constexpr const char* NEAR_MISS_SOUND = "assets/audio/near_miss.ogg";

// ============================================
// DIFICULTADES (para futuras extensiones)
// ============================================
enum class Difficulty
{
    EASY = 0,      // Spawn lento, velocidad baja
    NORMAL = 1,    // Spawn medio, velocidad media
    HARD = 2,      // Spawn rápido, velocidad alta
    INSANE = 3     // Spawn muy rápido, velocidad muy alta
};

// ============================================
// TIPOS DE VEHÍCULOS (para futuras extensiones)
// ============================================
enum class VehicleType
{
    SPORTS_CAR = 0,     // Max velocity: 500, Acceleration: 350
    SUV = 1,            // Max velocity: 450, Acceleration: 300
    TRUCK = 2           // Max velocity: 350, Acceleration: 250
};

// ============================================
// MACROS ÚTILES
// ============================================
#define ASSERT(condition) \
    if (!(condition)) { \
        std::cerr << "ASSERTION FAILED: " << #condition << \
                     " at " << __FILE__ << ":" << __LINE__ << std::endl; \
        exit(1); \
    }

#define LOG_INFO(msg) std::cout << "[INFO] " << msg << std::endl
#define LOG_WARNING(msg) std::cout << "[WARNING] " << msg << std::endl
#define LOG_ERROR(msg) std::cerr << "[ERROR] " << msg << std::endl

// ============================================
// EJEMPLO DE USO EN CÓDIGO
// ============================================

/*
#include "Config.hpp"

// En Player.cpp:
Player::Player(float x, float y) {
    body.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
    maxVelocity = PLAYER_MAX_VELOCITY;
    // ...
}

// En GameState.cpp:
void GameState::update(float deltaTime) {
    if (score->getTimeAlive() > 0 && 
        static_cast<int>(score->getTimeAlive()) % 30 == 0) {
        spawner->increaseDifficulty();
    }
}

// Agregar asset cuando esté disponible:
if (!ui.loadFont(FONT_PATH)) {
    LOG_ERROR("Cannot load font: " << FONT_PATH);
}
*/

#endif
