CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.cc)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRC_FILES))
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cc,$(OBJ_DIR)/test_%.o,$(TEST_FILES))

TARGET = practica_2

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) -o $@ $^

$(TEST_TARGET): $(OBJ_FILES) $(TEST_OBJ_FILES)
	$(CXX) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TEST_OBJ_FILES) $(TARGET)

.PHONY: all clean