CC = g++

TARGET = main

run: all
	./$(TARGET)

all: main

main: main.o
	$(CC) -o $(TARGET) $(TARGET).o

main.o: main.cpp
	$(CC) -c $(TARGET).cpp

clean:
	rm *.o $(TARGET)