CXX = g++
SRC = src/Hangman.cpp src/hangman_controller.cpp
TARGET = hangman.out

build:
	$(CXX) $(SRC) -o $(TARGET)

clean:
	rm $(TARGET)
