main: tp3.o main.o
	@gcc -o main tp3.o main.o
	@echo Compiling programm ...

tp3.o: tp3.c
	@gcc -o tp3.o -c tp3.c -Wall -I src/
	@echo Compiling tp3.o ...

main.o: main.c
	@gcc -o main.o -c main.c -Wall
	@echo Compiling main.o ...

clean:
	@rm *.o
	@echo Cleaning Ok
