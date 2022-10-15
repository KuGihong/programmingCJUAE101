#include <stdio.h>

#define Age	25;               // 나이 값을 25세로 설정
#define Chestsize	95;       // 가슴둘레사이즈 값을 95로 설정


int main(void)
{
	int nAge = Age;           // 나이 값 저장
	int nChest = Chestsize;   // 가슴둘레사이즈 값 저장
	char chSize;

	if (nAge < 20)             // 나이가 20보다 작을 경우
	{
		if (nChest < 85)      // 가슴둘레가 85 미만일 경우
		{
			chSize = 'S';     // 변수에 'S' 저장
		}
		else if (nChest >= 85 && nChest <= 95)  // 가슴둘레가 85보다 크고 95보다 작거나 같을 경우
		{
			chSize = 'M';     // 변수에 'M' 저장
		}
		else                  // 95보다 클 경우
		{
			chSize = 'L';     // 변수에 'L' 저장
		}
	}
	else                      // 나이가 20 이상일 경우
	{
		if (nChest < 90)      // 가슴둘레가 90 미만일 경우
		{
			chSize = 'S';     // 변수에 'S' 저장
		}
		else if (nChest >= 90 && nChest <= 100)  // 가슴둘레가 90보다 크고 100보다 작거나 같을 경우
		{
			chSize = 'M';     // 변수에 'M' 저장
		}
		else                  // 100보다 클 경우
		{
			chSize = 'L';     // 변수에 'L' 저장
		}
	}
		printf("Size is %c.\n", chSize);  // 사이즈에 저장된 변수 값 출력

		return 0;
	}