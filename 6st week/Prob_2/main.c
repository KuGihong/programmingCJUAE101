#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define	MAXIMUM_NUMBER	100	//�ִ� ����
#define NUMBER_SIZE	100	//������ ũ��

void Random_number(int* nNum, int nSize)	//������ ���� ����, ��� �Լ�
{
	srand((unsigned)time(NULL));	//������ ������ �ƴ� �������� ���� �������� ����

	printf("\nThe numbers : \n");
	int i = 0;	//�ӽú��� ����
	for (int i = 0; i < nSize; i++)	//nSize��ŭ �ݺ�
	{
		nNum[i] = rand() % NUMBER_SIZE;	//nSize��ŭ ĭ���� 100������ ������ ������ ä���
		printf("%d ", nNum[i]);	//ä���� ���� ���
	}
	printf("\n");
}

int Average(int* nNum, int nSize)	//��� ��� �Լ�
{
	int i;
	int temp = 0;	//�ӽú��� ����, �ʱ�ȭ
	int sum = 0;
	for (i = 0; i < nSize; i++)	//nSize��ŭ �ݺ�
	{
		sum += nNum[i];	//�迭 ���� ���� ����
	}
	temp = sum / nSize;	//��� ���ϴ� ����
	return temp;	//temp���� ��ȯ
}

int Variation(int* nNum, int nSize)	//�л� ��� �Լ�
{
	int i = 0;	//�ӽú��� ����, �ʱ�ȭ
	int temp = 0;
	int avg = Average(nNum, nSize);	//����� ��հ� avg�� ����
	for (int i = 0; i < nSize; i++)	//nSize��ŭ �ݺ�
	{
		temp = temp + pow((nNum[i] - avg), 2);	//�л� ���
	}
	temp = temp / nSize;	//�л� ���ϴ� ����
	return temp;	//temp���� ��ȯ
}

int Std_deviation(int* nNum, int nSize)	//ǥ�� ���� ��� �Լ�
{
	int temp = 0;	//�ӽú��� ����, �ʱ�ȭ
	temp = sqrt(Variation(nNum, nSize));	//ǥ�� ���� ���
	return temp;	//temp���� ��ȯ
}

void Calculation(int* nNum, int nSize)	//����ϰ� ����ϴ� �Լ�
{
	int nAns, nRes;
	while (1)	//�ݺ��� ����
	{
		printf("\nWhat do you want to see? Input the number:\nEx)Exit: 0, Average: 1, Variance: 2, Standard deviation: 3\n");
		scanf_s("%d", &nAns);	//nAns�� �Է� �� ����

		switch (nAns)
		{
		case 0:	//nAns 0�϶�
			printf("\nExit..\n");
			exit(1);	//����
			break;	//81������ Ż��

		case 1:	//nAns 1�϶�
			printf("\nAverage: ");
			nRes = Average(nNum, nSize);	//nRes�� ��հ� ����� �� ����
			printf("%d\n", nRes);	//�� ���
			break;	//81������ Ż��

		case 2:	//nAns 2�϶�
			printf("\nVariance: ");
			nRes = Variation(nNum, nSize);	//nRes�� �л� ����� �� ����
			printf("%d\n", nRes);	//�� ���
			break;	//81������ Ż��

		case 3:	//nAns 3�϶�
			printf("\nStandard deviation: ");
			nRes = Std_deviation(nNum, nSize);	//nRes�� ǥ�� ���� ����� �� ����
			printf("%d\n", nRes);	//�� ���
			break;	//81������ Ż��

		default:	//nAns�� �ٸ� ���϶�
			printf("\nPlease write the number again(0 ~ 3)\n");	//�ٽ� �Է��ϱ� ���
			break;	//81������ Ż��
		}
	}
}

int main(void)
{
	int nNum[MAXIMUM_NUMBER];	//���� ũ���� �迭 ����
	int nSize;	//���� ����

	printf("Enter an array of a certain size for calculating the mean, variance, and standard deviation:\n");
	scanf_s("%d", &nSize);	//�Է� ���� nSize�� ����

	if (100 > nSize > 0)	//nSize�� 0���� Ŭ ���
	{
		Random_number(nNum, nSize);	//������ ���� ����
		Calculation(nNum, nSize);	//���, �л�, ǥ������ ���
	}
	else	//�Ǵ�
	{
		printf("Please enter the positive number.(Area: 0 ~ 100)\n");	//�ٽ� �Է� ���
	}
	return 0;	//����
}