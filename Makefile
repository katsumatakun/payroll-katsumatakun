#Makefile for the payroll reading and output program

OBJ = main.o insert.o myprint.o print_rawdata.o
STRUCTS = linked.h emp_rec.h
HEADERS = insert.h myprint.h print_rawdata.h
all: main

main: $(OBJ)
	gcc -o main $(OBJ)

main.o: main.c $(STRUCTS) $(HEADERS)
	gcc -c main.c

insert.o: insert.c insert.h $(STRUCTS)
	gcc -c insert.c

myprint.o: myprint.c myprint.h $(STRUCTS)
	gcc -c myprint.c

print_rawdata.o: print_rawdata.c print_rawdata.h emp_rec.h
	gcc -c print_rawdata.c

clean:
	rm -rf main *.o
