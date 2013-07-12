# G++ Compiler used
CC=g++
CFLAGS=-c
OtherIncludes=-I ../EzWindows/include -I/usr/X11R6/include
Otherlibs=-L/usr/X11R6/lib -lX11 -L../EzWindows/lib -lezwin

all: Hex

Hex: GameOfHex.o 
	$(CC) $(OtherIncludes) $(Otherlibs) GameOfHex.o -o Hex

GameOfHex.o: GameOfHex.cpp
	$(CC) $(CFLAGS) $(OtherIncludes) $(Otherlibs) GameOfHex.cpp
	
clean:
	rm -rf *o Hex

                                                                                                                                                                          
