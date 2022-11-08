#include <stdio.h>
#include<stdlib.h>

#define START_COMMAND	1	//시작을 입력했을 때의 수
#define END_COMMAND		2	//종료를 입력했을 때의 수
#define SIZE	3	//식의 개수
#define NUMBER	3	//미지수의 개수
#define TURN	1	//식이 몇번째 차례인지 나타내기 위한 수

void Ask(int(*pA)[SIZE], int* pB)	//미지수의 계수를 입력받고 출력하는 함수
{
	printf("\n\t [Calculation]\n\n\tAx + By + Cz = D\n\tAx + By + Cz = D\n\tAx + By + Cz = D\n");
	
	for (int i = 0; i < SIZE; i++)	//임시변수 i, 식의 개수만큼 반복
	{
		printf("\nInput %dst Ax + By + Cz = D\n", i + TURN);	//몇 번째 식인지 출력
		for (int j = 0; j < NUMBER; j++)	//임시변수 j, 미지수의 개수만큼 반복
		{
			if (j == 0)
			{
				printf("->\t\t\tA: ");
			}
			else if (j == 1)
			{
				printf("->\t\t\tB: ");
			}
			else
			{
				printf("->\t\t\tC: ");
			}
			scanf_s("%d", &pA[i][j]);	//순서대로 A,B,C 값을 입력
		}
		printf("->\t\t\tD: ");
		scanf_s("%d", &pB[i]);	//D 값은 B 배열에 입력
	}

	printf("\n\t  [Equations]\n");
	for (int i = 0; i < SIZE; i++)	//입력된 값을 3개의 연립일차방정식의 형태로 출력
	{
		printf("\n\t%dx + %dy + %dz = %d", pA[i][0], pA[i][1], pA[i][2], pB[i]);
	}
}

void Print_Determinant(int(*pA)[SIZE], int* pB)	//계수행렬 출력하는 함수
{
	printf("\n\t [Determinant A]\n");	//A의 계수행렬 출력
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < NUMBER; j++)
		{
			printf("\t%d", pA[i][j]);	//pA행렬 출력
		}
		printf("\n");
	}

	printf("\n\t [Determinant A1]\n");	//A1의 계수행렬 출력
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < NUMBER; j++)
		{
			if (j == 0)
				printf("\t%d", pB[i]);		//첫번째 행을 pB배열로 출력
			else
				printf("\t%d", pA[i][j]);	//나머지 행렬을 pA배열로 출력
		}
		printf("\n");
	}

	printf("\n\t [Determinant A2]\n");	//A2의 계수행렬 출력
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < NUMBER; j++)
		{
			if (j == 1)
				printf("\t%d", pB[i]);		//두번째 행을 pB배열로 출력
			else
				printf("\t%d", pA[i][j]);	//나머지 행렬을 pA배열로 출력
		}
		printf("\n");
	}

	printf("\n\t [Determinant A3]\n");	//A3의 계수행렬 출력
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < NUMBER; j++)
		{
			if (j == 3)
				printf("\t%d", pB[i]);		//세번째 행을 pB배열로 출력
			else
				printf("\t%d", pA[i][j]);	//나머지 행렬을 pA배열로 출력
		}
		printf("\n");
	}
}

void Calculation_Cramer(int(*pA)[SIZE], int* pB)	//크래머 공식을 사용해 계산, 출력하는 함수
{
	double x = 0, y = 0, z = 0;
	double det_A = 0;
	double A1 = 0, A2 = 0, A3 = 0;

	det_A = pA[0][0] * (pA[1][1] * pA[2][2] - pA[1][2] * pA[2][1])	//determinant A 행렬식을 여인수 전개로 계산
		  - pA[0][1] * (pA[1][0] * pA[2][2] - pA[1][2] * pA[2][0])
		  + pA[0][2] * (pA[1][0] * pA[2][1] - pA[1][1] * pA[2][0]);

	if (det_A == 0)	//만약 0이라면
	{
		printf("\nNo solution,,\n");	//해를 구할 수 없으므로 계산 종료
	
	}
	else	//아니라면
	{
		A1 = pB[0] * (pA[1][1] * pA[2][2] - pA[1][2] * pA[2][1])	//배열의 각 요소를 통해 A1 계수행렬 계산
		   - pA[0][1] * (pB[1] * pA[2][2] - pA[1][2] * pB[2])
		   + pA[0][2] * (pB[1] * pA[2][1] - pA[1][1] * pB[2]);

		A2 = pA[0][0] * (pB[1] * pA[2][2] - pA[1][2] * pB[2])	//배열의 각 요소를 통해 A2 계수행렬 계산
		   - pB[0] * (pA[1][0] * pA[2][2] - pA[1][2] * pA[2][0])
		   + pA[0][2] * (pA[1][0] * pB[2] - pB[1] * pA[2][0]);

		A3 = pA[0][0] * (pA[1][1] * pB[2] - pB[1] * pA[2][1])	//배열의 각 요소를 통해 A3 계수행렬 계산
		   - pA[0][1] * (pA[1][0] * pB[2] - pB[1] * pA[2][0])
		   + pB[0] * (pA[1][0] * pA[2][1] - pA[1][1] * pA[2][0]);

		x = A1 / det_A;	//미지수 x의 해 계산
		y = A2 / det_A; //미지수 y의 해 계산
		z = A3 / det_A; //미지수 z의 해 계산

		printf("\nDeterminant A = %.4f", det_A);
		printf("\nDeterminant A1 = %.4f", A1);
		printf("\nDeterminant A2 = %.4f", A2);
		printf("\nDeterminant A3 = %.4f", A3);

		printf("\nx = A1/A = %.4f   y = A2/A = %.4f   z = A3/A = %.4f", x, y, z);	
		printf("\n\n∴ x = %.4f\ty = %.4f\tz = %.4f", x, y, z);		//해를 출력
	}
}

int main(void)
{
	//크래머 공식 사용을 위해 Ax = B의 형태의 행렬을 선언
	int A[SIZE][NUMBER] = { NULL };	//미지수의 계수를 저장할 행렬 선언, 초기화
	int B[SIZE] = { NULL };	//식의 값을 저장할 배열 선언, 초기화
	int nAns = 0;	//대답 저장할 변수

	printf("\n [Calcultaion: Cramer's Rule]");
	printf("\n\n [ON: 1]\t     [OFF: 2]\n\nInput the number: ");

	while(1)	//반복
	{
		scanf_s("%d", &nAns);
		if(nAns == START_COMMAND)	//nAns가 1일 경우
		{
			Ask(A, B);	//미지수의 계수를 입력받고 출력하는 함수

			printf("\n\n[Calculation : Use the Cramer's rule...]\n");

			Print_Determinant(A, B);	//계수행렬 출력하는 함수

			Calculation_Cramer(A, B);	//크래머 공식을 사용해 계산, 출력하는 함수

			printf("\n\n[Retry: 1]\t[OFF: 2]\n\nInput the number: ");
		}
		else if(nAns == END_COMMAND)
		{
			printf("\nOFF..\n");
			break;	//아니라면 반복문 탈출
		}
		else
		{
			printf("\nInput the Number again..");
			break;
		}
	}
	return 0;
}