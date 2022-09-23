#include <stdio.h>

int main(void)
{
	char ch;    //문자를  저장할 변수 지정

	printf("input : ");    //문자 입력 메세지 출력

	scanf_s("%c", &ch);    //변수 ch에 문자 입력

	printf("%cThe ASCII code value of the character is %d.", ch, ch);   //입력된 문자를 변환해서 출력

	return 0;

}