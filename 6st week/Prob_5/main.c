#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h> 

#define SHOOT_NUMBER	100	//�̻��� �߻� ��
#define	ARRAY_SIZE		10	//����� ����


double Calculation(double r1, double r2, double v, double z, double k, double *x)	//�յ������ ������ ǥ�رյ������ ���� ����
{
	int i = 0;	//�ӽú��� i �ʱ�ȭ
	int j = 0;	//�ӽú��� i �ʱ�ȭ

	do	//�켱 �߻縦 �����Ƿ� ���๮�� ���� �����Ű�� ���� �˻�
	{
		while(1)	//�ݺ�
		{
			r1 = (double)rand() / RAND_MAX;	//��� ���� r1�� 0~1 ���� ������ ����
			r2 = (double)rand() / RAND_MAX;	//��� ���� r2�� 0~1 ���� ������ ����
			v = sqrt(2 / exp(1.0)) * (2 * r2 - 1);	//0,1������ ���� r1, r2�� �߻����� v�� ����
			z = v / r1;								//���� ���Ŀ� 1�ܰ迡�� ���� v���� �������� ������ z�� k�� ����
			k = ((double)1 / 4) * z * z;

			if (k < 1 - r1)							//���� ������ �����ϸ� 1�ܰ�� ���ư� ���� �ٽ� ����
			{
				x[i] = z;		//���Ժ��� Ȯ�� ���� x�� z���� �ְ� �ݺ��� Ż��(33������ �̵�)
				i++;		
				break;
			}
			else if ((k > (0.259 / r1) + 0.35) || (k > log(r1))) //3�ܰ� �׷��� ������ 1�ܰ�� ���ư� ���� �ٽ� ����
				continue;
		}
	} while (i < SHOOT_NUMBER);	//�߻�� ȸ����ŭ �ݺ�

}
void Print_Variable_X_Y(double *Vertical, double *Horizontal)	//����, ���� ���� ���Ժ��� ���
{
	printf("\n[Horizontal variable X]\n ");
	for (int i = 0; i < SHOOT_NUMBER; i++)	//�߻�� ȸ����ŭ �ݺ�
	{
		if (i % ARRAY_SIZE == 0)	//����� ���¸� 10*10 �� ���·� ����
		{
			printf("\n");
		}
		printf("%.2f\t", Horizontal[i]);	//�Ҽ��� 2�ڸ����� ���� ���� ǥ�����Ժ��� ���
	}
	printf("\n"); 

	printf("\n[Vertical variable Y]\n ");
	for (int i = 0; i < SHOOT_NUMBER; i++)	//�߻�� ȸ����ŭ �ݺ�
	{
		if (i % ARRAY_SIZE == 0)	//����� ���¸� 10*10 �� ���·� ����
		{
			printf("\n");
		}
		printf("%.2f\t", Vertical[i]);	//�Ҽ��� 2�ڸ����� ���� ���� ǥ�����Ժ��� ���
	}
	printf("\n");
}

void Accuracy_Calculation(double* Vertical, double* Horizontal)	//���߷� ���
{
	int nHit = 0;	//���� Ƚ�� ������ ����
	for (int i = 0; i < SHOOT_NUMBER; i++)	//�߻� ȸ����ŭ �ݺ� 
	{
		if ((0.8 * Vertical[i] >= -1 && 0.8 * Vertical[i] <= 1) && (1.6 * Horizontal[i] >= -1 && 1.6 * Horizontal[i] <= 1))
			nHit++;	//ǥ���� x, y�� 2m, 2m�̹Ƿ� 0,0�� �������� �ϸ� x�� y��ǥ�� 1 ~ -1���̿� �����Ƿ� ���հ���ŭ ���� Ƚ�� ����
	}
	printf("\nAccuracy: %.2lf%%\n", (double)nHit);	//�Ҽ��� ���ڸ����� %�� ���
}

int main(void) 
{
	double Vertical[SHOOT_NUMBER];	//���� ���� �迭
	double Horizontal[SHOOT_NUMBER];	//���� ���� �迭
	double r1 = 0;	//�߻��� �̻����� ���� r1
	double r2 = 0;	//�߻��� �̻����� ���� r2
	double v = 0;	//����� ���� ���� v
	double k = 0;	//����� ���� ���� k
	double z = 0;	//����� ���� ���� z
		
	printf("Hit Rate Caclulation\n");	//���߷� ��� ���

	Calculation(r1, r2, v, z, k, Vertical);		//ź������ ���� ��ǥ �յ� ������ ǥ�����Ժ����� ���		
	Calculation(r1, r2, v, z, k, Horizontal);	//ź������ ���� ��ǥ �յ� ������ ǥ�����Ժ����� ���

	Print_Variable_X_Y(Vertical, Horizontal);	//����(x) ����(y) ��ǥ�� ǥ�� ���Ժ��� ��� ���

	Accuracy_Calculation(Vertical, Horizontal);	//ǥ���� ���߷� ���

	return 0;
}