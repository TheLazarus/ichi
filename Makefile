CC = g++
CFLAGS = -Wall -Wextra -municode
CPP_FILES = Ichi.cpp IchiProcManager.cpp IchiWinManager.cpp
OBJ_FILES = Ichi.o IchiProcManager.o IchiWinManager.o

build: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o app $(OBJ_FILES)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del *.exe
	del *.o

.PHONY: build clean