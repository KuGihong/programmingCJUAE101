#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define M	5	//M의 값
#define N	5	//N의 값
#define NUMBER_SIZE	10	//숫자의 크기

void Random_number(int nNum1[N][M], int nNum2[M][N])	//각각의 2차원 배열에 무작위 정수 생성, 출력 함수
{
	srand((unsigned)time(NULL));	//정해진 난수가 아닌 무작위의 수를 가져오는 수식

	printf("Multiplication of random integer matrices of n x m and m x n:\n\n[The array of n x m]\n");
	for (int i = 0; i < N; i++)	//임시변수 i가 N이 될때까지 i증감
	{
		for (int j = 0; j < M; j++)	//임시변수 j가 M이 될때까지 증감
		{
			nNum1[i][j] = rand() % NUMBER_SIZE;	//첫번째 배열의 행과 열에 각각 한 칸씩 무작위 정수 생성
			printf("%d\t", nNum1[i][j]);	//출력
		}
		printf("\n");	//배열의 행 줄바꿈(사각화)
	}
	printf("\n[The array of m x n]\n");
	
	for (int i = 0; i < M; i++)	//i가 M이 될때까지 증감
	{
		for (int j = 0; j < N; j++)	//j가 N이 될때까지 증감
		{
			nNum2[j][i] = rand() % NUMBER_SIZE;	//두번째 배열의 행과 열에 각각 한 칸씩 무작위 정수 생성

			printf("%d\t", nNum2[j][i]);	//출력
		}
		printf("\n");	//배열의 행 줄바꿈(사각화)
	}
	printf("\n");
}

void Multiply(int nNum1[N][M], int nNum2[M][N], int nRes[N][N])	//두 행렬의 곱을 구하고 출력하는 함수
{
	printf("[Multiplication of the two arrays]\n");
	for (int i = 0; i < N; i++)	//i가 N이 될때까지 증감
	{
		for (int j = 0; j < N; j++)	//j가 M이 될때까지 증감
		{
			for (int k = 0; k < M; k++)	//k가 M이 될때까지 증감
			{
				nRes[i][j] += (nNum1[i][k] * nNum2[k][j]);	//행렬의 곱 계산식
			}
			printf("%d\t", nRes[i][j]);	//행렬의 곱 출력
		}
		printf("\n");	//배열의 행 줄바꿈(사각화)
	}
}

int main(void)
{
	int nNum1[N][M] = { 0 };	//첫번째 행렬 지정
	int nNum2[M][N] = { 0 };	//두번째 행렬 지정
	int nRes[N][N] = { 0 };		//두 행렬의 곱셈 결과를 저장할 배열 지정
	int nAns = 0;	//시작 여부의 대답을 저장할 변수
	
	printf("Do yo want to see this program?(Multiplication of random integer matrices of n x m and m x n)\n(Yes: 1, No: 2)\n");
	while (1)	//반복문
	{
		scanf_s("%d", &nAns);	//입력값 nAns에 저장
		if (nAns == 1)	//nAns가 1이라면
		{
			Random_number(nNum1, nNum2);	//두 행렬을 무작위 정수로 채우고 출력하는 함수
			Multiply(nNum1, nNum2, nRes);	//두 행렬의 곱의 결과를 계산하고 출력하는 함수
			break;	//76행으로 이동
		}
		else if (nAns == 2)	//nAns가 2라면
		{
			printf("Okay..\n");
			return 0;	//종료
		}
		else	//그 외의 경우
		{
			printf("Please enter again 1 or 2\n");	//다시 입력해주세요 출력 후 61행으로 이동
			break;
		}
	}
	return 0;	//종료
}