#include <stdio.h>

int main(void)
{
	double kg;   //kg ���� �ʱ�ȭ
	double cm;   //cm ���� �ʱ�ȭ
	double bmi;   //bmi ���� �ʱ�ȭ

	printf("Input your weight(kg) and height(cm) : ");   //�����Կ� Ű �Է� ���
	scanf_s("%lf%lf", &kg, &cm);   // ���� kg, cm �� �Է�

	bmi = (kg) / (cm * cm);   //bmi ���

	(bmi >= 20.0) && (bmi < 25.0) ? printf("Average\n") : printf("Take care of your weight\n");  // bmi�� 20�̻�. 25�̸��̸� ǥ��, �׷��������� ü�߰����� �ʿ��մϴ� ���

	return 0;
}