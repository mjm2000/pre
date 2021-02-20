CC=gcc
CFLAGS=-I

all: csv  
	./build/csv $(ARGS) file.csv 

csv: csv.o
	$(CC) -o build/csv build/csv.o
	

csv.o: src/csv.c 
	$(CC) -o build/csv.o -c  src/csv.c 

clean:
	rm build/*
 



