
OBJ = main.o insert.o myprint.o delete_list.o print_rawdata.o
STRUCTS = linked.h emp_rec.h
HEADERS = insert.h myprint.h delete_list.h print_rawdata.h
all: main

main: $(OBJ)
	gcc -o main $(OBJ)

main.o: main.c $(STRUCTS) $(HEADERS)
	gcc -c main.c

insert.o: insert.c insert.h $(STRUCTS)
	gcc -c insert.c

myprint.o: myprint.c myprint.h $(STRUCTS)
	gcc -c myprint.c

print_rawdata.o: print_rawdata.c print_rawdata.h $(STRUCTS)
	gcc -c print_rawdata.c

delete_list.o: delete_list.c delete_list.h $(STRUCTS)
	gcc -c delete_list.c

clean:
	rm -rf main *.o
