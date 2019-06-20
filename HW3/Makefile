.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall

all: hw3 hw3a1

hw3: hw3.o SpigotE.o
	gcc -g -o hw3 $(CFLAGS) hw3.o SpigotE.o

hw3a1: hw3.o SpigotEa1.o 
	gcc -g -o hw3a1 $(CFLAGS) hw3.o SpigotEa1.o 

hw3.o: hw3.c
	gcc -c -g -o hw3.o $(CFLAGS) hw3.c

SpigotE.o: SpigotE.c
	gcc -c -g -o SpigotE.o $(CFLAGS) SpigotE.c

SpigotEa1.o: SpigotEa1.S
	as --64 -o SpigotEa1.o SpigotEa1.S

clean:
	rm -f *.o hw3 hw3a1
