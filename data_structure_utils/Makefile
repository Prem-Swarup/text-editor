# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Output binary name
TARGET = rope_example

# Source files
SRCS = rope.cpp test.cpp

# Object files (compiled .cpp files)
OBJS = $(SRCS:.cpp=.o)

# Default target: compile and run the program
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile the .cpp files into .o files
%.o: %.cpp Rope.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and the target executable
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
