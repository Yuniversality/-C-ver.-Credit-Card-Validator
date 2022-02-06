CC = g++
CFLAGS = -Wall -Werror -std=c++11 -pedantic -O3
OBJ = creditCardValidation.o main.o
EXE = creditCardValidator

all: $(EXE)

$(EXE): $(OBJ)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJ) 

creditCardValidation.o: creditCardValidation.h creditCardValidation.cpp
		$(CC) $(CFLAGS) -c creditCardValidation.cpp -o creditCardValidation.o

main.o: main.cpp
		$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
		rm *.o $(EXE)