#include <stdio.h>

int main()
{
	int nNum;                     //nNum ���� ����
	int nSum;                     //nSum ���� ����

	printf("Write if you want the sum of 1 to n : ");  //Write if you want the sum of 1 to n : ���
	scanf_s("%d", &nNum);         //�Էµ� �� nNum�� ����

	nSum = rec_func(nNum);        //nSum�� nNum���� �� rec_func �Լ� ����
	printf("The result is %d\n", nSum);  //nSum �� ���

	return 0;
}

int rec_func(int nNum)             //rec_func �Լ� ����
{
	if (nNum <= 0)                 //nNum�� 0���� �۰ų� ���� ���
		return 0;                      //���� ����
	return nNum + rec_func(nNum - 1);  //nNum�� nNum-1�� ������ rec_func�Լ��� ���ϸ� ��ȯ
}