CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

main: main.o
    $(CC) -o main main.o $(LIBS)

main.o: main.c
    $(CC) -c main.c $(CFLAGS)

clean:
    rm -f *.o main
