# Makefile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++2a

# Target executable
TARGET = find

# Source files
SRCS = main.cpp searchFile.cpp

# Object files
OBJS = $(addprefix obj/, $(notdir $(SRCS:.cpp=.o)))

# Directory for object files
OBJDIR = obj/

all: directories $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJDIR)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

directories: ${OBJDIR}

${OBJDIR}:
	mkdir -p ${OBJDIR}

clean:
	$(RM) -rf $(OBJDIR) $(TARGET)