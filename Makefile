# Makefile para compilar o projeto turn_based_game

# Compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++17 -Wall

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Arquivo final
TARGET = jogo

# Arquivos-fonte
SRC = $(wildcard $(SRC_DIR)/*.cpp)

# Objetos gerados
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Regras
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean