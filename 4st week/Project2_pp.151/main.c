#include <stdio.h>

#define Age	25;               // ���� ���� 25���� ����
#define Chestsize	95;       // �����ѷ������� ���� 95�� ����


int main(void)
{
	int nAge = Age;           // ���� �� ����
	int nChest = Chestsize;   // �����ѷ������� �� ����
	char chSize;

	if (nAge < 20)             // ���̰� 20���� ���� ���
	{
		if (nChest < 85)      // �����ѷ��� 85 �̸��� ���
		{
			chSize = 'S';     // ������ 'S' ����
		}
		else if (nChest >= 85 && nChest <= 95)  // �����ѷ��� 85���� ũ�� 95���� �۰ų� ���� ���
		{
			chSize = 'M';     // ������ 'M' ����
		}
		else                  // 95���� Ŭ ���
		{
			chSize = 'L';     // ������ 'L' ����
		}
	}
	else                      // ���̰� 20 �̻��� ���
	{
		if (nChest < 90)      // �����ѷ��� 90 �̸��� ���
		{
			chSize = 'S';     // ������ 'S' ����
		}
		else if (nChest >= 90 && nChest <= 100)  // �����ѷ��� 90���� ũ�� 100���� �۰ų� ���� ���
		{
			chSize = 'M';     // ������ 'M' ����
		}
		else                  // 100���� Ŭ ���
		{
			chSize = 'L';     // ������ 'L' ����
		}
	}
		printf("Size is %c.\n", chSize);  // ����� ����� ���� �� ���

		return 0;
	}