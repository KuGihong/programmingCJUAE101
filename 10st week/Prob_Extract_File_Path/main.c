#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#pragma warning(disable:4996)	//Ignore C4996 error
#define MAXIMUM_ARRAY  256 //Maximum size of array
#define ADD_1   1   //Pointer +1 : To represent a letter after one space

int main(void)
{
	char chFile_path[MAXIMUM_ARRAY] = { 0 };    //Array to file path
    char* pName = NULL; //Pointer of file name
    char* pExtension = NULL;    //Pointer of file extension

	printf("Input the file path: ");
	scanf_s("%s", chFile_path, MAXIMUM_ARRAY);  //Input file path

    pExtension = strrchr(chFile_path, '.');         //Extract file extensions
    printf("\nFile extension: %s\n", pExtension);   //Output file extensions

    pName = strrchr(chFile_path, '\\') + ADD_1; //Extract file name
    pName = strtok(pName, "."); //Remove the last part of the file name

    printf("File name: %s\n", pName);   //Output file name

    system("pause");    //Pause

	return 0;
}