CC=gcc
FLAGS= -Wall

all: stringProg libfuncs.so

stringProg: main.o libfuncs.so
	$(CC) $(FLAGS) main.o ./libfuncs.so -o stringProg

main.o: main.c funcs.h
	$(CC) $(FLAGS) -c main.c

libfuncs.so: funcs.o
	$(CC) -shared -o libfuncs.so funcs.o

funcs.o: funcs.c funcs.h
	$(CC) $(FLAGS) -c funcs.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg