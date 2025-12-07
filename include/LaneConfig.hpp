#ifndef LANE_CONFIG_HPP
#define LANE_CONFIG_HPP

#include <array>

// Configuración de carriles: simétricos respecto al centro de la ventana
// Centro X (ventana 800px): 400
// Separación entre carriles: 80px
// Posiciones: 400 - 1.5d, 400 - 0.5d, 400 + 0.5d, 400 + 1.5d
inline constexpr float WINDOW_CENTER_X = 400.0f;
inline constexpr float LANE_SEPARATION = 50.0f;

inline float getLaneX(int laneIndex)
{
    // laneIndex: 0..3
    // offsets: -1.5, -0.5, +0.5, +1.5
    static constexpr float offsets[4] = { -1.5f, -0.5f, 0.5f, 1.5f };
    if (laneIndex < 0) laneIndex = 0;
    if (laneIndex > 3) laneIndex = 3;
    return WINDOW_CENTER_X + offsets[laneIndex] * LANE_SEPARATION;
}

#endif