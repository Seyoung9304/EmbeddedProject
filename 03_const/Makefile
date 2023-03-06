help:
	@echo "enter: make all"

main.o: main.c hyundai.h
	gcc -c main.c

all: main.o
	gcc -o main.exe main.o
	./main.exe

clean:
	del main.o
	del main.exe