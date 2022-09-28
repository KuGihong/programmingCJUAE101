#include <stdio.h>

int main(void)
{
	int nA = 0;                                       // 정수 A값 초기화
	int nB = 0;                                       // 정수 B값 초기화
	int nRes = 0;                                     // 결과 Res값 초기화
	char chOper;                                      // 계산 수식 설정

	printf("Input your arithmetic operation :\n");    // 사칙연산 계산식 입력
	scanf_s("%d%c%d", &nA, &chOper, 1, &nB);          // 각 변수에 값 저장

	if (chOper == '+')                                // chOper가 '+'라면
	{
		nRes = nA + nB;                               // nRes에 nA + nB 저장
	}
	else if (chOper == '-')                           // chOper가 '-'라면
	{
		nRes = nA - nB;                               // nRes에 nA - nB 저장
	}
	else if (chOper == '*')                           // chOper가 '*'라면
	{
		nRes = nA * nB;                               // nRes에 nA * nB 저장
	}
	else                                              // chOper가 그 외의 값이라면
	{
		nRes = nA / nB;                               // nRes에 nA / nB 저장
	}
	printf("%d%c%d=%d\n", nA, chOper, nB, nRes);      // 실행 값 출력

	return 0;
}