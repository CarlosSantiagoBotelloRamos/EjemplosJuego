# 🏎️ Traffic Racer - Game Development Project

![Traffic Racer Banner]

> A modern 2D arcade racing game developed in **C++17** using **SFML** on **MinGW64/MSYS2**

---

## 🎮 Game Overview

**Traffic Racer** es un juego de carreras estilo arcade donde el jugador controla un vehículo evitando tráfico y acumulando puntos.

### Características Principales
- 🚗 Juego completo funcional con menú, selecciones, gameplay y game over
- 🎯 Sistema de puntuación completo (distancia, velocidad, near misses)
- 🔄 Dificultad dinámica (aumenta cada 30 segundos)
- 🎨 3 carriles de tráfico con generación procedural
- ⌨️ Controles responsivos (teclado - futuro: gamepad)
- 🎨 Arquitectura modular y extensible
- 📦 Fácil de compilar (scripts de setup incluidos)

---

## 🚀 Quick Start

### Windows (Recommended)

```powershell
# Opción 1: Script automático (RECOMENDADO)
.\setup.ps1

# Opción 2: Compilación manual
make rebuild
make run
```

### MSYS2 Bash

```bash
# Setup automático
bash setup.bash

# O manual
make rebuild
./bin/TrafficRacer.exe
```

---

## 📋 Requisitos

### Software
- ✅ **MinGW64** (en MSYS2)
- ✅ **SFML 2.5.1+**
- ✅ **Make**
- ✅ **Visual Studio Code** (opcional, recomendado)

### Instalación MSYS2
```bash
# En MSYS2 MinGW 64-bit:
pacman -S mingw-w64-x86_64-sfml
pacman -S mingw-w64-x86_64-toolchain
pacman -S make
```

### Hardware Mínimo
- CPU: Dual Core @ 1GHz
- RAM: 512 MB
- GPU: Integrada
- OS: Windows 7+

---

## 📁 Project Structure

```
EjemplosJuego/
├── include/              # 15+ header files
├── core/                 # 7 implementation files
├── states/               # 5 state implementations
├── src/main.cpp          # Entry point
├── assets/               # Fonts, images, audio (to add)
├── bin/                  # Compiled executable
├── obj/                  # Object files
├── .vscode/              # VS Code config
├── makefile              # Build system
├── TRAFFIC_RACER_README.md  # Full documentation
├── PROJECT_SUMMARY.md    # Architecture summary
├── QUICK_START.md        # Compilation guide
├── FILE_INDEX.md         # File navigation
└── setup.ps1/setup.bat   # Automatic setup
```

---

## 🎮 Game Controls

| Action | Keyboard |
|--------|----------|
| Navigate Menu | ↑ / ↓ |
| Select Option | ENTER |
| Accelerate | W / ↑ |
| Brake | S / ↓ |
| Turn Left | A / ← |
| Turn Right | D / → |
| Back/Menu | ESC |

---

## 🎯 Game States

```
MenuState
    ↓
VehicleSelectState / MapSelectState
    ↓
GameState (Main Gameplay)
    ├─→ Collision Detected
    └─→ GameOverState
         ├─→ Restart Game
         └─→ Return to Menu
```

---

## 📊 Project Statistics

| Metric | Value |
|--------|-------|
| **Language** | C++17 |
| **Total LOC** | ~1,585 |
| **Classes** | 13 |
| **Compilation Time** | 20-40s |
| **Executable Size** | 5-8 MB |
| **Target FPS** | 60 |
| **Resolution** | 800x600 |

---

## 🏗️ Architecture

The game uses the **State Pattern** for game flow:

```
GameEngine (Main Loop)
    │
    └── StateStack
        └── Current State (Menu/Game/GameOver/etc)
            ├── Input Handling
            ├── Logic Update
            └── Rendering
```

### Key Components

| Component | Purpose |
|-----------|---------|
| **GameEngine** | Main game loop and state management |
| **State** | Base class for all game states |
| **Player** | Player vehicle logic |
| **EnemyCar** | Enemy vehicle logic |
| **Spawner** | Procedural traffic generation |
| **Score** | Scoring system |
| **Collision** | AABB collision detection |
| **UI** | Text rendering and HUD |

---

## 🛠️ Build Commands

```bash
# Compile the project
make

# Full rebuild (clean + compile)
make rebuild

# Compile and run
make run

# Clean build artifacts
make clean

# Check syntax without linking
make check

# Show help
make help
```

---

## 📚 Documentation

| Document | Purpose |
|----------|---------|
| `TRAFFIC_RACER_README.md` | 📖 Complete documentation |
| `PROJECT_SUMMARY.md` | 📊 Architecture & statistics |
| `QUICK_START.md` | 🚀 Compilation guide |
| `FILE_INDEX.md` | 📑 File navigation |
| `TODO.md` | ✅ Tasks & features |

---

## 🔧 VS Code Integration

### Features
- ✅ Syntax highlighting for C++
- ✅ Build tasks (Ctrl+Shift+B)
- ✅ Debug launch (F5)
- ✅ IntelliSense support
- ✅ Problem matcher for errors

### Setup
VS Code configuration is already included in `.vscode/` folder.

---

## 🎮 How to Play

### Menu Navigation
1. Use **UP/DOWN** arrows to select option
2. Press **ENTER** to confirm
3. Press **ESC** to go back

### Vehicle Selection
Choose between 3 vehicles with different speeds

### Map Selection
Select difficulty: Normal, Hard, or Insane

### Gameplay
- Avoid traffic (red cars)
- Accumulate points
- Watch your health
- Reach high scores

### Scoring System
- **+1** points per second alive
- **+Points** based on speed
- **+50** bonus for near miss
- **-100** penalty for collision

---

## 🌟 Features

### Implemented ✅
- [x] Complete game flow
- [x] State management system
- [x] Player controls (accel, brake, steer)
- [x] Traffic generation
- [x] Collision detection
- [x] Scoring system
- [x] Dynamic difficulty
- [x] Menu system
- [x] Game over screen
- [x] VS Code integration
- [x] Automatic setup scripts

### Future Enhancements
- [ ] Asset sprites (cars, roads)
- [ ] Sound effects
- [ ] Background music
- [ ] Power-ups
- [ ] Leaderboard
- [ ] Multiple game modes
- [ ] Gamepad support
- [ ] Visual effects

---

## 🐛 Troubleshooting

### "Cannot find SFML"
```bash
pacman -S mingw-w64-x86_64-sfml
```

### "arial.ttf not found"
```bash
# Option A: Copy from Windows
copy C:\Windows\Fonts\arial.ttf assets\fonts\arial.ttf

# Option B: Download from Google Fonts
# https://fonts.google.com/
```

### "make: command not found"
```bash
pacman -S make
```

### "g++ not found"
```bash
pacman -S mingw-w64-x86_64-toolchain
```

---

## 📖 Learning Resources

### Files to Study
1. **Start**: `src/main.cpp` - Entry point
2. **Then**: `include/State.hpp` - Design pattern
3. **Next**: `core/GameEngine.cpp` - Main loop
4. **Deep**: `states/GameState.cpp` - Gameplay logic

### External Resources
- [SFML Documentation](https://www.sfml-dev.org/)
- [Game Programming Patterns](https://gameprogrammingpatterns.com/)
- [C++ Best Practices](https://github.com/cpp-best-practices/cppbestpractices)

---

## 💾 Save/Load

Currently, the game does **not** save progress. Each session is independent.

To add save functionality:
1. Extend `Score` class with serialization
2. Save to file on game end
3. Load on game start

---

## 🤝 Contributing

Want to improve Traffic Racer? Here are some ideas:

1. **Graphics**: Add sprite artwork
2. **Audio**: Add sound effects and music
3. **Features**: Implement power-ups or new game modes
4. **Performance**: Optimize rendering or physics
5. **Documentation**: Improve code comments

---

## 📄 License

This project is open source. See `LICENSE` file for details.

---

## 🙏 Credits

**Developed with:**
- C++17
- SFML 2.5.1
- MinGW64
- MSYS2
- Visual Studio Code

---

## 📞 Support

### Getting Help
1. Check `QUICK_START.md` for common issues
2. Read `TRAFFIC_RACER_README.md` for detailed documentation
3. Review code comments in `.hpp` files
4. Check `TODO.md` for completed/pending features

### Found a Bug?
1. Check `TODO.md` to see if it's known
2. Review the relevant source file
3. File an issue with reproduction steps

---

## 🎓 What You Learn

This project teaches:
- ✅ Game architecture (State Pattern)
- ✅ 2D game development
- ✅ Object-oriented design
- ✅ SFML graphics library
- ✅ C++ modern features
- ✅ Build systems (Make)
- ✅ Debugging techniques
- ✅ Code organization

---

## 🚀 Next Steps

1. **Run the game**: `make run`
2. **Explore the code**: Check `include/` and `core/`
3. **Read documentation**: Start with `QUICK_START.md`
4. **Extend it**: Add features from `TODO.md`

---

## 📈 Project Status

| Phase | Status | Details |
|-------|--------|---------|
| **Core Gameplay** | ✅ COMPLETE | All main mechanics working |
| **Menu System** | ✅ COMPLETE | All states implemented |
| **Scoring** | ✅ COMPLETE | Full point system |
| **Assets** | ⏳ TODO | Need sprites & audio |
| **Features** | ⏳ TODO | Extensions listed in TODO.md |

---

<div align="center">

### Made with ❤️ in C++17

**Traffic Racer** © 2024

[📖 Full Docs](TRAFFIC_RACER_README.md) • [🚀 Quick Start](QUICK_START.md) • [📑 File Index](FILE_INDEX.md)

</div>

---

*Enjoy Traffic Racer! 🏎️🚗*
