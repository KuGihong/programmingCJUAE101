#include <stdio.h>

int main(void)

{
	int a = 20;    // a�� 20 �ʱ�ȭ
	int b = 0;     // b�� 0 �ʱ�ȭ

	if (a > 10)    // a�� 10���� Ŭ ��� 
	{
		b = a;     // b�� a ����

	}

	printf("a : %d, b : %d\n", a, b);   // a, b�� ���

	return 0;

}