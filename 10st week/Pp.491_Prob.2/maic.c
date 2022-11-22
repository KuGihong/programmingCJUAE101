#include<stdio.h>

typedef struct	//Redefine structure
{
	int nPrice;
	int nCalorie;
}Cracker;	//Structure is Craker

int main(void)
{
	Cracker Basasak;	//Declare Craker Basasak

	printf("Input the price : ");
	scanf_s("%d", &Basasak.nPrice);	//Input Basasak's price

	if (Basasak.nPrice > 0)	//If nPrice is a positive numbers,
	{
		printf("Input the calories : ");
		scanf_s("%d", &Basasak.nCalorie);	//Input Basasak's calorie

		if (Basasak.nCalorie > 0)	//If nCalorie is a positive numbers,
		{
			printf("The price of Basasak Crakcer : %dwon\n", Basasak.nPrice);	//Output the price
			printf("The calories of Basasak Crakcer : %dkcal\n", Basasak.nCalorie);	//Output the calorie
		}
		else	//Otherwise,
			printf("\nThis is not a valid input..\n");	//Exit
	}
	else	//Otherwise,
	{
		printf("\nThis is not a valid input..\n");	//Exit
	}

	return 0;
}