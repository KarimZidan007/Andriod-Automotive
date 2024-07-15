cc=gcc
src =$(wildcard *.c)
obj =$(src:.c=.o)

projectname=iti.elf
INC = -I ./Includes #searching for include

all:$(projectname)

%.o :%.c
	$(cc) $(INC) -c $<

$(projectName) : $(obj)
	$(cc) $(INC) $^ -o $@


clean:
	rm *.o
	rm iti.elf
