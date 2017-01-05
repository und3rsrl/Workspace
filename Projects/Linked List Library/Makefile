CC=gcc
CFLAGS=-I.
DEPS = linked_lists.h
OBJ = main.o linked_lists.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

LinkedLists: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)