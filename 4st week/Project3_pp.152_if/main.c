#include <stdio.h>

int main(void)
{
	int nA = 0;                                       // ���� A�� �ʱ�ȭ
	int nB = 0;                                       // ���� B�� �ʱ�ȭ
	int nRes = 0;                                     // ��� Res�� �ʱ�ȭ
	char chOper;                                      // ��� ���� ����

	printf("Input your arithmetic operation :\n");    // ��Ģ���� ���� �Է�
	scanf_s("%d%c%d", &nA, &chOper, 1, &nB);          // �� ������ �� ����

	if (chOper == '+')                                // chOper�� '+'���
	{
		nRes = nA + nB;                               // nRes�� nA + nB ����
	}
	else if (chOper == '-')                           // chOper�� '-'���
	{
		nRes = nA - nB;                               // nRes�� nA - nB ����
	}
	else if (chOper == '*')                           // chOper�� '*'���
	{
		nRes = nA * nB;                               // nRes�� nA * nB ����
	}
	else                                              // chOper�� �� ���� ���̶��
	{
		nRes = nA / nB;                               // nRes�� nA / nB ����
	}
	printf("%d%c%d=%d\n", nA, chOper, nB, nRes);      // ���� �� ���

	return 0;
}