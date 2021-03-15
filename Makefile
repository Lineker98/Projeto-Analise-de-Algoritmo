CC = g++
CFLAGS = -g -Wall

TARGET = tp
SOURCE = tp

PATH_LIB = ./libraries/
PATH_ALG = ./algorithm/

LIB = $(PATH_LIB)combination.c $(PATH_LIB)planet.c 
ALG = $(PATH_ALG)brute_force.c

all: $(TARGET).c 
	$(CC) $(CFLAGS) -o $(SOURCE) $(LIB) $(ALG) $(TARGET).c

clean: 
	$(RM) $(SOURCE) output.txt
