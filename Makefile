
all: main

main: main.o insert.o
	gcc -o main main.o insert.o

main.o: main.c emp_rec.h linked.h insert.h
	gcc -c main.c

insert.o: insert.c insert.h emp_rec.h linked.h
	gcc -c insert.c

clean:
	rm -rf main *.o
