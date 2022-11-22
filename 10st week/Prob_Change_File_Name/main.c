#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#pragma warning(disable:4996)	//Ignore C4996 error to use strtok
#pragma warning(disable:6053)	//Ignore C6053 error
#define MAXIMUM_ARRAY  256 //Maximum size of array
#define MAXIMUM_NAME    20  //Maximum size of name array
#define ADD_1   1   //Pointer +1 : To represent a letter after one space

int main(void)
{
    char chFile_path[MAXIMUM_ARRAY] = { 0 };    //Array of file path
    char chChange_path[MAXIMUM_ARRAY] = { 0 };  //Array of path to change
    char chChange_name[MAXIMUM_NAME] = { 0 };     //Array of name to change
    char* pName = NULL;         //Pointer of file name
    char* pExtension = NULL;    //Pointer of file extension

    printf("Input the file path: ");
    scanf_s("%s", chFile_path, MAXIMUM_ARRAY);  //Input the file path
    
    printf("Enter the file name for change: ");
    scanf_s("%s", chChange_name, MAXIMUM_NAME); //Input the file name to change
    pExtension = strrchr(chFile_path, '.');     //Extract file extensions
    strcat(chChange_name, pExtension);          //Add file extension after name to change 

    pName = strrchr(chFile_path, '\\') + ADD_1;     //Extract original file name and extension
    pName = strtok(pName, ".");             //Remove extension from with a combined statement file name and extension

    printf("\nChanging File name.. (Original file name: %s)\n", pName); //Output original file name

    strncpy(chChange_path, chFile_path, (int)(strlen(chFile_path) - strlen(pName)));    
    //Remove the last part of file path's file name and store it to change path

    strcat(chChange_path, chChange_name);   //Add changed name after changed path

    printf("\nChanged the file path: %s\n\n", chChange_path);   //Output changed file path

    system("pause");    //Pause

    return 0;
}