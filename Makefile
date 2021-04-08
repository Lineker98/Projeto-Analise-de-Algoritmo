CC = g++
CFLAGS = -g -Wall

TARGET = tp
SOURCE = tp

PATH_LIB = ./libraries/
PATH_ALG = ./algorithm/

LIB = $(PATH_LIB)combination.c $(PATH_LIB)planet.c $(PATH_LIB)escolha_gulosa.c $(PATH_LIB)input_function.c 

ALG = $(PATH_ALG)brute_force.c $(PATH_ALG)guloso.c $(PATH_ALG)dynamic.c 

all: $(TARGET).c 
	$(CC) $(CFLAGS) -o $(SOURCE) $(LIB) $(ALG) $(TARGET).c

clean: 
	$(RM) $(SOURCE) output.txt
