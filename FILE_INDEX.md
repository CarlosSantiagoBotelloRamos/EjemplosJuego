# 📑 Índice de Archivos - Traffic Racer

## 📚 Documentación Principal

| Archivo | Descripción |
|---------|-------------|
| `TRAFFIC_RACER_README.md` | 📖 Documentación completa del proyecto |
| `PROJECT_SUMMARY.md` | 📊 Resumen visual y estadísticas |
| `QUICK_START.md` | 🚀 Guía rápida de compilación |
| `FILE_INDEX.md` | 📑 Este archivo - Índice de archivos |
| `TODO.md` | ✅ Lista de tareas completadas/pendientes |

---

## 🎮 Archivos de Juego

### Headers (Interfaz)

**Núcleo del Motor**
- `include/State.hpp` - Base class para todos los estados (64 líneas)
- `include/GameEngine.hpp` - Motor principal del juego (42 líneas)

**Estados del Juego**
- `include/MenuState.hpp` - Menú principal (22 líneas)
- `include/GameState.hpp` - Lógica principal de juego (32 líneas)
- `include/GameOverState.hpp` - Pantalla de fin de juego (25 líneas)
- `include/VehicleSelectState.hpp` - Selección de vehículo (18 líneas)
- `include/MapSelectState.hpp` - Selección de mapa (18 líneas)

**Lógica de Juego**
- `include/Player.hpp` - Vehículo del jugador (30 líneas)
- `include/EnemyCar.hpp` - Vehículos enemigos (25 líneas)
- `include/Spawner.hpp` - Generador de tráfico (24 líneas)
- `include/Score.hpp` - Sistema de puntuación (26 líneas)
- `include/Collision.hpp` - Detección de colisiones (11 líneas)
- `include/UI.hpp` - Interfaz gráfica (22 líneas)

**Utilidades y Futuro**
- `include/Config.hpp` - Constantes de configuración (150+ líneas)
- `include/SpriteManager.hpp` - Gestor de sprites (38 líneas)
- `include/InputHandler.hpp` - Gestor de entrada (35 líneas)

**Legado**
- `include/GameWindow.hpp` - Clase GameWindow (SFML wrapper)
- `include/Ground.hpp` - Suelo del juego
- `include/Ball.hpp` - Bola (ejemplos anteriores)

### Implementaciones (Código)

**Motor Principal** (`core/`)
- `core/GameEngine.cpp` - Implementación del motor (97 líneas)

**Lógica de Juego** (`core/`)
- `core/Player.cpp` - Lógica del jugador (140 líneas)
- `core/EnemyCar.cpp` - Lógica de enemigos (55 líneas)
- `core/Spawner.cpp` - Generador de tráfico (105 líneas)
- `core/Score.cpp` - Sistema de puntuación (65 líneas)
- `core/Collision.cpp` - Detección de colisiones (32 líneas)
- `core/UI.cpp` - Interfaz gráfica (65 líneas)

**Estados del Juego** (`states/`)
- `states/MenuState.cpp` - Menú principal (75 líneas)
- `states/GameState.cpp` - Juego principal (165 líneas)
- `states/GameOverState.cpp` - Pantalla de fin (80 líneas)
- `states/VehicleSelectState.cpp` - Selección vehículo (70 líneas)
- `states/MapSelectState.cpp` - Selección mapa (70 líneas)

**Punto de Entrada** (`src/`)
- `src/main.cpp` - Función main (25 líneas)
- `src/00_Ventana.cpp` - Ejemplos anteriores
- `src/01_Imagen.cpp` - Ejemplos anteriores
- (y otros archivos de ejemplos)

---

## 🔧 Configuración

### VS Code Configuration (`.vscode/`)
- `launch.json` - Configuración de debugger
- `tasks.json` - Tareas de compilación
- `settings.json` - Configuración del editor

### Scripts de Setup
- `setup.bat` - Script para Windows CMD
- `setup.ps1` - Script para Windows PowerShell

### Build System
- `makefile` - Reglas de compilación (95 líneas)

---

## 📁 Estructura de Carpetas

```
🗂️ EjemplosJuego/
│
├── 📄 Documentación
│   ├── TRAFFIC_RACER_README.md        (Documentación completa)
│   ├── PROJECT_SUMMARY.md              (Resumen del proyecto)
│   ├── QUICK_START.md                  (Guía rápida)
│   ├── FILE_INDEX.md                   (Este archivo)
│   ├── TODO.md                         (Tareas)
│   └── LICENSE                         (Licencia)
│
├── 📂 include/                         (Headers - 25+ archivos)
│   ├── State.hpp                       (Base para estados)
│   ├── GameEngine.hpp                  (Motor del juego)
│   ├── MenuState.hpp, GameState.hpp, GameOverState.hpp
│   ├── VehicleSelectState.hpp, MapSelectState.hpp
│   ├── Player.hpp, EnemyCar.hpp
│   ├── Spawner.hpp, Score.hpp
│   ├── Collision.hpp, UI.hpp
│   ├── Config.hpp                      (Configuración)
│   ├── SpriteManager.hpp               (Gestor de sprites)
│   ├── InputHandler.hpp                (Gestor de entrada)
│   └── (Archivos legados)
│
├── 📂 core/                            (Implementación - 7 archivos)
│   ├── GameEngine.cpp
│   ├── Player.cpp, EnemyCar.cpp
│   ├── Spawner.cpp, Score.cpp
│   ├── Collision.cpp, UI.cpp
│
├── 📂 states/                          (Estados - 5 archivos)
│   ├── MenuState.cpp
│   ├── GameState.cpp
│   ├── GameOverState.cpp
│   ├── VehicleSelectState.cpp
│   └── MapSelectState.cpp
│
├── 📂 src/                             (Punto de entrada)
│   ├── main.cpp                        (Función main del juego)
│   ├── 00_Ventana.cpp                  (Ejemplos anteriores)
│   └── (Otros ejemplos)
│
├── 📂 assets/                          (Recursos de juego)
│   ├── fonts/
│   │   └── arial.ttf                   (⚠️ REQUERIDO)
│   ├── cars/                           (Sprites de vehículos)
│   ├── road/                           (Texturas de carretera)
│   ├── ui/                             (Elementos de UI)
│   ├── audio/                          (Efectos de sonido)
│   └── music/                          (Música de fondo)
│
├── 📂 obj/                             (Archivos compilados - GENERADO)
│   ├── GameEngine.o
│   ├── Player.o, EnemyCar.o, ...
│   └── (13 archivos .o)
│
├── 📂 bin/                             (Ejecutables - GENERADO)
│   └── TrafficRacer.exe                (Juego ejecutable)
│
├── 📂 .vscode/                         (VS Code Configuration)
│   ├── launch.json                     (Debug setup)
│   ├── tasks.json                      (Build tasks)
│   └── settings.json                   (Editor settings)
│
├── 📂 docs/                            (Documentación adicional)
│   ├── extensiones.md
│   ├── fork.md
│   ├── herramientas.md
│   ├── librerias.md
│   ├── path.md
│   └── images/
│
├── 📝 makefile                         (Build system)
├── 📝 setup.bat                        (Setup Windows CMD)
├── 📝 setup.ps1                        (Setup Windows PowerShell)
└── 📝 LICENSE                          (Licencia del proyecto)
```

---

## 📊 Estadísticas de Código

| Categoría | Archivos | Líneas | Promedio |
|-----------|----------|--------|----------|
| Headers | 12 | ~450 | 37.5 |
| Core Implementation | 7 | ~650 | 92.8 |
| States Implementation | 5 | ~460 | 92 |
| Main | 1 | 25 | 25 |
| **TOTAL** | **25** | **~1,585** | **63.4** |

---

## 🔗 Relaciones Entre Archivos

```
main.cpp
    ↓
GameEngine.hpp/cpp
    ├── State.hpp (Base class)
    │   ├── MenuState.hpp/cpp
    │   ├── VehicleSelectState.hpp/cpp
    │   ├── MapSelectState.hpp/cpp
    │   ├── GameState.hpp/cpp
    │   │   ├── Player.hpp/cpp
    │   │   ├── Spawner.hpp/cpp
    │   │   │   └── EnemyCar.hpp/cpp
    │   │   ├── Collision.hpp/cpp
    │   │   ├── Score.hpp/cpp
    │   │   └── UI.hpp/cpp
    │   └── GameOverState.hpp/cpp
    │
    └── Config.hpp (Constantes globales)
```

---

## 🚀 Flujo de Ejecución

```
main.cpp
    ↓
GameEngine::run()
    ├── handleInput()      ← Lee controles del usuario
    ├── update()           ← Actualiza lógica (deltaTime)
    └── render()           ← Dibuja en pantalla
        ↓
    Stack de Estados (LIFO)
    ├── Actual: MenuState  ← Procesa inputs/actualiza/renderiza
    └── Anterior: (ninguno)
```

---

## 📝 Líneas de Código Por Archivo

### Headers
| Archivo | Líneas |
|---------|--------|
| State.hpp | 20 |
| GameEngine.hpp | 42 |
| MenuState.hpp | 22 |
| GameState.hpp | 32 |
| GameOverState.hpp | 25 |
| VehicleSelectState.hpp | 18 |
| MapSelectState.hpp | 18 |
| Player.hpp | 30 |
| EnemyCar.hpp | 25 |
| Spawner.hpp | 24 |
| Score.hpp | 26 |
| Collision.hpp | 11 |
| UI.hpp | 22 |
| Config.hpp | 150 |
| SpriteManager.hpp | 38 |
| InputHandler.hpp | 35 |

### Implementaciones
| Archivo | Líneas |
|---------|--------|
| GameEngine.cpp | 97 |
| Player.cpp | 140 |
| EnemyCar.cpp | 55 |
| Spawner.cpp | 105 |
| Score.cpp | 65 |
| Collision.cpp | 32 |
| UI.cpp | 65 |
| MenuState.cpp | 75 |
| GameState.cpp | 165 |
| GameOverState.cpp | 80 |
| VehicleSelectState.cpp | 70 |
| MapSelectState.cpp | 70 |
| main.cpp | 25 |

---

## 🎯 Dónde Encontrar Qué

### Si quieres...

| Quiero... | Ver archivo... |
|-----------|-----------------|
| Cambiar tamaño ventana | `include/Config.hpp` (WINDOW_WIDTH, HEIGHT) |
| Ajustar velocidad del jugador | `core/Player.cpp` o `include/Config.hpp` |
| Cambiar dificultad | `core/Spawner.cpp` o `include/Config.hpp` |
| Modificar HUD | `core/UI.cpp` o `states/GameState.cpp` |
| Cambiar controles | `states/GameState.cpp` (handleInput) |
| Añadir sprites | `include/SpriteManager.hpp` |
| Añadir sonidos | `include/Config.hpp` (paths) |
| Compilar el juego | `makefile` |
| Entender la arquitectura | `PROJECT_SUMMARY.md` |
| Compilar rápidamente | `QUICK_START.md` |

---

## ✨ Características Por Archivo

### Player.cpp
- ✅ Aceleración suave
- ✅ Desaceleración
- ✅ Movimiento lateral
- ✅ Límites de pantalla
- ✅ Sistema de salud

### Spawner.cpp
- ✅ Generación continua
- ✅ Distribución en carriles
- ✅ Variación de velocidad
- ✅ Dificultad dinámica
- ✅ Limpieza de objetos offscreen

### GameState.cpp
- ✅ Lógica de juego
- ✅ Detección de colisiones
- ✅ Detección de near miss
- ✅ Actualización de score
- ✅ Transición a game over

### Score.cpp
- ✅ Puntos por segundo
- ✅ Puntos por velocidad
- ✅ Bonificación near miss
- ✅ Penalización colisión
- ✅ Tracking de estadísticas

---

## 📞 Navegación Rápida

**Para empezar:**
1. Lee `QUICK_START.md`
2. Ejecuta `setup.ps1` o `setup.bat`
3. Abre proyecto en VS Code

**Para entender la arquitectura:**
1. Lee `PROJECT_SUMMARY.md`
2. Estudia diagrama de flujo
3. Examina `include/State.hpp`

**Para extender el juego:**
1. Lee `TODO.md`
2. Consulta `include/Config.hpp`
3. Modifica archivo correspondiente
4. Recompila: `make rebuild`

**Para depurar:**
1. Presiona F5 en VS Code
2. O ejecuta: `gdb ./bin/TrafficRacer.exe`

---

## 🎓 Orden de Lectura Recomendado

### Principiante
1. `QUICK_START.md` - Entender compilación
2. `TRAFFIC_RACER_README.md` - Entender juego
3. `include/State.hpp` - Entender arquitectura
4. `src/main.cpp` - Entender punto de entrada

### Intermedio
1. `PROJECT_SUMMARY.md` - Ver big picture
2. `include/GameEngine.hpp` - Entender motor
3. `states/GameState.cpp` - Entender juego
4. `core/Player.cpp` - Entender jugador

### Avanzado
1. `include/Config.hpp` - Constantes
2. Todos los archivos en `core/` - Entender componentes
3. Todos los archivos en `states/` - Entender flujo
4. `makefile` - Entender compilación

---

## 📈 Dependencias de Compilación

```
main.cpp
    ↓ include
GameEngine.hpp
    ↓ include
State.hpp
    ↓ include
MenuState.hpp, GameState.hpp, GameOverState.hpp, etc.
    ↓ include
Player.hpp, EnemyCar.hpp, Spawner.hpp, Score.hpp, etc.
    ↓ include
Collision.hpp, UI.hpp, Config.hpp
    ↓ link
-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
    ↓
TrafficRacer.exe
```

---

## 🔐 Archivos Críticos (No modificar sin cuidado)

| Archivo | Razón | Si rompes... |
|---------|-------|-------------|
| `makefile` | Build system | El juego no compila |
| `src/main.cpp` | Entry point | El juego no inicia |
| `include/State.hpp` | Base pattern | Los estados no funcionan |
| `core/GameEngine.cpp` | Game loop | El juego se cuelga |

---

Este índice te ayuda a navegar el proyecto. ¡Happy coding! 🎮🏎️

*Última actualización: 2024*
