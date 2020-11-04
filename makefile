all: maze mazep

maze: maze.c stack.c stack.h
	gcc -Wall -std=c11 -pedantic maze.c stack.c -Iinclude stack.h -o maze 

mazep: maze.c stack.c stack.h
	gcc -Wall -std=c11 -pedantic maze.c stack.c -Iinclude stack.h -o mazep -fopenmp

clean:
	rm maze mazep