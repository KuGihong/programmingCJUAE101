#include <stdio.h>

#define Chestsize	95;    // �����ѷ� ũ�⸦ 95�� ����

int main(void)
{
	int nChest = Chestsize;     // �����ѷ��� �����ѷ� ũ�� ����
	char chSize;          // ���� ������ ������ ���� 
	
	if (nChest <= 90)    // �����ѷ��� 90���� �۰ų� ���� ���
	{
		chSize = 'S';     // ������ 'S' ����
	}
	else if (nChest > 90 && nChest <= 100)  // �����ѷ��� 90���� ũ�� 100���� �۰ų� ���� ���
	{
		chSize = 'M';     // ������ 'M' ����
	}
	else                //100���� Ŭ ���
	{
		chSize = 'L';     // ������ 'L' ����
	}
	
	printf("Size is % C", chSize);    // size�� ����� ���� �� ���

	return 0;
}