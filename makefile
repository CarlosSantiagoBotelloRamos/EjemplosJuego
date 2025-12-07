# Directorios de origen y destino
SRC_DIR := src
CORE_DIR := core
STATES_DIR := states
GAMEPLAY_DIR := gameplay
BIN_DIR := bin

# Bibliotecas SFML
SFML := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Directorios de inclusión
INCLUDES := -Iinclude

# Compilador y flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -O2

# Archivos objeto
OBJ_DIR := obj
OBJECTS := $(addprefix $(OBJ_DIR)/, \
	GameEngine.o Player.o EnemyCar.o Collision.o UI.o Spawner.o Score.o \
	MenuState.o GameState.o GameOverState.o VehicleSelectState.o MapSelectState.o \
	main.o CarSprite.o)

# Ejecutable principal
EXECUTABLE := $(BIN_DIR)/TrafficRacer.exe

# Regla por defecto
all: $(EXECUTABLE)

# Crear el ejecutable
$(EXECUTABLE): $(OBJECTS) | $(BIN_DIR)
	@echo "Linking executable..."
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(SFML)
	@echo "[SUCCESS] Build complete: $(EXECUTABLE)"

# Compilar archivos objeto de src/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compilar archivos objeto de core/
$(OBJ_DIR)/%.o: $(CORE_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compilar archivos objeto de states/
$(OBJ_DIR)/%.o: $(STATES_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compilar archivos objeto de gameplay/
$(OBJ_DIR)/%.o: $(GAMEPLAY_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Crear directorios
$(OBJ_DIR):
	@mkdir -p $@

$(BIN_DIR):
	@mkdir -p $@

# Limpiar archivos generados
clean:
	@echo "Cleaning build files..."
	@rm -rf $(OBJ_DIR)
	@rm -f $(EXECUTABLE)
	@echo "[SUCCESS] Clean complete"

# Ejecutar el programa
run: $(EXECUTABLE)
	@echo "[INFO] Running Traffic Racer..."
	@$(EXECUTABLE)

# Recompilar todo
rebuild: clean all

# Ayuda
help:
	@echo ""
	@echo "Traffic Racer - Build Commands"
	@echo "==============================="
	@echo ""
	@echo "  make              - Compile project"
	@echo "  make rebuild      - Clean and compile"
	@echo "  make run          - Compile and run"
	@echo "  make clean        - Remove build files"
	@echo "  make help         - Show this help"
	@echo ""

# Verificar compilación sin linking
check:
	@echo "Checking compilation..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -fsyntax-only $(SRC_DIR)/*.cpp
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -fsyntax-only $(CORE_DIR)/*.cpp
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -fsyntax-only $(STATES_DIR)/*.cpp
	@echo "[SUCCESS] No syntax errors found"

.PHONY: all clean run rebuild help check
