#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	MAXIMUM_NUMBER	100
#define NUMBER_SIZE	100

void Random_number(int* nNum, int nSize)	//�迭 �ȿ� ������ ���� ����, ��� �Լ�
{
	int i;	//�ӽú��� ����

	srand((unsigned)time(NULL));	//������ ������ �ƴ� �������� ���� �������� ����

	printf("\nRandom Array:\n");
	for (int i = 0; i < nSize; i++)	//nSize��ŭ �ݺ�
	{
		nNum[i] = rand() % NUMBER_SIZE;	//nSize��ŭ ĭ���� 100������ ������ ������ ä���
		printf("%d ", nNum[i]);	//ä���� ���� ���
	}
	printf("\n");
}

void Descending(int* nNum, int nSize)	//�������� �Լ�
{
	int i, j;	//�ӽ� ����
	int temp = 0;	//�ӽú��� 0���� �ʱ�ȭ
	printf("\nSort In Descending Array:\n");
	for (i = 0; i < nSize; i++)	//i�� 0���� nSize���� Ŀ���� ������ i�� ������Ű�� �ݺ�
	{
		for (j = i; j < nSize; j++)	//j�� i���� �ְ� nSize���� Ŀ���� ������ j�� ������Ű�� �ݺ�
		{
			if (nNum[i] < nNum[j])	//���� �迭�� i��°�� j��°���� �۴ٸ� 
			{
				temp = nNum[i];	
				nNum[i] = nNum[j];		//�迭�� i��°�� j��°�� �ڸ� �ٲ�(�������� ����)
				nNum[j] = temp;	
			}
		}
		printf("%d ", nNum[i]);	//�迭 �� ������� ���
	}
	printf("\n");
}

void Ascending(int *nNum, int nSize)	//�������� �Լ�
{
	int i, j;	//�ӽ� ����
	int temp = 0;	//�ӽú��� 0���� �ʱ�ȭ
	printf("\nSort In Ascending Array:\n");
	for (i = 0; i < nSize; i++)	//i�� 0���� nSize���� Ŀ���� ������ i�� ������Ű�� �ݺ�
	{
		for (j = i; j < nSize; j++)	//j�� i���� �ְ� nSize���� Ŀ���� ������ j�� ������Ű�� �ݺ�
		{
			if (nNum[i] > nNum[j])	//���� �迭�� i��°�� j��°���� ũ�ٸ� 
			{
				temp = nNum[i];
				nNum[i] = nNum[j];		//�迭�� i��°�� j��°�� �ڸ� �ٲ�(�������� ����)
				nNum[j] = temp;
			}
		}
		printf("%d ", nNum[i]);	//�迭 �� ������� ���
	}
	printf("\n");
}

int main(void)
{
	int nNum[MAXIMUM_NUMBER];	//�迭 ����
	int nSize = 0;	//ũ�� ���� nSize�� 0���� �ʱ�ȭ

	printf("Enter an array of a certain size:\n(Input a number greater than 0)\n");
	scanf_s("%d", &nSize);	// �Է°��� nSize�� ����

	if (nSize > 0)	//nSize�� ���� 0���� ū ���ڶ��
	{
		Random_number(nNum, nSize);	//������ ������ ä�� �迭 ����, ����ϴ� �Լ�
		Descending(nNum, nSize);	//������������ �����ϴ� �Լ�
		Ascending(nNum, nSize);	//������������ �����ϴ� �Լ�
	}
	else	//�ٸ� ���̶��
		printf("Please enter again the size with a number greater than 0..\n");	//�ٽ� �Է����ּ��� ���

	return 0;	//����
}