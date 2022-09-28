#include <stdio.h>

int main(void)
{
	int nA = 0;                                       // 정수 A값 초기화
	int nB = 0;                                       // 정수 B값 초기화
	int nRes = 0;                                      // 결과 Res값 초기화
	char chOper;                                      // 계산 수식 설정

	printf("Input your arithmetic operation :\n");    // 사칙연산 계산식 입력
	scanf_s("%d%c%d", &nA, &chOper, 1, &nB);           // 각 변수에 값 저장

	switch (chOper)                                   // chOper의 값이 얼마인지 확인
	{
	case '+':                                         // '+'이면 

		nRes = nA + nB;                               // nRes에 nA + nB 저장

		break;                                        // 28행으로 이동

	case '-':                                        // '-'이면 

		nRes = nA - nB;                               // nRes에 nA - nB 저장

		break;                                        // 28행으로 이동

	case'*':                                         // '*'이면 

		nRes = nA * nB;                               // nRes에 nA * nB 저장

		break;                                        // 28행으로 이동

	default:                                          // chOper와 일치하는 case의 값이 없으면 

		nRes = nA / nB;                               // nRes에 nA / nB 저장

		break;                                        // 28행으로 이동
	}

	printf("%d%c%d=%d\n", nA, chOper, nB, nRes);      // 실행 값 출력

	return 0;

}