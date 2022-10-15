#include <stdio.h>

#define Chestsize	95;    // 가슴둘레 크기를 95로 설정

int main(void)
{
	int nChest = Chestsize;     // 가슴둘레에 가슴둘레 크기 저장
	char chSize;          // 옷의 사이즈 저장할 변수 
	
	if (nChest <= 90)    // 가슴둘레가 90보다 작거나 같을 경우
	{
		chSize = 'S';     // 변수에 'S' 저장
	}
	else if (nChest > 90 && nChest <= 100)  // 가슴둘레가 90보다 크고 100보다 작거나 같을 경우
	{
		chSize = 'M';     // 변수에 'M' 저장
	}
	else                //100보다 클 경우
	{
		chSize = 'L';     // 변수에 'L' 저장
	}
	
	printf("Size is % C", chSize);    // size에 저장된 변수 값 출력

	return 0;
}