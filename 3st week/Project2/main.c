#include <stdio.h>

int main(void)
{
	int a = 10;     // a�� 10���� �ʱ�ȭ

	if (a >= 0)     // a�� 0���� �۰ų� ũ��
	{
		a = 1;      // a�� 1 ����
	}
	else            // a�� 0���� ������
	{
		a = -1;     // a�� -1����
	}

	printf("a : %d\n", a);

	return 0;
}