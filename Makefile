
all: main

main: main.o
	gcc -o main main.o

main.o: main.c emp_rec.h
	gcc -c main.c

clean:
	rm -rf main *.o
