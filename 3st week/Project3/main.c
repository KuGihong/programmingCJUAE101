#include <stdio.h>

int main(void)
{
	int a = 0, b = 0;   // a값 0으로 초기화, b값 0으로 초기화

	if (a > 0)          // a가 0보다 크면 
	{
		b = 1;          // b에 1대입
	}
	else if (a == 0)    // a가 0보다 크지 않고 a가 0이면 
	{
		b = 2;          // b에 2 대입
	}
	else                // a가 0보다 크지 않고 0도 아니면
	{
		b = 3;          // b에 3 대입
	}

	printf("b : %d\n", b);

	return 0;
}