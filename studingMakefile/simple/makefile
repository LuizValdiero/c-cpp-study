##
#target: prerequisetes
#	recipe	
##

# https://gcc.gnu.org/onlinedocs/

# "make -> monta somente printly

PROJ_NAME = printly

# $(wildcard *.c) - select all files .c from directory
C_SOURCE = $(wildcard *.c )
H_SOURCE = $(wildcard *.h )

# copy C_SOURCE variable and replace .c extension to .o for each name
OBJ = $(C_SOURCE:.c=.o)

#compiler
CC = gcc
#flags for compiler
CC_FLAGS = -c -W -Wall -ansi -pedantic

#all: printly
all: $(PROJ_NAME)


# $@ -> target
# $< -> first prerequisite
# $^ -> all prerequisites

#printly: main.o helloWorld.o
#	gcc -o printly main.o helloWorld.o
$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^ 

#main.o: main.c helloWorld.h
#	gcc -o main.o main.c -c -w -Wall -ansi -pedantic
main.o: main.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

#helloWorld.o: helloWorld.c helloWorld.h
#	gcc -o helloWorld.o helloWorld.c -c -w -Wall -ansi -pedantic
%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
#	rm -rf *.o *~ printly
	rm -rf *.o $(PROJ_NAME) *~