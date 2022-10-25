#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h> 

#define NUMBER_SIZE		100
#define	ARRAY_SIZE	10

void Random_number(double* verti, double* hori)	//�迭�� ������ �Ǽ� ����, ���
{
	srand(time(NULL));	//�ð����� ���ϴ� ������ ����

	printf("Vertical direction\n");

	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		verti[i] = (double)rand() / RAND_MAX;	//0���� 1������ �Ǽ��� ���� ����
		hori[i] = (double)rand() / RAND_MAX;

		if (i % ARRAY_SIZE == 0)	//���� ������ 10*10 �� ���·� �Ҽ��� 2�ڸ����� ���
		{
			printf("\n");
		}
		printf("%.2f\t", verti[i]);
	}

	printf("\n\nHorizontal diection\n");
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		if (i % ARRAY_SIZE == 0)	//���� ������ 10*10 �� ���·� �Ҽ��� 2�ڸ����� ���
		{
			printf("\n");
		}
		printf("%.2f\t", hori[i]);
	}
}
void Calculation(double *r, double *V, double *Z, double *K, double *X)	//�յ������ ������ ǥ�رյ������ ����
{
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		while (1)
		{
			V[i] = (sqrt(2 / exp(1.0)) * (2 * r[i] - 1));		//1�ܰ�
			Z[i] = V[i] / r[i];									//2�ܰ�
			K[i] = 0.25 * (pow(Z[i], 2));						//2�ܰ�
			if (K[i] < (1 - r[i]))								//3�ܰ� 1������ ���� �� 55�� �̵�
			{
				break;
			}
			else if ((K[i] >= (0.259 / r[i]) + 0.35) && (K[i] > -log10(r[i])))	//3�ܰ� 2������ ���� ��
			{
				r[i] = (double)rand() / RAND_MAX;	//������ �ٽ� ����
			}
		}
	}
	for (int i = 0; i < 100; i++)	//4�ܰ�
	{
		X[i] = 0 + Z[i] * 1.0;		//��� 0, ǥ������ 1.0
	}
}

int main(void) 
{
	int nAns;	//��� ������ ����
	int nRes = 0;	//�����(���߷�) ������ ����
	double Vertical[NUMBER_SIZE];	//���� ���� �迭
	double Horizontal[NUMBER_SIZE];	//���� ���� �迭

	double Verti_V[NUMBER_SIZE] = { 0 };	//���� ��꿡 �ʿ��� ���� ���� V �迭
	double Verti_Z[NUMBER_SIZE] = { 0 };	//���� ��꿡 �ʿ��� ���� ���� Z �迭
	double Verti_K[NUMBER_SIZE] = { 0 };	//���� ��꿡 �ʿ��� ���� ���� K �迭

	double Hori_V[NUMBER_SIZE] = { 0 };		//���� ��꿡 �ʿ��� ���� ���� V �迭
	double Hori_Z[NUMBER_SIZE] = { 0 };		//���� ��꿡 �ʿ��� ���� ���� Z �迭
	double Hori_K[NUMBER_SIZE] = { 0 };		//���� ��꿡 �ʿ��� ���� ���� K �迭

	double Verti_X[NUMBER_SIZE] = { 0 };	//���� ��꿡 �ʿ��� ���� ���� X �迭
	double Hori_X[NUMBER_SIZE] = { 0 };		//���� ��꿡 �ʿ��� ���� ���� X �迭

	printf("Start a hit-rate calculation program\n(Yes: 1, No: 2)\n");
	while (1)	//�ݺ���
	{
		scanf_s("%d", &nAns);	//�Է°� nAns�� ����
		if (nAns == 1)	//nAns�� 1�̶��
		{
			Random_number(Horizontal, Vertical);	//�迭�� 0~1������ �Ǽ��� ���� ����
			Calculation(Vertical, Verti_V, Verti_Z, Verti_K, Verti_X);	//�Ե� ������ ǥ�����Ժ����� ���
			Calculation(Horizontal, Hori_V, Hori_Z, Hori_K, Hori_X);	//�Ե� ������ ǥ�����Ժ����� ���

			printf("Vertical variable X is..\n ");
			for (int i = 0; i < 100; i++)
			{
				printf("%.2f\n", Verti_X[i]);	//���� ���� ǥ�����Ժ��� ���
			}

			printf("Horizontal variable X is..\n ");
			for (int i = 0; i < 100; i++)
			{
				printf("%.2f\n", Hori_X[i]);	//���� ���� ǥ�����Ժ��� ���
			}

			break;	//114������ �̵�
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
	return 0;
}