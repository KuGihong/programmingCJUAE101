#include<stdio.h>

#define PASSWORD "qwe123"   //��й�ȣ
#define SIZE  20  //�ִ� ���� ũ��

int Save(char* pw) //�н����� �����ϴ� �Լ� ����
{
    int i = 0;  //�ӽ� ���� i �ʱ�ȭ
    for (i = 0; pw[i] != '\0'; i++)    //��й�ȣ ���ڿ� NULL���� �ݺ�
    {
        pw++;  //�� ĭ�� �߰�
    }
    return i;   //i�� ��ȯ
}

int Compare(char* s_pw, char* u_pw) //�ý��� �н������ ������ �Է��� �н����� ���ϴ� �Լ� ����
{
    int i = 0;  //�ӽ� ���� i �ʱ�ȭ
    int s_pw_save = Save(s_pw); //����� �ý��� ��й�ȣ �迭�� �ý��� ������ ����
    int u_pw_save = Save(u_pw); //����� ���� ��й�ȣ �迭�� ���� ������ ����

    if (s_pw_save != u_pw_save) //�ý��� ������ ���� ������ �ٸ���
        return 0;  //0���� ��ȯ
    for (i = 0; i <= s_pw_save; i++)       //�ý��� ���� ������ ������ �ݺ�
    {
        if (s_pw[i] != u_pw[i]) //�ý��� ��й�ȣ i��°�� ���� ��й�ȣ i��°�� ���ٸ�
            return 0;   //1�� ��ȯ
    }
    return 1;   //0���� ��ȯ(����)
}

void Ask(char* s_pw, char* u_pw) //�н����� ����� �Լ� ����
{
    printf("Please input your password : \n");
    while (1)   //����ؼ� �ݺ�
    {
        scanf_s("%s", u_pw, SIZE);   //�Է��� ������ ��й�ȣ�� u_pwd�� ����
        if (Compare(s_pw, u_pw) != 0) //���ϴ� �Լ�, ��й�ȣ�� �´ٸ�(0�� �ƴ϶��)
            break;  //29������ �̵�
        else    //�ƴ϶�� �ٽ� �ݺ�
            printf("Not matched, retry..\n");
    }
    printf("Normal termination..\n");
}

int main(void)
{
    char chSystem_pw[SIZE] = { PASSWORD }; //�ý��� ��й�ȣ �迭ũ�� ���� �� ��й�ȣ ����
    char chUser_pw[SIZE]; //���� ��й�ȣ �迭ũ�� ����
    
    Ask(chSystem_pw, chUser_pw); //�н����� ����� �Լ�
    
    return 0;
}