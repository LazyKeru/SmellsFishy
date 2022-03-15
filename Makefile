# Variables
# Directory flow
INC_DIR := ./header/
SRC_DIR := ./src/
BIN_DIR := ./bin/
BUILD_DIR := ./build/

# Location of cpp files and object list
## CPP location
MAIN_LIST := ${SRC_DIR}main.cpp
TEST_LIST := $(wildcard ${SRC_DIR}test/*.cpp)
SRC_LIST := $(filter-out ${TEST_LIST}, $(wildcard ${SRC_DIR}*/*.cpp))
## Object location
OBJ_MAIN_LIST := $(addprefix $(BUILD_DIR), $(notdir $(MAIN_LIST:.cpp=.o)))
OBJ_TEST_LIST := $(addprefix $(BUILD_DIR), $(notdir $(TEST_LIST:.cpp=.o)))
OBJ_SRC_LIST := $(addprefix $(BUILD_DIR), $(notdir $(SRC_LIST:.cpp=.o)))

ifdef OS
   RM = del /Q *.o
else
   ifeq ($(shell uname), Linux)
      RM = rm -f *.o 
   endif
endif

# Variables for tools
CXXFLAGS:= -Wall
INCLUDES:= -I${INC_DIR}
CXX := g++
LD := g++

test: compile_src compile_test
	${LD} $(notdir $(TEST_LIST:.cpp=.o)) $(notdir $(SRC_LIST:.cpp=.o)) -o $(BIN_DIR)/$@

main: compile_src compile_main
	${LD} $(notdir $(TEST_LIST:.cpp=.o)) $(notdir $(SRC_LIST:.cpp=.o)) -o $(BIN_DIR)/$@

# As of now it builds in root
compile_src:
	$(CXX) $(CXXFLAGS) -c $(SRC_LIST)

# As of now it builds in root
compile_test:
	$(CXX) $(CXXFLAGS) -c $(TEST_LIST)

# As of now it builds in root
compile_main:
	$(CXX) $(CXXFLAGS) -c $(MAIN_LIST)

clean:
	$(RM)