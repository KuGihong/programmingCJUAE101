#include<stdio.h>

int main(void)
{
	int i, j;                                               //���� ������ ���� ����

	printf("Enter multiplication table as number. \n");     //�������� �� �Է��ϼ��� ���
	scanf_s("%d", &i);                                      //�Է��� ���� ���� i�� ����

	for (j = 1; j <= 9; j++)                            //j�� 2�� �ʱ�ȭ, 2���� 9���� ���ų� ���� ���� �ݺ�
	{
		printf("%d * %d = %d\n", i, j, i * j);          //i*j�� �ݺ��� ����� ���
	}

	return 0;
}