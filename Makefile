CC=g++
CFLAGS=-Wall -std=c++11
LDFLAGS=
SOURCES=main.cpp steamid.cpp
EXECUTABLE=steamid-converter

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

