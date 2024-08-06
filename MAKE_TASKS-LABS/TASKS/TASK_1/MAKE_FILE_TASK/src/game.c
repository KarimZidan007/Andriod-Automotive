#include <stdlib.h>
#include "game.h"


#define MAX_NUMB 10

void GUESS_GAME ()
{

int GENERATED_NUMB=rand()%MAX_NUMB;
int USER_NUMBER;
printf("ENTER YOUR GUESS NUMBER\n");
scanf("%d",&USER_NUMBER);

if(GENERATED_NUMB==USER_NUMBER)
{
	printf("TRUE GUESS\n");
}
else
{
	printf("WRONG GUESS THE NUMBER IS %d \n",GENERATED_NUMB);
}

}
