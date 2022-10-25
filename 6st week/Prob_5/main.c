#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h> 

#define NUMBER_SIZE		100
#define	ARRAY_SIZE	10

void Random_number(double* verti, double* hori)	//배열에 무작위 실수 생성, 출력
{
	srand(time(NULL));	//시간마다 변하는 무작위 난수

	printf("Vertical direction\n");

	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		verti[i] = (double)rand() / RAND_MAX;	//0부터 1까지의 실수형 난수 생성
		hori[i] = (double)rand() / RAND_MAX;

		if (i % ARRAY_SIZE == 0)	//수직 분포를 10*10 의 형태로 소숫점 2자리까지 출력
		{
			printf("\n");
		}
		printf("%.2f\t", verti[i]);
	}

	printf("\n\nHorizontal diection\n");
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		if (i % ARRAY_SIZE == 0)	//수평 분포를 10*10 의 형태로 소숫점 2자리까지 출력
		{
			printf("\n");
		}
		printf("%.2f\t", hori[i]);
	}
}
void Calculation(double *r, double *V, double *Z, double *K, double *X)	//균등분포된 난수를 표준균등분포로 변경
{
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		while (1)
		{
			V[i] = (sqrt(2 / exp(1.0)) * (2 * r[i] - 1));		//1단계
			Z[i] = V[i] / r[i];									//2단계
			K[i] = 0.25 * (pow(Z[i], 2));						//2단계
			if (K[i] < (1 - r[i]))								//3단계 1번조건 만족 시 55행 이동
			{
				break;
			}
			else if ((K[i] >= (0.259 / r[i]) + 0.35) && (K[i] > -log10(r[i])))	//3단계 2번조건 만족 시
			{
				r[i] = (double)rand() / RAND_MAX;	//난수를 다시 생성
			}
		}
	}
	for (int i = 0; i < 100; i++)	//4단계
	{
		X[i] = 0 + Z[i] * 1.0;		//평균 0, 표준편차 1.0
	}
}

int main(void) 
{
	int nAns;	//대답 저장할 변수
	int nRes = 0;	//결과값(명중률) 저장할 변수
	double Vertical[NUMBER_SIZE];	//수직 변수 배열
	double Horizontal[NUMBER_SIZE];	//수평 변수 배열

	double Verti_V[NUMBER_SIZE] = { 0 };	//수식 계산에 필요한 수직 변수 V 배열
	double Verti_Z[NUMBER_SIZE] = { 0 };	//수식 계산에 필요한 수직 변수 Z 배열
	double Verti_K[NUMBER_SIZE] = { 0 };	//수식 계산에 필요한 수직 변수 K 배열

	double Hori_V[NUMBER_SIZE] = { 0 };		//수식 계산에 필요한 수평 변수 V 배열
	double Hori_Z[NUMBER_SIZE] = { 0 };		//수식 계산에 필요한 수평 변수 Z 배열
	double Hori_K[NUMBER_SIZE] = { 0 };		//수식 계산에 필요한 수평 변수 K 배열

	double Verti_X[NUMBER_SIZE] = { 0 };	//수식 계산에 필요한 수직 변수 X 배열
	double Hori_X[NUMBER_SIZE] = { 0 };		//수식 계산에 필요한 수평 변수 X 배열

	printf("Start a hit-rate calculation program\n(Yes: 1, No: 2)\n");
	while (1)	//반복문
	{
		scanf_s("%d", &nAns);	//입력값 nAns에 저장
		if (nAns == 1)	//nAns가 1이라면
		{
			Random_number(Horizontal, Vertical);	//배열에 0~1사이의 실수형 난수 생성
			Calculation(Vertical, Verti_V, Verti_Z, Verti_K, Verti_X);	//규등 분포를 표준정규분포로 계산
			Calculation(Horizontal, Hori_V, Hori_Z, Hori_K, Hori_X);	//규등 분포를 표준정규분포로 계산

			printf("Vertical variable X is..\n ");
			for (int i = 0; i < 100; i++)
			{
				printf("%.2f\n", Verti_X[i]);	//수직 방향 표준정규분포 출력
			}

			printf("Horizontal variable X is..\n ");
			for (int i = 0; i < 100; i++)
			{
				printf("%.2f\n", Hori_X[i]);	//수평 방향 표준정규분포 출력
			}

			break;	//114행으로 이동
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
	return 0;
}