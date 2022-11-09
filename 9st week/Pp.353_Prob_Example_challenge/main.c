#include<stdio.h>
#include<string.h>

#pragma warning(disable:4996) //ignore C4996 error 
#define MAXIMUM_ARRAY	80	//maximum array size

void Swap(char* pTemp, char* pStrA, char* pStrB)	//swap function
{;
	if (strcmp(pStrA, pStrB) > 0)	//in the order of the dictionary, if pStrB > pStrA
	{
		strcpy(pTemp, pStrA);
		strcpy(pStrA, pStrB);		//swap StrB to StrA
		strcpy(pStrB, pTemp);
	}
}

int main(void)
{
	char chStr1[MAXIMUM_ARRAY];		//string array1
	char chStr2[MAXIMUM_ARRAY];		//string array2
	char chStr3[MAXIMUM_ARRAY];		//string array3
	char Temp[MAXIMUM_ARRAY];		//temporary array
	
	printf("Input 3 words : ");		//input three words
	scanf_s("%s%s%s", chStr1, MAXIMUM_ARRAY, chStr2, MAXIMUM_ARRAY, chStr3, MAXIMUM_ARRAY);
	
	chStr1[strlen(chStr1)] = '\0';	//place NULL at the end of the three strings
	chStr2[strlen(chStr2)] = '\0';
	chStr3[strlen(chStr3)] = '\0';

	Swap(Temp, chStr1, chStr2);		//sort the 3 words into the preceding words in dictionary order
	Swap(Temp, chStr2, chStr3);	
	Swap(Temp, chStr2, chStr3);

	printf("%s, %s, %s\n", chStr1, chStr2, chStr3); //sorted the three words output 

	return 0;
}