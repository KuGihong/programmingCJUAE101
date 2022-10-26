#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h> 

#define SHOOT_NUMBER	100	//미사일 발사 수
#define	ARRAY_SIZE		10	//출력의 형태


double Calculation(double r1, double r2, double v, double z, double k, double *x)	//균등분포된 난수를 표준균등분포로 변경 수식
{
	int i = 0;	//임시변수 i 초기화
	int j = 0;	//임시변수 i 초기화

	do	//우선 발사를 했으므로 실행문을 먼저 실행시키고 조건 검사
	{
		while(1)	//반복
		{
			r1 = (double)rand() / RAND_MAX;	//사격 변수 r1을 0~1 사이 난수로 저장
			r2 = (double)rand() / RAND_MAX;	//사격 변수 r2을 0~1 사이 난수로 저장
			v = sqrt(2 / exp(1.0)) * (2 * r2 - 1);	//0,1사이의 난수 r1, r2를 발생시켜 v를 구함
			z = v / r1;								//다음 수식에 1단계에서 구한 v값과 난수값을 대입해 z와 k를 구함
			k = ((double)1 / 4) * z * z;

			if (k < 1 - r1)							//다음 조건을 만족하면 1단계로 돌아가 난수 다시 생성
			{
				x[i] = z;		//정규분포 확률 변수 x에 z값을 넣고 반복문 탈출(33행으로 이동)
				i++;		
				break;
			}
			else if ((k > (0.259 / r1) + 0.35) || (k > log(r1))) //3단계 그렇지 않으면 1단계로 돌아가 난수 다시 생성
				continue;
		}
	} while (i < SHOOT_NUMBER);	//발사된 회수만큼 반복

}
void Print_Variable_X_Y(double *Vertical, double *Horizontal)	//수직, 수평 방향 정규분포 출력
{
	printf("\n[Horizontal variable X]\n ");
	for (int i = 0; i < SHOOT_NUMBER; i++)	//발사된 회수만큼 반복
	{
		if (i % ARRAY_SIZE == 0)	//출력의 형태를 10*10 의 형태로 만듬
		{
			printf("\n");
		}
		printf("%.2f\t", Horizontal[i]);	//소숫점 2자리까지 수평 방향 표준정규분포 출력
	}
	printf("\n"); 

	printf("\n[Vertical variable Y]\n ");
	for (int i = 0; i < SHOOT_NUMBER; i++)	//발사된 회수만큼 반복
	{
		if (i % ARRAY_SIZE == 0)	//출력의 형태를 10*10 의 형태로 만듬
		{
			printf("\n");
		}
		printf("%.2f\t", Vertical[i]);	//소숫점 2자리까지 수직 방향 표준정규분포 출력
	}
	printf("\n");
}

void Accuracy_Calculation(double* Vertical, double* Horizontal)	//명중률 계산
{
	int nHit = 0;	//명중 횟수 저장할 변수
	for (int i = 0; i < SHOOT_NUMBER; i++)	//발사 회수만큼 반복 
	{
		if ((0.8 * Vertical[i] >= -1 && 0.8 * Vertical[i] <= 1) && (1.6 * Horizontal[i] >= -1 && 1.6 * Horizontal[i] <= 1))
			nHit++;	//표적지 x, y가 2m, 2m이므로 0,0을 원점으로 하면 x와 y좌표는 1 ~ -1사이에 있으므로 사잇값만큼 명중 횟수 증가
	}
	printf("\nAccuracy: %.2lf%%\n", (double)nHit);	//소숫점 두자리까지 %로 출력
}

int main(void) 
{
	double Vertical[SHOOT_NUMBER];	//수직 변수 배열
	double Horizontal[SHOOT_NUMBER];	//수평 변수 배열
	double r1 = 0;	//발사한 미사일의 변수 r1
	double r2 = 0;	//발사한 미사일의 변수 r2
	double v = 0;	//계산을 위한 수식 v
	double k = 0;	//계산을 위한 수식 k
	double z = 0;	//계산을 위한 수식 z
		
	printf("Hit Rate Caclulation\n");	//명중률 계산 출력

	Calculation(r1, r2, v, z, k, Vertical);		//탄착점의 수직 좌표 균등 분포를 표준정규분포로 계산		
	Calculation(r1, r2, v, z, k, Horizontal);	//탄착점의 수평 좌표 균등 분포를 표준정규분포로 계산

	Print_Variable_X_Y(Vertical, Horizontal);	//수직(x) 수평(y) 좌표의 표준 정규분포 결과 출력

	Accuracy_Calculation(Vertical, Horizontal);	//표적지 명중률 출력

	return 0;
}