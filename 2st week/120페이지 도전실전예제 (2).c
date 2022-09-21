#include <stdio.h>

int main(void)
{
	double kg;
	double cm;
	double bmi;

	printf("input your weight(kg) and height(cm) : ");
	scanf_s("%lf%lf", &kg, &cm);

	bmi = (kg) / (cm * cm);

	(bmi >= 20.0) && (bmi < 25.0) ? printf("average\n") : printf("take care of your weight\n");

	return 0;
}