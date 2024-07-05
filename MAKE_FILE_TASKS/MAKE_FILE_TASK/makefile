CC=gcc
INCS= -I ./INCLUDES
CFLAGS= -c
SOURCE_F =game.c main.c
BINDIR = bin

STR=./bin/$@
STRB=./bin/$^
vpath %.h ./INCLUDES
vpath %.c ./src/
vpath %.o ./bin/

OBJ = $(foreach file,$(SOURCE_F),$(patsubst %.c,%.o,$(file)))

App.out: $(OBJ)
	$(CC) ./bin/*.o -o ./build/$@ 
%.o:%.c
	$(CC) $(CFLAGS) $(INCS) $^ -o $(STR)
	


.phony: clean
clean:
	rm ./bin/*.o ./build/*.out
