#include<stdio.h>

#define PASSWORD "qwe123"   //비밀번호
#define SIZE  20  //최대 숫자 크기

int Save(char* pw) //패스워드 저장하는 함수 선언
{
    int i = 0;  //임시 변수 i 초기화
    for (i = 0; pw[i] != '\0'; i++)    //비밀번호 문자열 NULL까지 반복
    {
        pw++;  //한 칸씩 추가
    }
    return i;   //i로 반환
}

int Compare(char* s_pw, char* u_pw) //시스템 패스워드와 유저가 입력한 패스워드 비교하는 함수 선언
{
    int i = 0;  //임시 변수 i 초기화
    int s_pw_save = Save(s_pw); //저장된 시스템 비밀번호 배열을 시스템 변수에 저장
    int u_pw_save = Save(u_pw); //저장된 유저 비밀번호 배열을 유저 변수에 저장

    if (s_pw_save != u_pw_save) //시스템 변수와 유저 변수가 다르면
        return 0;  //0으로 반환
    for (i = 0; i <= s_pw_save; i++)       //시스템 변수 수보다 작으면 반복
    {
        if (s_pw[i] != u_pw[i]) //시스템 비밀번호 i번째와 유저 비밀번호 i번째와 같다면
            return 0;   //1로 반환
    }
    return 1;   //0으로 반환(종료)
}

void Ask(char* s_pw, char* u_pw) //패스워드 물어보는 함수 선언
{
    printf("Please input your password : \n");
    while (1)   //계속해서 반복
    {
        scanf_s("%s", u_pw, SIZE);   //입력한 유저의 비밀번호를 u_pwd에 저장
        if (Compare(s_pw, u_pw) != 0) //비교하는 함수, 비밀번호가 맞다면(0이 아니라면)
            break;  //29행으로 이동
        else    //아니라면 다시 반복
            printf("Not matched, retry..\n");
    }
    printf("Normal termination..\n");
}

int main(void)
{
    char chSystem_pw[SIZE] = { PASSWORD }; //시스템 비밀번호 배열크기 지정 및 비밀번호 지정
    char chUser_pw[SIZE]; //유저 비밀번호 배열크기 지정
    
    Ask(chSystem_pw, chUser_pw); //패스워드 물어보는 함수
    
    return 0;
}