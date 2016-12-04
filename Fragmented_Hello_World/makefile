# makefile

all: HelloWorld.o Utils.o 
	gcc -o main HelloWorld.o Utils.o 

HelloWorld.o: HelloWorld.c
	gcc -c -o HelloWorld.o HelloWorld.c 

Utils.o: Utils.c
	gcc -c -o Utils.o Utils.c

clean:
	rm -f Utils.o HelloWorld.o main
