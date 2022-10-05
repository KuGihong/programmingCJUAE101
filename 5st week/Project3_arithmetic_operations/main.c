#include<stdio.h>

int Add(int nA, int nB);                             //Add 함수 선언
int Sub(int nA, int nB);                             //Sub 함수 선언
int Mul(int nA, int nB);                             //Mul 함수 선언
int Div(int nA, int nB);                             //Div 함수 선언
int Rem(int nA, int nB);                             //Rem 함수 선언

int main(void)
{
	int nA = 0;                                       // 정수 A값 초기화
	int nB = 0;                                       // 정수 B값 초기화
	int nRes = 0;                                      // 결과 Res값 초기화
	char chOper;                                      // 계산 수식 설정

	printf("Input your arithmetic operation :\n");    // 사칙연산 계산식 입력 출력
	scanf_s("%d%c%d", &nA, &chOper, 1, &nB);          // 입력값 각 변수에 저장
	
	switch (chOper)                   //chOper의 값이 무엇인지 확인
	{
	case '+':                         //+일 경우
	{
		printf("Addition : ");        //Addition: 출력
		nRes = Add(nA, nB);           //Add 함수 호출
		printf("%d %c %d = %d\n", nA, chOper, nB, nRes); //결과값 출력

		break;                        //실행종료, 63행으로 이동
	}
	case '-':                         //-일 경우
	{
		printf("Subtraction : ");     //Subtraction : 출력
		nRes = Sub(nA, nB);           //Sub 함수 호출
		printf("%d %c %d = %d\n", nA, chOper, nB, nRes);  //결과값 출력
		break;                        //실행종료, 63행으로 이동
	}
	case'*':                          //*인 경우
	{
		printf("Multiplication : ");  //Multiplication : 출력
		nRes = Mul(nA, nB);           //Mul 함수 출력
		printf("%d %c %d = %d\n", nA, chOper, nB, nRes);  //결과값 출력
		break;                        //실행종료, 63행으로 이동
	}
	case '/':                         // /인 경우
	{
		printf("Division : ");        //Division : 출력
		nRes = Div(nA, nB);           //Div 함수 호출
		printf("%d %c %d = %d\n", nA, chOper, nB, nRes); //결과값 출력
		break;                        //실행종료, 63행으로 이동
	}
	case '%':                         //%인 경우
	{
		printf("Remaining Operation : "); //Remaining Operaion : 출력
		nRes = Rem(nA, nB);           //Rem 함수 호출
		printf("%d %c %d = %d\n", nA, chOper, nB, nRes);  //결과값 출력
		break;                        //실행종료, 63행으로 이동
	}
	default:                          //그 외의 경우
	{
		printf("Please wirte it again with '+ - * / %%'\n"); //Please wirte it again with '+ - * / % 출력
		break;                        //실행종료, 63행으로 이동
	}
	}
	return 0;
}

int Add(int nA, int nB)  //Add 함수 정의 시작
{
	int temp;            //변수 temp 지정
	temp = nA + nB;      //temp에 nA + nB 저장
	return temp;         //temp의 값을 변환
}
int Sub(int nA, int nB)  //Sub 함수 정의 시작
{
	int temp;            //변수 temp 지정       
	temp = nA - nB;      //temp에 nA - nB 저장
	return temp;         //temp의 값을 변환       
}
int Mul(int nA, int nB)  //Mul 함수 정의 시작
{
	int temp;            //변수 temp 지정          
	temp = nA * nB;      //temp에 nA * nB 저장
	return temp;         //temp의 값을 변환        
}
int Div(int nA, int nB)  //Div 함수 정의 시작
{
	int temp;            //변수 temp 지정      
	temp = nA / nB;      //temp에 nA / nB 저장
	return temp;         //temp의 값을 변환         
}
int Rem(int nA, int nB)  //Rem 함수 정의 시작
{
	int temp;            //변수 temp 지정  
	temp = nA % nB;      //temp에 nA % nB 저장
	return temp;         //temp의 값을 변환
}               