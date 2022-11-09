#include<stdio.h>
#include<string.h>

#pragma warning(disable:4996) //ignore C4996 error
#define MAXIMUM_ARRAY	80	//maximum array size
#define MAXIMUM_LENGTH	20	//maximum length
#define LENGTH	5	//before print "*"

void Print_Res(char* pStr, char* pRes, char* pStar)	//function: print res
{
	for (int i = 0; i < MAXIMUM_LENGTH; i++)
	{
		strcat(pStar, "*");	//add * in pStar array
	}
	printf("Input word: ");
	scanf_s("%s", pStr, MAXIMUM_ARRAY);	//input string
	
	if (strlen(pStr) > LENGTH)		//sentence's length over 5
	{
		strncpy(pRes, pStr, LENGTH);	//copy pStr to pRes
		pRes[LENGTH] = '\0';	//place NULL at the end of string
		strncat(pRes, pStar, (int)strlen(pStr) - LENGTH);	//add * to the length of the string by the string's length -5
	}
	else
	{
		strcpy(pRes, pStr);
	}
	printf("Enter the word is : %s, Omitted word is : %s\n", pStr, pRes);
}

int main(void)
{
	char chStr[MAXIMUM_ARRAY] = { NULL };	//string array
	char chRes[MAXIMUM_ARRAY] = { NULL };	//res of string array
	char chStar[MAXIMUM_ARRAY] = "*";		//"*" array
	
	Print_Res(chStr, chRes, chStar);	//function: print res
	
	return 0;
}