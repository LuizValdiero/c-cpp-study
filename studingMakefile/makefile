##
#target: prerequisetes
#	recipe	
##

# https://gcc.gnu.org/onlinedocs/

# "make -> monta somente printly

all: printly

printly: main.o helloWorld.o
	gcc -o printly main.o helloWorld.o

main.o: main.c helloWorld.h
	gcc -o main.o main.c -c -w -Wall -ansi -pedantic

helloWorld.o: helloWorld.c helloWorld.h
	gcc -o helloWorld.o helloWorld.c -c -w -Wall -ansi -pedantic

clean:
	rm -rf *.o *~ printly
