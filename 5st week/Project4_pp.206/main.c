#include <stdio.h>

int main()
{
	int nNum;                     //nNum 변수 지정
	int nSum;                     //nSum 변수 지정

	printf("Write if you want the sum of 1 to n : ");  //Write if you want the sum of 1 to n : 출력
	scanf_s("%d", &nNum);         //입력된 값 nNum에 저장

	nSum = rec_func(nNum);        //nSum에 nNum값이 들어간 rec_func 함수 저장
	printf("The result is %d\n", nSum);  //nSum 값 출력

	return 0;
}

int rec_func(int nNum)             //rec_func 함수 정의
{
	if (nNum <= 0)                 //nNum이 0보다 작거나 같을 경우
		return 0;                      //실행 종료
	return nNum + rec_func(nNum - 1);  //nNum에 nNum-1을 대입한 rec_func함수를 더하며 반환
}