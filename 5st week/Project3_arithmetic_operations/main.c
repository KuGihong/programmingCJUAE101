#include<stdio.h>

int Add(int nA, int nB);                             //Add �Լ� ����
int Sub(int nA, int nB);                             //Sub �Լ� ����
int Mul(int nA, int nB);                             //Mul �Լ� ����
int Div(int nA, int nB);                             //Div �Լ� ����
int Rem(int nA, int nB);                             //Rem �Լ� ����

int main(void)
{
	int nA = 0;                                       // ���� A�� �ʱ�ȭ
	int nB = 0;                                       // ���� B�� �ʱ�ȭ
	int nRes = 0;                                      // ��� Res�� �ʱ�ȭ
	char chOper;                                      // ��� ���� ����

	printf("Input your arithmetic operation :\n");    // ��Ģ���� ���� �Է� ���
	scanf_s("%d%c%d", &nA, &chOper, 1, &nB);          // �Է°� �� ������ ����
	
	switch (chOper)                   //chOper�� ���� �������� Ȯ��
	{
	case '+':                         //+�� ���
	{
		printf("Addition : ");        //Addition: ���
		nRes = Add(nA, nB);           //Add �Լ� ȣ��
		printf("%d %c %d = %d\n", nA, chOper, nB, nRes); //����� ���

		break;                        //��������, 63������ �̵�
	}
	case '-':                         //-�� ���
	{
		printf("Subtraction : ");     //Subtraction : ���
		nRes = Sub(nA, nB);           //Sub �Լ� ȣ��
		printf("%d %c %d = %d\n", nA, chOper, nB, nRes);  //����� ���
		break;                        //��������, 63������ �̵�
	}
	case'*':                          //*�� ���
	{
		printf("Multiplication : ");  //Multiplication : ���
		nRes = Mul(nA, nB);           //Mul �Լ� ���
		printf("%d %c %d = %d\n", nA, chOper, nB, nRes);  //����� ���
		break;                        //��������, 63������ �̵�
	}
	case '/':                         // /�� ���
	{
		printf("Division : ");        //Division : ���
		nRes = Div(nA, nB);           //Div �Լ� ȣ��
		printf("%d %c %d = %d\n", nA, chOper, nB, nRes); //����� ���
		break;                        //��������, 63������ �̵�
	}
	case '%':                         //%�� ���
	{
		printf("Remaining Operation : "); //Remaining Operaion : ���
		nRes = Rem(nA, nB);           //Rem �Լ� ȣ��
		printf("%d %c %d = %d\n", nA, chOper, nB, nRes);  //����� ���
		break;                        //��������, 63������ �̵�
	}
	default:                          //�� ���� ���
	{
		printf("Please wirte it again with '+ - * / %%'\n"); //Please wirte it again with '+ - * / % ���
		break;                        //��������, 63������ �̵�
	}
	}
	return 0;
}

int Add(int nA, int nB)  //Add �Լ� ���� ����
{
	int temp;            //���� temp ����
	temp = nA + nB;      //temp�� nA + nB ����
	return temp;         //temp�� ���� ��ȯ
}
int Sub(int nA, int nB)  //Sub �Լ� ���� ����
{
	int temp;            //���� temp ����       
	temp = nA - nB;      //temp�� nA - nB ����
	return temp;         //temp�� ���� ��ȯ       
}
int Mul(int nA, int nB)  //Mul �Լ� ���� ����
{
	int temp;            //���� temp ����          
	temp = nA * nB;      //temp�� nA * nB ����
	return temp;         //temp�� ���� ��ȯ        
}
int Div(int nA, int nB)  //Div �Լ� ���� ����
{
	int temp;            //���� temp ����      
	temp = nA / nB;      //temp�� nA / nB ����
	return temp;         //temp�� ���� ��ȯ         
}
int Rem(int nA, int nB)  //Rem �Լ� ���� ����
{
	int temp;            //���� temp ����  
	temp = nA % nB;      //temp�� nA % nB ����
	return temp;         //temp�� ���� ��ȯ
}               