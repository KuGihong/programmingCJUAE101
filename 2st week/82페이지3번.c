#include <stdio.h>

int main(void)
{
	char ch;    //���ڸ�  ������ ���� ����

	printf("input : ");    //���� �Է� �޼��� ���
	scanf_s("%c", &ch);    //���� ch�� ���� �Է�
	printf("%cThe ASCII code value of the character is %d.", ch, ch);   //�Էµ� ���ڸ� ��ȯ�ؼ� ���

	return 0;

}