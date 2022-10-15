#include<stdio.h>

int main(void)
{
	int i, j;                                               //값을 저장할 변수 지정

	printf("Enter multiplication table as number. \n");     //구구단의 수 입력하세요 출력
	scanf_s("%d", &i);                                      //입력한 값을 변수 i에 저장

	for (j = 1; j <= 9; j++)                            //j를 2로 초기화, 2에서 9보다 같거나 작을 동안 반복
	{
		printf("%d * %d = %d\n", i, j, i * j);          //i*j를 반복한 결과값 출력
	}

	return 0;
}