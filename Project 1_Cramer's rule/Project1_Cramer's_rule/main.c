#include <stdio.h>
#include<stdlib.h>

#define START_COMMAND	1	//������ �Է����� ���� ��
#define END_COMMAND		2	//���Ḧ �Է����� ���� ��
#define SIZE	3	//���� ����
#define NUMBER	3	//�������� ����
#define TURN	1	//���� ���° �������� ��Ÿ���� ���� ��

void Ask(int(*pA)[SIZE], int* pB)	//�������� ����� �Է¹ް� ����ϴ� �Լ�
{
	printf("\n\t [Calculation]\n\n\tAx + By + Cz = D\n\tAx + By + Cz = D\n\tAx + By + Cz = D\n");
	
	for (int i = 0; i < SIZE; i++)	//�ӽú��� i, ���� ������ŭ �ݺ�
	{
		printf("\nInput %dst Ax + By + Cz = D\n", i + TURN);	//�� ��° ������ ���
		for (int j = 0; j < NUMBER; j++)	//�ӽú��� j, �������� ������ŭ �ݺ�
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
			scanf_s("%d", &pA[i][j]);	//������� A,B,C ���� �Է�
		}
		printf("->\t\t\tD: ");
		scanf_s("%d", &pB[i]);	//D ���� B �迭�� �Է�
	}

	printf("\n\t  [Equations]\n");
	for (int i = 0; i < SIZE; i++)	//�Էµ� ���� 3���� ���������������� ���·� ���
	{
		printf("\n\t%dx + %dy + %dz = %d", pA[i][0], pA[i][1], pA[i][2], pB[i]);
	}
}

void Print_Determinant(int(*pA)[SIZE], int* pB)	//������ ����ϴ� �Լ�
{
	printf("\n\t [Determinant A]\n");	//A�� ������ ���
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < NUMBER; j++)
		{
			printf("\t%d", pA[i][j]);	//pA��� ���
		}
		printf("\n");
	}

	printf("\n\t [Determinant A1]\n");	//A1�� ������ ���
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < NUMBER; j++)
		{
			if (j == 0)
				printf("\t%d", pB[i]);		//ù��° ���� pB�迭�� ���
			else
				printf("\t%d", pA[i][j]);	//������ ����� pA�迭�� ���
		}
		printf("\n");
	}

	printf("\n\t [Determinant A2]\n");	//A2�� ������ ���
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < NUMBER; j++)
		{
			if (j == 1)
				printf("\t%d", pB[i]);		//�ι�° ���� pB�迭�� ���
			else
				printf("\t%d", pA[i][j]);	//������ ����� pA�迭�� ���
		}
		printf("\n");
	}

	printf("\n\t [Determinant A3]\n");	//A3�� ������ ���
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < NUMBER; j++)
		{
			if (j == 3)
				printf("\t%d", pB[i]);		//����° ���� pB�迭�� ���
			else
				printf("\t%d", pA[i][j]);	//������ ����� pA�迭�� ���
		}
		printf("\n");
	}
}

void Calculation_Cramer(int(*pA)[SIZE], int* pB)	//ũ���� ������ ����� ���, ����ϴ� �Լ�
{
	double x = 0, y = 0, z = 0;
	double det_A = 0;
	double A1 = 0, A2 = 0, A3 = 0;

	det_A = pA[0][0] * (pA[1][1] * pA[2][2] - pA[1][2] * pA[2][1])	//determinant A ��Ľ��� ���μ� ������ ���
		  - pA[0][1] * (pA[1][0] * pA[2][2] - pA[1][2] * pA[2][0])
		  + pA[0][2] * (pA[1][0] * pA[2][1] - pA[1][1] * pA[2][0]);

	if (det_A == 0)	//���� 0�̶��
	{
		printf("\nNo solution,,\n");	//�ظ� ���� �� �����Ƿ� ��� ����
	
	}
	else	//�ƴ϶��
	{
		A1 = pB[0] * (pA[1][1] * pA[2][2] - pA[1][2] * pA[2][1])	//�迭�� �� ��Ҹ� ���� A1 ������ ���
		   - pA[0][1] * (pB[1] * pA[2][2] - pA[1][2] * pB[2])
		   + pA[0][2] * (pB[1] * pA[2][1] - pA[1][1] * pB[2]);

		A2 = pA[0][0] * (pB[1] * pA[2][2] - pA[1][2] * pB[2])	//�迭�� �� ��Ҹ� ���� A2 ������ ���
		   - pB[0] * (pA[1][0] * pA[2][2] - pA[1][2] * pA[2][0])
		   + pA[0][2] * (pA[1][0] * pB[2] - pB[1] * pA[2][0]);

		A3 = pA[0][0] * (pA[1][1] * pB[2] - pB[1] * pA[2][1])	//�迭�� �� ��Ҹ� ���� A3 ������ ���
		   - pA[0][1] * (pA[1][0] * pB[2] - pB[1] * pA[2][0])
		   + pB[0] * (pA[1][0] * pA[2][1] - pA[1][1] * pA[2][0]);

		x = A1 / det_A;	//������ x�� �� ���
		y = A2 / det_A; //������ y�� �� ���
		z = A3 / det_A; //������ z�� �� ���

		printf("\nDeterminant A = %.4f", det_A);
		printf("\nDeterminant A1 = %.4f", A1);
		printf("\nDeterminant A2 = %.4f", A2);
		printf("\nDeterminant A3 = %.4f", A3);

		printf("\nx = A1/A = %.4f   y = A2/A = %.4f   z = A3/A = %.4f", x, y, z);	
		printf("\n\n�� x = %.4f\ty = %.4f\tz = %.4f", x, y, z);		//�ظ� ���
	}
}

int main(void)
{
	//ũ���� ���� ����� ���� Ax = B�� ������ ����� ����
	int A[SIZE][NUMBER] = { NULL };	//�������� ����� ������ ��� ����, �ʱ�ȭ
	int B[SIZE] = { NULL };	//���� ���� ������ �迭 ����, �ʱ�ȭ
	int nAns = 0;	//��� ������ ����

	printf("\n [Calcultaion: Cramer's Rule]");
	printf("\n\n [ON: 1]\t     [OFF: 2]\n\nInput the number: ");

	while(1)	//�ݺ�
	{
		scanf_s("%d", &nAns);
		if(nAns == START_COMMAND)	//nAns�� 1�� ���
		{
			Ask(A, B);	//�������� ����� �Է¹ް� ����ϴ� �Լ�

			printf("\n\n[Calculation : Use the Cramer's rule...]\n");

			Print_Determinant(A, B);	//������ ����ϴ� �Լ�

			Calculation_Cramer(A, B);	//ũ���� ������ ����� ���, ����ϴ� �Լ�

			printf("\n\n[Retry: 1]\t[OFF: 2]\n\nInput the number: ");
		}
		else if(nAns == END_COMMAND)
		{
			printf("\nOFF..\n");
			break;	//�ƴ϶�� �ݺ��� Ż��
		}
		else
		{
			printf("\nInput the Number again..");
			break;
		}
	}
	return 0;
}