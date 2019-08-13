##
#target: prerequisetes
#	recipe	
##

# https://gcc.gnu.org/onlinedocs/

# "make -> monta somente printly

PROJ_NAME = printly

# $(wildcard *.c) - select all files .c from directory
C_SOURCE = $(wildcard ./source/*.c )
H_SOURCE = $(wildcard ./source/*.h )

# copy C_SOURCE variable and replace .c extension to .o for each name
#OBJ = $(subst .c, .o, $(subst source, objects, $(C_SOURCE)))
OBJ=$(subst .c,.o,$(subst source,objects,$(C_SOURCE)))

#compiler
CC = gcc
#flags for compiler
CC_FLAGS = -c -W -Wall -ansi -pedantic
# clean target
RM = rm -rf

#all: printly
all: objFolder $(PROJ_NAME)

# $@ -> target
# $< -> first prerequisite
# $^ -> all prerequisites

#printly: main.o helloWorld.o
#	gcc -o printly main.o helloWorld.o
$(PROJ_NAME): $(OBJ)
	@ echo '# Building binary using $(CC) linker: $@ - $^'
	$(CC) $^ -o $@
	@ echo '# Finishing building binary: $@'
	@ echo ' '

#helloWorld.o: helloWorld.c helloWorld.h
#	gcc -o helloWorld.o helloWorld.c -c -w -Wall -ansi -pedantic
./objects/%.o: ./source/%.c ./source/%.h
	@ echo '# Building target using $(CC) compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@


#main.o: main.c helloWorld.h
#	gcc -o main.o main.c -c -w -Wall -ansi -pedantic
./objects/main.o: ./source/main.c $(H_SOURCE)
	@ echo '# Building target using $(CC) compiler: $<'
	$(CC) -o $@ $< $(CC_FLAGS)


objFolder:
	@ mkdir -p objects

clean:
#	rm -rf *.o *~ printly
	rm -rf *.o $(PROJ_NAME) *~ objects

.PHONY: all clean printly
