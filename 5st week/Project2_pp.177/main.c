#include<stdio.h>

#define Minprimenum		2       //Minprimenum �� 2�� ����

int main(void)
{
	int nNum, i, j;             //���� ����
	int nCount = 0;             //nCount 0���� �ʱ�ȭ

	printf("Enter an integer greater than or equal to 2 : ");  //2 �̻��� ������ �Է��ϼ��� ���
	scanf_s("%d", &nNum);                                      //���� nNum�� �Է°� ����

	if (nNum < Minprimenum)                                //���� nNum�� 2���� ���� ���
	{
		printf("Please check your number \n");             //���ڸ� �ٽ� Ȯ�����ּ��� ���
	}
	else                                                   //�ƴҰ��
	{
		for (int i = 2; i <= nNum; i++)                    //i�� 2�� �ʱ�ȭ, nNum���� �۰ų� ���� ���� i���� ������Ű�鼭 �ݺ�
		{
			for (int j = 2; j <= i; j++)                   //j�� 2�� �ʱ�ȭ, i���� �۰ų� ���� ���� j���� ������Ű�鼭 �ݺ�
			{
				if (i % j == 0)                            //���� i % j�� 0�� ���
				{
					if (i > j)                             //i�� j���� ũ�ٸ� �۾��� �����ϰ� 21������ �̵�
						break;
					else                                   //�ƴ϶��
					{
						printf("%5d", i);                  //i���� ��ü �� 5�� �������ķ� ���
						nCount++;                          //nCount ���� ������Ŵ
						if (nCount % 5 == 0)               //���� nCount % 5�� 0�̶��
							printf("\n");                  //���̵� ���
					}
				}
			}
		}
	}
	return 0;
}