#include<stdio.h>

#define Minprimenum		2       //Minprimenum 을 2로 정의

int main(void)
{
	int nNum, i, j;             //변수 지정
	int nCount = 0;             //nCount 0으로 초기화

	printf("Enter an integer greater than or equal to 2 : ");  //2 이상의 정수를 입력하세요 출력
	scanf_s("%d", &nNum);                                      //변수 nNum에 입력값 저장

		if (nNum < Minprimenum)                                //만약 nNum이 2보다 작을 경우
		{
			printf("Please check your number \n");             //숫자를 다시 확인해주세요 출력
		}
		else                                                   //아닐경우
		{
			for (int i = 2; i <= nNum; i++)                    //i를 2로 초기화, nNum보다 작거나 같을 동안 i값을 증가시키면서 반복
			{
				for (int j = 2; j <= i; j++)                   //j를 2로 초기화, i보다 작거나 같을 동안 j값을 증가시키면서 반복
				{
					if (i % j == 0)                            //만약 i % j가 0인 경우
					{
						if (i > j)                             //i가 j보다 크다면 작업을 종료하고 21행으로 이동
							break;
						else                                   //아니라면
						{
							printf("%5d", i);                  //i값을 전체 폭 5로 우측정렬로 출력
							nCount++;                          //nCount 값을 증가시킴
							if (nCount % 5 == 0)               //만약 nCount % 5가 0이라면
								printf("\n");                  //줄이동 출력
						}
					}
				}
			}
		}
	return 0;
}