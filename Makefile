CC = g++

CFLAGS =-g -Wall

all: prog

bitHandler.o: bitHandler/bitHandler.cpp
	$(CC) $(CFLAGS) -c $^

transmissor.o: transmissor/transmissor.cpp
	$(CC) $(CFLAGS) -c $^

receptor.o: receptor/receptor.cpp
	$(CC) $(CFLAGS) -c $^

meioDeComunicacao.o: meioDeComunicacao/meioDeComunicacao.cpp
	$(CC) $(CFLAGS) -c $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^

prog: main.o bitHandler.o transmissor.o meioDeComunicacao.o receptor.o
	$(CC) main.o bitHandler.o transmissor.o meioDeComunicacao.o receptor.o $(CFLAGS) -o prog 

clean:
	rm *.o prog

run: prog
	./prog
