ARM=arm-none-eabi-gcc 
VAR2=$(wildcard main.?)

COMPILER=gcc

%.o:%.c
	${COMPILER} -c $^
MYHOST: *.o
	${COMPILER} $^
	echo ${VAR2}

.PHONY:clean
clean:
	rm *.o *.out
