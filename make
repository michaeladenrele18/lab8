CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = matrix_ops
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
