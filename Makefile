CC = g++
CFLAGS = -Wall -Wextra -municode

build:
	$(CC) $(CFLAGS) ./slaga.cpp ./WinManager.cpp -o app