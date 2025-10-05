# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -IInclude

# Folders
SRC_DIR = Src
OBJ_DIR = Obj
BIN = out

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp) Main.cpp
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

# Default target
all: $(BIN)

# Link executable
$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Compile .cpp into .o inside Obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure Obj/ exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Run program
run: $(BIN)
	
	./$(BIN)

# Clean up
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN)

.PHONY: all clean run
