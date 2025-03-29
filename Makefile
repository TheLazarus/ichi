CC = g++
CFLAGS = -Wall -Wextra -municode
CPP_FILES = Ichi.cpp IchiProcManager.cpp IchiWinManager.cpp IchiWinProcedure.cpp
OBJ_FILES = Ichi.o IchiProcManager.o IchiWinManager.o IchiWinProcedure.o

build: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o Ichi $(OBJ_FILES)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del *.exe
	del *.o

.PHONY: build clean