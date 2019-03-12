#Makefile for the payroll reading and output program

OBJ = payroll.o insert.o print_calculated.o print_rawdata.o
STRUCTS = linked.h emp_rec.h
HEADERS = insert.h print_calculated.h print_rawdata.h
all: payroll

payroll: $(OBJ)
	gcc -o payroll $(OBJ)

payroll.o: payroll.c $(STRUCTS) $(HEADERS)
	gcc -c payroll.c

insert.o: insert.c insert.h $(STRUCTS)
	gcc -c insert.c

print_calculated.o: print_calculated.c print_calculated.h $(STRUCTS)
	gcc -c print_calculated.c

print_rawdata.o: print_rawdata.c print_rawdata.h emp_rec.h
	gcc -c print_rawdata.c

clean:
	rm -rf main *.o
