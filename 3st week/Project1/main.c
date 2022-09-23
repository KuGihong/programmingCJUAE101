#include <stdio.h>

int main(void)

{
	int a = 20;    // a값 20 초기화
	int b = 0;     // b값 0 초기화

	if (a > 10)    // a가 10보다 클 경우 
	{
		b = a;     // b에 a 대입

	}

	printf("a : %d, b : %d\n", a, b);   // a, b값 출력

	return 0;

}