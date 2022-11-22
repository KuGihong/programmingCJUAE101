#include<stdio.h>

#define NUMBER	4	//The number of ARROW
#define NUMBER_LIMIT	3	//Number's limit of list
#define LIST_2	2	//list number 3
#define ADD	3	//To make YELLOW start from 5


typedef enum { CYAN, MAGENTA, YELLOW = 5, BLACK } COLOR;	//Declaration Enumerations as COLOR
//YELLOW starts with 5, so put it into 5
typedef enum { UP, DOWN, LEFT, RIGHT } ARROW;	//Declaration Enumerations as ARROW

void Direction_Print(int nAns)	//Function: Print direction
{
	COLOR My_Color = { nAns };	//nAns is stored in the sturcture of My_Color
	int c;	//Variable 'c'
	ARROW Direction = UP;	//Initialize structure ARROW of Direction to UP(=0)
	int d = Direction;	//Direction points to 'd'

	for (c = CYAN; c <= BLACK; c++)	//Repeat CYAN(=0) to Black(=6)
	{
		d++;	//Add Direction by 1
		d = d % NUMBER;	//Direction circulationg in order of 1,2,3,0,1,2,3....

		if (c == My_Color)	//If c = My Color
			break;	//Break, move to line 24
	}
	switch (d)	//Select My Color's Direction and output
	{
	case UP:
		printf("Current Direction : UP"); 
		break;
	case DOWN:
		printf("Current Direction : DOWN\n"); 
		break;
	case LEFT:
		printf("Current Direction : LEFT\n"); 
		break;
	case RIGHT:
		printf("Current Direction : RIGHT\n"); 
		break;
	}

}

int main(void)
{
	int nAns;
	printf("Choose my color\n0. CYAN, 1. MAGENTA, 2.YELLOW, 3. BLACK\n: ");
	scanf_s("%d", &nAns);	//Choose my clolor and save in nAns

	if (nAns > NUMBER_LIMIT || nAns < 0)	//If nAns over 3
	{
		printf("Please choose the number in the list\n");
		return 0;	//Exit
	}
	if (nAns >= LIST_2)	//If nAns >= 2, add 2 to nAns(to make YELLOW start from 5)
	{
		nAns += ADD;
		Direction_Print(nAns);	//Print direction
	}
	else
	{
		Direction_Print(nAns);	//Print direction
	}
	return 0;
}