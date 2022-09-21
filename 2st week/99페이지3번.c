#include <stdio.h>

int main(void)
{
	int kor = 3, eng = 5, mat = 4;   // 국어, 영어, 수학의 학점 지정
	int credit;   //전체 학점 저장할 변수 지정
	int res;   //연산결과를 저장할 변수 지정
	double kscore = 3.8, escore = 4.4, mscore = 3.9;   // 각 과목의 평점 지정
	double grade;   //평점 평균을 저장할 변수 지정
	credit = kor + eng + mat;   //전체 학점 계산
	grade = (kscore + escore + mscore) / 3;   //평점 평균 계산
	res = (credit >= 10) && (grade >= 4.0);   //연산 결과에서 전체 학점이 10학점 이상이고 평점 평균이 4.0보다 크면 참=1, 그렇지 않으면 거짓=0
	printf("%d\n", res);

	return 0;

}