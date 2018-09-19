CXX = g++
CXXFLAGS = -std=c++0x -Wall
SRC_DIR=src
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(SRC_DIR)/%.o,$(SRC_FILES))

all: build

build: $(OBJ_FILES)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o build/Blockchain $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	@rm -rf $(OBJ_FILES)
	@rm -rf build
