#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define M	5	//M�� ��
#define N	5	//N�� ��
#define NUMBER_SIZE	10	//������ ũ��

void Random_number(int nNum1[N][M], int nNum2[M][N])	//������ 2���� �迭�� ������ ���� ����, ��� �Լ�
{
	srand((unsigned)time(NULL));	//������ ������ �ƴ� �������� ���� �������� ����

	printf("Multiplication of random integer matrices of n x m and m x n:\n\n[The array of n x m]\n");
	for (int i = 0; i < N; i++)	//�ӽú��� i�� N�� �ɶ����� i����
	{
		for (int j = 0; j < M; j++)	//�ӽú��� j�� M�� �ɶ����� ����
		{
			nNum1[i][j] = rand() % NUMBER_SIZE;	//ù��° �迭�� ��� ���� ���� �� ĭ�� ������ ���� ����
			printf("%d\t", nNum1[i][j]);	//���
		}
		printf("\n");	//�迭�� �� �ٹٲ�(�簢ȭ)
	}
	printf("\n[The array of m x n]\n");
	
	for (int i = 0; i < M; i++)	//i�� M�� �ɶ����� ����
	{
		for (int j = 0; j < N; j++)	//j�� N�� �ɶ����� ����
		{
			nNum2[j][i] = rand() % NUMBER_SIZE;	//�ι�° �迭�� ��� ���� ���� �� ĭ�� ������ ���� ����

			printf("%d\t", nNum2[j][i]);	//���
		}
		printf("\n");	//�迭�� �� �ٹٲ�(�簢ȭ)
	}
	printf("\n");
}

void Multiply(int nNum1[N][M], int nNum2[M][N], int nRes[N][N])	//�� ����� ���� ���ϰ� ����ϴ� �Լ�
{
	printf("[Multiplication of the two arrays]\n");
	for (int i = 0; i < N; i++)	//i�� N�� �ɶ����� ����
	{
		for (int j = 0; j < N; j++)	//j�� M�� �ɶ����� ����
		{
			for (int k = 0; k < M; k++)	//k�� M�� �ɶ����� ����
			{
				nRes[i][j] += (nNum1[i][k] * nNum2[k][j]);	//����� �� ����
			}
			printf("%d\t", nRes[i][j]);	//����� �� ���
		}
		printf("\n");	//�迭�� �� �ٹٲ�(�簢ȭ)
	}
}

int main(void)
{
	int nNum1[N][M] = { 0 };	//ù��° ��� ����
	int nNum2[M][N] = { 0 };	//�ι�° ��� ����
	int nRes[N][N] = { 0 };		//�� ����� ���� ����� ������ �迭 ����
	int nAns = 0;	//���� ������ ����� ������ ����
	
	printf("Do yo want to see this program?(Multiplication of random integer matrices of n x m and m x n)\n(Yes: 1, No: 2)\n");
	while (1)	//�ݺ���
	{
		scanf_s("%d", &nAns);	//�Է°� nAns�� ����
		if (nAns == 1)	//nAns�� 1�̶��
		{
			Random_number(nNum1, nNum2);	//�� ����� ������ ������ ä��� ����ϴ� �Լ�
			Multiply(nNum1, nNum2, nRes);	//�� ����� ���� ����� ����ϰ� ����ϴ� �Լ�
			break;	//76������ �̵�
		}
		else if (nAns == 2)	//nAns�� 2���
		{
			printf("Okay..\n");
			return 0;	//����
		}
		else	//�� ���� ���
		{
			printf("Please enter again 1 or 2\n");	//�ٽ� �Է����ּ��� ��� �� 61������ �̵�
			break;
		}
	}
	return 0;	//����
}