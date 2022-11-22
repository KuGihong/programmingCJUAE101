#include<stdio.h>

#pragma warning(disable:6031)	//Ignore C6031 error
#define MAXIMUM_ARRAY	100		//Size of maximum array

int main(void)
{
	FILE* fp = NULL;	//File pointer declaration

	int int_num;		//Variation to store integer
	double double_num;	//Variation to store real number
	int ch;				//Variation to store charactor, declared 'int' to use 'getchar'
	char str[MAXIMUM_ARRAY];		//Ararry to store string

	printf("[Enter the information of the file you want to create..]\n");
	printf("\nInteger: ");	//Input integer
	scanf_s("%d", &int_num);

	printf("Real number: ");	//Input real number
	scanf_s("%lf", &double_num);

	getchar();	//Remove '\n'
	printf("Character: ");	//Input character
	ch = getchar();

	getchar();	//Remove '\n'
	printf("String: ");		//Input string
	gets_s(str, MAXIMUM_ARRAY);

	fopen_s(&fp, "C:\\Users\\kgh36\\Documents\\GitHub\\programmingCJUAE101\\10st week\\Prob_Create_text_file\\test.txt", "w");
	//Create file to write and read

	if (fp == NULL)	//Confirm file opening
	{
		printf("File didn't open..\n");
		return 1;	//Exit
	}
	printf("\n[File open..]\n");
	fprintf(fp, "Integer number: %d\nReal number: %f\nCharcter: %c\nString: %s\n", int_num, double_num, ch, str);
	//File receives data

	printf("\n[Loading file..]\n");
	fscanf_s(fp, "%d %lf %s", &int_num, &double_num, str, MAXIMUM_ARRAY);	//Input data from the file
	printf("\nInteger number: %d\nReal number: %f\nCharcter: %c\nString: %s\n", int_num, double_num, ch, str);
	//Output the data of file
	
	printf("\n[File closed..]\n");
	fclose(fp);	//Close file

	return 0;
}