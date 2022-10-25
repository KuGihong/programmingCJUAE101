#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	MAXIMUM_NUMBER	100
#define NUMBER_SIZE	100

void Random_number(int* nNum, int nSize)	//배열 안에 무작위 정수 생성, 출력 함수
{
	int i;	//임시변수 지정

	srand((unsigned)time(NULL));	//정해진 난수가 아닌 무작위의 수를 가져오는 수식

	printf("\nRandom Array:\n");
	for (int i = 0; i < nSize; i++)	//nSize만큼 반복
	{
		nNum[i] = rand() % NUMBER_SIZE;	//nSize만큼 칸마다 100까지의 무작위 정수로 채우기
		printf("%d ", nNum[i]);	//채워진 숫자 출력
	}
	printf("\n");
}

void Descending(int* nNum, int nSize)	//내림차순 함수
{
	int i, j;	//임시 변수
	int temp = 0;	//임시변수 0으로 초기화
	printf("\nSort In Descending Array:\n");
	for (i = 0; i < nSize; i++)	//i가 0부터 nSize보다 커지기 전까지 i를 증감시키며 반복
	{
		for (j = i; j < nSize; j++)	//j에 i값을 넣고 nSize보다 커지기 전까지 j를 증감시키며 반복
		{
			if (nNum[i] < nNum[j])	//만약 배열의 i번째가 j번째보다 작다면 
			{
				temp = nNum[i];	
				nNum[i] = nNum[j];		//배열의 i번째와 j번째의 자리 바꿈(내림차순 정렬)
				nNum[j] = temp;	
			}
		}
		printf("%d ", nNum[i]);	//배열 값 순서대로 출력
	}
	printf("\n");
}

void Ascending(int *nNum, int nSize)	//오름차순 함수
{
	int i, j;	//임시 변수
	int temp = 0;	//임시변수 0으로 초기화
	printf("\nSort In Ascending Array:\n");
	for (i = 0; i < nSize; i++)	//i가 0부터 nSize보다 커지기 전까지 i를 증감시키며 반복
	{
		for (j = i; j < nSize; j++)	//j에 i값을 넣고 nSize보다 커지기 전까지 j를 증감시키며 반복
		{
			if (nNum[i] > nNum[j])	//만약 배열의 i번째가 j번째보다 크다면 
			{
				temp = nNum[i];
				nNum[i] = nNum[j];		//배열의 i번째와 j번째의 자리 바꿈(오름차순 정렬)
				nNum[j] = temp;
			}
		}
		printf("%d ", nNum[i]);	//배열 값 순서대로 출력
	}
	printf("\n");
}

int main(void)
{
	int nNum[MAXIMUM_NUMBER];	//배열 선언
	int nSize = 0;	//크기 변수 nSize를 0으로 초기화

	printf("Enter an array of a certain size:\n(Input a number greater than 0)\n");
	scanf_s("%d", &nSize);	// 입력값을 nSize에 저장

	if (nSize > 0)	//nSize가 만약 0보다 큰 숫자라면
	{
		Random_number(nNum, nSize);	//무작위 정수로 채운 배열 생성, 출력하는 함수
		Descending(nNum, nSize);	//내림차순으로 정렬하는 함수
		Ascending(nNum, nSize);	//오름차순으로 정렬하는 함수
	}
	else	//다른 값이라면
		printf("Please enter again the size with a number greater than 0..\n");	//다시 입력해주세요 출력

	return 0;	//종료
}