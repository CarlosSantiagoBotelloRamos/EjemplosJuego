# Guía Rápida de Compilación - Traffic Racer

## 🚀 Inicio Rápido (5 minutos)

### Opción 1: Script Automático (RECOMENDADO)

#### En PowerShell (Windows):
```powershell
# Ejecuta el script de setup
.\setup.ps1
```

#### En CMD (Windows):
```cmd
setup.bat
```

#### En Bash (MSYS2):
```bash
# Crear carpetas
mkdir -p assets/fonts bin obj

# Copiar fuente
cp /c/Windows/Fonts/arial.ttf assets/fonts/

# Compilar
make rebuild
```

### Opción 2: Compilación Manual

```bash
# 1. Asegúrate de tener SFML y MinGW64 instalados
pacman -S mingw-w64-x86_64-sfml mingw-w64-x86_64-toolchain make

# 2. Crea carpetas necesarias
mkdir -p assets/fonts bin obj

# 3. Copia una fuente TTF a assets/fonts/arial.ttf
#    (descarga desde https://fonts.google.com o copia de Windows)

# 4. Compila el proyecto
make rebuild

# 5. Ejecuta
./bin/TrafficRacer.exe
```

---

## 📋 Requisitos Previos

### Windows con MSYS2

```bash
# Abre MSYS2 MinGW 64-bit y ejecuta:
pacman -S mingw-w64-x86_64-toolchain
pacman -S mingw-w64-x86_64-sfml
pacman -S make
```

### Verificar instalación
```bash
g++ --version
make --version
```

---

## 🎮 Ejecución

### Opción 1: Make
```bash
make run
```

### Opción 2: Ejecutable directo
```bash
./bin/TrafficRacer.exe
```

### Opción 3: VS Code
- Presiona `Ctrl+Shift+B` para compilar
- Presiona `F5` para ejecutar en debug
- O usa la terminal integrada: `make run`

---

## 🗂️ Estructura de Archivos Generados

```
EjemplosJuego/
├── obj/                    # Archivos compilados
│   ├── GameEngine.o
│   ├── Player.o
│   ├── EnemyCar.o
│   ├── ...
│   └── main.o
├── bin/
│   └── TrafficRacer.exe    # Ejecutable final
├── assets/
│   └── fonts/
│       └── arial.ttf       # Fuente necesaria
├── .vscode/                # Configuración VS Code
│   ├── launch.json         # Debug config
│   ├── tasks.json          # Tasks config
│   └── settings.json       # Editor config
└── makefile                # Reglas de compilación
```

---

## 🔧 Comandos Disponibles

```bash
# Compilar proyecto completo
make                    # Primera compilación
make rebuild           # Recompilar todo (clean + build)
make clean             # Limpiar archivos generados

# Ejecutar
make run               # Compilar y ejecutar
./bin/TrafficRacer.exe # Ejecutar directamente

# Desarrollo
make                   # Compilar cambios
```

---

## ⚠️ Solución de Problemas

### Error: "Cannot find SFML"
```
SOLUCIÓN: Instala SFML en MSYS2
$ pacman -S mingw-w64-x86_64-sfml
```

### Error: "arial.ttf not found"
```
SOLUCIÓN: Copia una fuente TTF a assets/fonts/arial.ttf

Opción A (Windows):
  copy C:\Windows\Fonts\arial.ttf assets\fonts\arial.ttf

Opción B (MSYS2/Bash):
  cp /c/Windows/Fonts/arial.ttf assets/fonts/

Opción C (Descargar):
  - Ve a https://fonts.google.com/
  - Descarga "Arial", "Roboto" o similar
  - Copia el .ttf a assets/fonts/arial.ttf
```

### Error: "make: command not found"
```
SOLUCIÓN: Instala make en MSYS2
$ pacman -S make
```

### Error: "g++: command not found"
```
SOLUCIÓN: Instala toolchain de MinGW64
$ pacman -S mingw-w64-x86_64-toolchain
```

### La compilación es lenta
```
NOTA: La primera compilación toma ~30 segundos.
Las compilaciones posteriores son rápidas si solo cambias código.
Usa "make clean" si quieres una compilación completa.
```

---

## 📊 Estadísticas de Compilación

**Archivos que se compilan:**
- 7 archivos core (GameEngine, Player, EnemyCar, etc.)
- 5 archivos states (MenuState, GameState, etc.)
- 1 archivo principal (main.cpp)

**Tamaño del ejecutable:** ~5-8 MB
**Tiempo de compilación:** ~20-40 segundos (primera vez)
**Tiempo de ejecución:** Inmediato

---

## 🎮 Cómo Jugar

**Menú Principal:**
- ↑↓ Navegar
- ENTER: Seleccionar
- ESC: Salir

**Selección de Vehículo/Mapa:**
- ← → Cambiar selección
- ENTER: Confirmar
- ESC: Volver

**Durante el Juego:**
- W/↑: Acelerar
- S/↓: Frenar
- A/←: Girar izquierda
- D/→: Girar derecha
- ESC: Volver al menú

**Game Over:**
- ← → Navegar
- ENTER: Seleccionar
- ESC: No disponible

---

## 📚 Documentación

Para más detalles, ver:
- `TRAFFIC_RACER_README.md` - Documentación completa del juego
- `.vscode/launch.json` - Configuración de debug
- `.vscode/tasks.json` - Configuración de tareas
- `include/` - Headers con comentarios
- `makefile` - Reglas de compilación

---

## 💾 Salvar Progreso

El juego **no guarda automáticamente** la partida.
Cada sesión es independiente.

Para agregar guardado:
1. Ver `include/Score.hpp`
2. Implementar serialización de datos
3. Guardar en `game_save.dat` o similar

---

## 🚀 Próximos Pasos

1. **Agregar Assets**
   - Descarga sprites de OpenGameArt.org
   - Copia a `assets/cars/` y `assets/road/`
   - Modifica `Player.cpp` y `GameState.cpp` para usar sprites

2. **Agregar Sonido**
   - Descarga efectos de sonido libres
   - Copia a `assets/audio/`
   - Usa `sf::Sound` en `core/UI.cpp`

3. **Mejorar Gameplay**
   - Ver `TODO.md` para ideas
   - Modificar dificultad en `core/Spawner.cpp`
   - Agregar power-ups en `gameplay/`

---

¡Disfruta desarrollando Traffic Racer! 🎮🏎️
