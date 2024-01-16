CXX = g++
CXXFLAGS = -std=c++11 -Wall -ansi -pedantic #-DMAP

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRCS = \
	$(SRC_DIR)/Main.cpp \
	$(SRC_DIR)/Catalogue.cpp \
	$(SRC_DIR)/Trajet.cpp \
	$(SRC_DIR)/TrajetSimple.cpp \
	$(SRC_DIR)/TrajetCompose.cpp \
	$(SRC_DIR)/Noeud.cpp \
	$(SRC_DIR)/Liste.cpp \
	$(SRC_DIR)/GestionFichier.cpp 

OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
TARGET = $(BIN_DIR)/trajets

all: directories $(TARGET)

directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/*.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

