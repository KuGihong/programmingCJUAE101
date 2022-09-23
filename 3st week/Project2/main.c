#include <stdio.h>

int main(void)
{
	int a = 10;     // a값 10으로 초기화

	if (a >= 0)     // a가 0보다 작거나 크면
	{
		a = 1;      // a에 1 대입
	}
	else            // a가 0보다 작으면
	{
		a = -1;     // a에 -1대입
	}

	printf("a : %d\n", a);

	return 0;
}