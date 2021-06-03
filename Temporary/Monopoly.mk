TempVersion1: test1.o read.o
	gcc test1.o read.o -o TempVersion1

test1.o:
	gcc -c test1.c

read.o:
	gcc -c read.c