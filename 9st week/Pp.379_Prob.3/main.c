#include<stdio.h>

#pragma warning(disable:4996) //Ignore C4996 error
#define MAXIMUM_ARRAY	80	//MAXIMUM array size
#define A	10
#define B	10
#define RES	10

void add_by_pointer(int* pA, int* pB, int* pRes)	//Funtion: Add by pointer
{
	*pRes = *pA + *pB;	//Calculation pA + pB
}

int main(void)
{
	int nA = A, nB = B, nRes = RES;

	add_by_pointer(&nA, &nB, &nRes);	//Funtion: Add by pointer

	printf("%d", nRes);		//print nRes

	return 0;
}