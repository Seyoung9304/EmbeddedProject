main.o: main.c hyundai.h
	gcc -c main.c

incre.o: incre.c hyundai.h
	gcc -c incre.c

decre.o: decre.c hyundai.h
	gcc -c decre.c

all: main.o incre.o decre.o
	gcc -o main.exe main.o incre.o decre.o
	./main.exe

clean:
	del *.o
	del main.exe