#include<stdio.h>
#include<string.h>

#pragma warning(disable:4996) //ignore C4996 error
#define MAXIMUM_ARRAY	80	  //maximum array size
#define LENGTH	9	//length of string

int main(void)
{
	char chStr[MAXIMUM_ARRAY] = { NULL };	//Array to store string

	strcpy(chStr, "wine");	//copy "wine"
	strcat(chStr, "apple");	//add "apple"
	strncpy(chStr, "pear", 1);	//copy "p"

	chStr[LENGTH] = '\0';	//add 0 to end of string

	printf("%s, %d\n", chStr, (int)strlen(chStr));	//print str, length of str

	return 0;
}