
all: main

main: main.o insert.o myprint.o
	gcc -o main main.o insert.o myprint.o

main.o: main.c emp_rec.h linked.h insert.h
	gcc -c main.c

insert.o: insert.c insert.h emp_rec.h linked.h
	gcc -c insert.c

myprint.o: myprint.c myprint.h emp_rec.h linked.h
	gcc -c myprint.c

clean:
	rm -rf main *.o
