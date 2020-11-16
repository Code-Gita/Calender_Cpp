output: output.o add.o
		g++ output.o add.o -o output
		rm output.o add.o

add.o:
	g++ -c main.cpp -g -o add.o

output.o: main.cpp Additional.h
		g++ -Wall -std=c++11 -I. -c main.cpp -g  -o output.o

clean:
		rm output output.o	add.o
