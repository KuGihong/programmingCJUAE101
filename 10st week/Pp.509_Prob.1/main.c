#include<stdio.h>

#define MAXIMUM_ARRAY 20	//Maximum size of array
#define AGE	22				//Age of "Andy"
#define HEIGHT	187.5		//Height of "Andy"

typedef struct	//Redefine struction
{
	char chName[MAXIMUM_ARRAY]; //Array of name
	int nAge;		//Variable of age
	char chSex;		//Variable of sex
	double Height;	//Variable of height
}Marriage;	//Struction is Marriage

int main(void)
{
	Marriage m1 = { "Andy",AGE,'M',HEIGHT };	//Marriage m1 initialization
	Marriage* mp = &m1;		//Use pointer m1 -> mp

	printf("\t[Profile]\n");
	printf("Name : %s\n", mp->chName);		//Output chName
	printf("Age : %d\n", mp->nAge);			//Output nAge
	printf("Sex : %c\n", mp->chSex);		//Output chSex
	printf("Height : %.1lf\n", mp->Height);	//Output Height

	return 0;
}

