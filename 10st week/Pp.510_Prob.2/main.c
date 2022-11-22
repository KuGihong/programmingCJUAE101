#include<stdio.h>
#include<stdlib.h>

#define LENGTH 5	//The train's length

typedef struct train Train;	//Redefine the struct train with Train

struct train
{
	int nSeats;		//Train's seats
	Train* nNext;	//A pointer to connect a train seat
};

void Memory_Check(Train* Memory)	//Funtion: Check memory
{
	if (Memory == NULL)	//Handle exceptions for low memory situations
	{
		printf("Out of memory..\n");
		exit(1);	//Exit
	}
}

int main(void)
{
	Train* nHead = NULL;	//Initialize structure head
	Train* nTail = NULL;	//Initialize structure tail
	
	for (int i = 0; i < LENGTH; i++)	//Repeat for length
	{
		if (nHead == NULL)	//if head 0
		{
			nHead = nTail = (Train*)malloc(sizeof(Train));	//Dynamic Train assignment and head to nHead
			Memory_Check(nHead);	//Check nHead's memory
		}
		else
		{
			nTail->nNext = (Train*)malloc(sizeof(Train));	//Dynamic Train assignment and head to nTail's nNext
			Memory_Check(nTail);	//Check nTail's memory
			nTail = nTail->nNext;	//Put nTail's nNext on nTail
		}
	}

	free(nHead, nTail);	//Initialize memorys

	return 0;
}