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
SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/personagem.cpp \
      $(SRC_DIR)/guerreiro.cpp \
      $(SRC_DIR)/bardo.cpp \
      $(SRC_DIR)/inimigo.cpp \
      $(SRC_DIR)/loja.cpp \
      $(SRC_DIR)/item.cpp \
      $(SRC_DIR)/jogo.cpp

# Objetos gerados
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Regras
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.hpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean