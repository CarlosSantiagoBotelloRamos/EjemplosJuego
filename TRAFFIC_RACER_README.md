# Traffic Racer - Juego de Carreras en C++ con SFML

## Descripción

**Traffic Racer** es un juego de carreras tipo arcade desarrollado en C++ utilizando la librería SFML. El jugador controla un automóvil navegando a través del tráfico, evitando colisiones mientras acumula puntos.

## Características del Juego

### Flujo Principal
1. **Menú Principal**: Acceso a iniciar juego, seleccionar vehículo, seleccionar mapa y salir
2. **Selección de Vehículo**: Elige entre 3 tipos de vehículos (Sports Car, SUV, Truck)
3. **Selección de Mapa**: Elige la dificultad del circuito (Highway, City Street, Mountain Road)
4. **Gameplay**: Juega evitando el tráfico y acumulando puntos
5. **Game Over**: Visualiza tu puntuación y elige reiniciar o volver al menú

### Mecánicas de Juego

**Controles**:
- `W` o `↑`: Acelerar
- `S` o `↓`: Frenar
- `A` o `←`: Girar a la izquierda
- `D` o `→`: Girar a la derecha
- `ESC`: Volver al menú durante la partida

**Sistema de Puntuación**:
- +1 punto por segundo vivo
- +Puntos según velocidad actual
- +50 puntos por "Near Miss" (esquivar auto)
- -100 puntos por colisión
- Distancia recorrida en metros
- Registro de velocidad máxima

**Dificultad Dinámica**:
- Aumenta cada 30 segundos
- Más autos spawneados
- Mayor velocidad del tráfico

**Sistema de Salud**:
- Inicia con 100% de salud
- -50% por colisión
- Game Over al llegar a 0%

## Estructura del Proyecto

```
EjemplosJuego/
├── include/              # Headers (.hpp)
│   ├── State.hpp
│   ├── GameEngine.hpp
│   ├── Player.hpp
│   ├── EnemyCar.hpp
│   ├── Collision.hpp
│   ├── Score.hpp
│   ├── Spawner.hpp
│   ├── UI.hpp
│   ├── MenuState.hpp
│   ├── GameState.hpp
│   ├── GameOverState.hpp
│   ├── VehicleSelectState.hpp
│   └── MapSelectState.hpp
├── core/                 # Implementación del motor
│   ├── GameEngine.cpp
│   ├── Player.cpp
│   ├── EnemyCar.cpp
│   ├── Collision.cpp
│   ├── Score.cpp
│   ├── Spawner.cpp
│   └── UI.cpp
├── states/               # Estados del juego
│   ├── MenuState.cpp
│   ├── GameState.cpp
│   ├── GameOverState.cpp
│   ├── VehicleSelectState.cpp
│   └── MapSelectState.cpp
├── src/
│   └── main.cpp          # Punto de entrada
├── assets/               # Recursos (fuentes, imágenes)
│   ├── fonts/
│   │   └── arial.ttf     # NECESARIO: Agregar fuente TTF
│   ├── images/
│   ├── audio/
│   └── music/
├── bin/                  # Ejecutables generados
├── obj/                  # Archivos objeto
├── makefile              # Configuración de compilación
└── README.md             # Este archivo
```

## Requisitos

### Software Requerido
- **MinGW64** (en MSYS2)
- **SFML 2.5.1** o superior
- **Make** (incluido en MSYS2)
- **Visual Studio Code** (recomendado)

### Instalación en MSYS2

#### 1. Instalar SFML
```bash
pacman -S mingw-w64-x86_64-sfml
```

#### 2. Instalar herramientas de compilación
```bash
pacman -S mingw-w64-x86_64-toolchain
pacman -S make
```

## Configuración Inicial

### 1. Crear Carpeta de Assets

Asegúrate de que existe la carpeta `assets/fonts/`:

```bash
mkdir -p assets/fonts
```

### 2. Agregar Fuente TTF

Necesitas agregar una fuente TrueType en `assets/fonts/arial.ttf`. Puedes:

**Opción A**: Copiar desde tu sistema (Windows)
```powershell
Copy-Item "C:\Windows\Fonts\arial.ttf" -Destination "assets\fonts\arial.ttf"
```

**Opción B**: Descargar una fuente libre
- Descarga desde [Google Fonts](https://fonts.google.com/) o [Font Library](https://fontlibrary.org/)
- Coloca el archivo `.ttf` en `assets/fonts/`

## Compilación

### Compilar el Proyecto

```bash
make
```

o para recompilar completamente:

```bash
make rebuild
```

### Limpiar Archivos Generados

```bash
make clean
```

## Ejecución

### Ejecutar el Juego

```bash
make run
```

o directamente:

```bash
./bin/TrafficRacer.exe
```

## Estructura de Clases

### GameEngine
- Motor principal del juego
- Maneja la pila de estados
- Gestiona el loop de juego

### State (Base)
- Clase abstracta para todos los estados
- Métodos: `handleInput()`, `update()`, `render()`

### MenuState
- Menú principal con 4 opciones
- Navegación con flechas UP/DOWN
- Confirmación con ENTER

### VehicleSelectState
- Selección de 3 vehículos
- Navegación con flechas LEFT/RIGHT

### MapSelectState
- Selección de 3 mapas con diferentes dificultades

### GameState
- Estado principal de juego
- Gestiona jugador, tráfico y física
- Detecta colisiones y near misses

### GameOverState
- Pantalla final con estadísticas
- Opción de reiniciar o volver al menú

### Player
- Lógica del vehículo del jugador
- Control de aceleración, frenado, movimiento lateral
- Sistema de salud

### EnemyCar
- Vehículos de tráfico generados dinámicamente
- Movimiento automático hacia adelante

### Spawner
- Generador de tráfico continuo
- Dificultad dinámica
- Variación de velocidades

### Score
- Sistema de puntuación completo
- Tracking de distancia, near misses, colisiones
- Cálculo de bonificaciones

### Collision
- Detección de colisiones AABB
- Cálculo de distancias
- Detección de "near misses"

### UI
- Renderizado de menús y HUD
- Manejo de fuentes
- Dibujado de texto y botones

## Configuración Avanzada

### Modificar Parámetros del Juego

En `core/Player.cpp`:
- `MAX_VELOCITY`: Velocidad máxima del jugador
- `ACCELERATION`: Aceleración
- `DECELERATION`: Desaceleración

En `core/Spawner.cpp`:
- `BASE_SPAWN_INTERVAL`: Intervalo de spawn inicial
- `INITIAL_SPEED`: Velocidad inicial del tráfico

En `states/GameState.cpp`:
- `nearMissThreshold`: Distancia para considerar "near miss"

## Ampliaciones Futuras

- [ ] Añadir sistema de poder-ups
- [ ] Implementar diferentes tipos de carreteras/texturas
- [ ] Sistema de sonido y música
- [ ] Leaderboard
- [ ] Efectos de partículas
- [ ] Diferentes tipos de enemigos
- [ ] Sistema de upgrades

## Solución de Problemas

### Error: "Cannot find SFML"
```
Solución: Asegúrate de tener SFML instalado en MSYS2:
pacman -S mingw-w64-x86_64-sfml
```

### Error: "arial.ttf not found"
```
Solución: Copia una fuente TTF a assets/fonts/arial.ttf
Ver sección "Agregar Fuente TTF" arriba
```

### Error de compilación en VS Code
```
Instala la extensión "C/C++ Extension Pack"
Configura tu carpeta de trabajo como workspace
```

## Licencia

Este proyecto es de código abierto y está disponible bajo la licencia que uses.

## Créditos

Desarrollado con:
- **C++17**
- **SFML 2.5.1**
- **MinGW64** (MSYS2)
- **Visual Studio Code**

---

¡Disfruta jugando Traffic Racer!
