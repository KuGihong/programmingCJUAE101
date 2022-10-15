#include <stdio.h>

int main(void)
{
	double kg;   //kg 초기화
	double cm;   //cm 초기화
	double bmi;   //bmi 초기화

	printf("input your weight(kg) and height(cm) : ");   //몸무게와 키 입력 출력

	scanf_s("%lf%lf", &kg, &cm);   // 변수 kg, cm 에 입력

	bmi = (kg) / (cm * cm);   //bmi 계산

	(bmi >= 20.0) && (bmi < 25.0) ? printf("average\n") : printf("take care of your weight\n");  // bmi가 20이상. 25미만이면 표준, 그렇지않으면 체중관리가 필요합니다 출력

	return 0;
}