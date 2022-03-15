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

# Looking at the OS to define or RM function 
ifdef OS
   RM = del /Q *.o *.exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -f *.o *.exe 
   endif
endif

# Variables for tools
CXXFLAGS:= -Wall -g -std=c++17
LDFLAGS:= -Wall -g -std=c++17
INCLUDES:= -I${INC_DIR}
CXX := g++
LD := g++

test: $(OBJ_SRC_LIST) $(OBJ_TEST_LIST)
	${LD} $(LDFLAGS) $(OBJ_SRC_LIST) $(OBJ_TEST_LIST) -o $(BIN_DIR)$@

main: $(OBJ_SRC_LIST) $(OBJ_MAIN_LIST)
	${LD} $(LDFLAGS) $(OBJ_SRC_LIST) $(MAIN_LIST) -o $(BIN_DIR)$@

# Compile the cpp files
${BUILD_DIR}%.o: ${SRC_DIR}*/%.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@
# Compile the main files
${BUILD_DIR}main.o: ${SRC_DIR}main.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@


SUBDIRS:= ${BUILD_DIR} ${BIN_DIR}
SUBDIRSCLEAN:=$(addsuffix clean,$(SUBDIRS))

clean: $(SUBDIRSCLEAN)

clean_curdir:
	$(RM)

%clean: %
	$(MAKE) -C $< -f ../Makefile clean_curdir
