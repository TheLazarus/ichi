CC = g++
CFLAGS = -Wall -Wextra -municode
LIBS = -lole32 -lcomctl32 -loleaut32 -luuid
CPP_FILES = Ichi.cpp IchiProcManager.cpp IchiWinManager.cpp IchiWinProcedure.cpp
OBJ_FILES = Ichi.o IchiProcManager.o IchiWinManager.o IchiWinProcedure.o

all: clean build
	
build: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o Ichi $(OBJ_FILES) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del *.exe
	del *.o

.PHONY: all clean