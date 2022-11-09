#include <stdio.h>

int a, b;	//Global variables

void input_data(int* pa, int* pb)	//Funtion: input data
{
	printf("Input two integer: ");
	scanf_s("%d%d", &a, &b);	//input two integer
}

void swap(void)	//Funtion: swap data
{
	int temp = 0;
	temp = a;		//swap a, b
	a = b;
	b = temp;
}

void print_data(int a, int b)	//Funtion: print data
{
	printf("Output integer: %d, %d\n", a, b);	//print a, b
}

int main(void)
{
	input_data(&a, &b);	//Funtion: input data
	swap();				//Funtion: swap data
	print_data(a, b);	//Funtion: print data

	return 0;
}