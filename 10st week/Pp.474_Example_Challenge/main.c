#include<stdio.h>
#include<stdlib.h>

#define PRIME_NUMBER		2	//For calculating prime numbers
#define COLUMNS_NUMBER		5	//For changing a line
#define NOT_PRIME_NUMBER	1	//A non-decimal number

int main(void)
{
	int nNum;	//Variable to store the answer
	int* pRes;	//Pointer of variable to store the res
	int nCount = 0;	//Initialize variable to count
	int i, j;

	printf("Input a positive number(please input the number more than 2) : ");	//Input a number
	scanf_s("%d", &nNum);	//Save the number to nNum
	
	pRes = (int*)malloc(nNum * sizeof(int));	//Dynamic assignment of pRes

	if (pRes == NULL)	//Handle exceptions for low memory situations
	{
		printf("Out of memory..\n");
		exit(1);	//Exit
	}
	for (i = 0; i <= (nNum - PRIME_NUMBER); i++)
	{
		pRes[i] = i + PRIME_NUMBER;		//Enter the numbers for calculating prime numbers
	}
	for (i = 0; i <= (nNum - PRIME_NUMBER); i++)	//Determining whether it is a prime number
	{
		for (j = PRIME_NUMBER; j <= (nNum - PRIME_NUMBER); j++)
		{
			if ((i + PRIME_NUMBER != j) && ((i + PRIME_NUMBER) % j == 0))	//If it's the same number of a divisible number
			{
				pRes[i] = NOT_PRIME_NUMBER;	//Save 1 in the pRes array
			}
		}
	}
	for (i = 0; i < (nNum - PRIME_NUMBER); i++)	//Output the numbers
	{
		if ((nCount != 0) && (nCount % COLUMNS_NUMBER == 0))	//Every 5 words, changing a line 
		{
			printf("\n");
		}
		nCount++;	//Add count

		if (pRes[i] == NOT_PRIME_NUMBER)	//if pRes == 1, output 'X'
		{
			printf("%5c", 'X');
		}
		else	//Or output the numbers
		{
			printf("%5d", pRes[i]);
		}
	}

	free(pRes);	//Return allocated memory area

	return 0;
}