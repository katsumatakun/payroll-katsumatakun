# payroll

In this homework you are going to create a program that will read a structured
binary file of employee records. You are given **emp_rec.h** which defines the
structure of the data on disk.  You will take as input from command line the
name of the file which is called **emp_recs.bin**.  The file contains unsorted
records which you will read and print out in a convenient form.  You can only read
the file once in the program.  You will next print the records in descending
alphabetical order as well as do some computations on the data (see requirements)
below:

* Must use dynamic memory (ala malloc()) to store records read
* Must have valid Makefile
* Must use at least one typedef in the program
* Must have separate files for functions - would recommend formatted printting
for a function/file and probably a function/file for the sort routine.
* Must use pointers where appropriate (no copy of structures around)
* Must have comments
* Can and recommend using strcmp() for your sort routine
* Don't forget that there may be duplicate last names in the file so must handle
sorting properly
* For each employee must calculate their net bi-weekly pay from their monthly pay (remember
    that bi-weekly pay is not monthly pay divided by 2)
* print out each employees net pay and keep a running sum of total payments so
the accounting dept can see how much they are paying in net wages during the period
as well as the amount they need to pay the government and state in taxes as well as
what their total medical contributions are.
* Must use branches and pull requests in git

## Extra Credit

* Use of doubly linked list for managing and sorting records
