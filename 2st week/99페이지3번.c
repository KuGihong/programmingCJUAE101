#include <stdio.h>

int main(void)
{
	int kor = 3, eng = 5, mat = 4;   // ����, ����, ������ ���� ����
	int credit;   //��ü ���� ������ ���� ����
	int res;   //�������� ������ ���� ����
	double kscore = 3.8, escore = 4.4, mscore = 3.9;   // �� ������ ���� ����
	double grade;   //���� ����� ������ ���� ����
	credit = kor + eng + mat;   //��ü ���� ���
	grade = (kscore + escore + mscore) / 3;   //���� ��� ���
	res = (credit >= 10) && (grade >= 4.0);   //���� ������� ��ü ������ 10���� �̻��̰� ���� ����� 4.0���� ũ�� ��=1, �׷��� ������ ����=0
	printf("%d\n", res);

	return 0;

}