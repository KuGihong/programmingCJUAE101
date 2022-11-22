#include<stdio.h>

#define MAXIMUM_ARRAY 50	//Maximum size of array 
#define SUBJECT_NUMBER 3.0	//Number of subjects
#define GRADE_A 90.0	//Score of grade'A'
#define GRADE_B 80.0	//Score of grade'B'
#define GRADE_C 70.0	//Score of grade'C'

typedef struct	//Redefined sturcture
{
	int nClass_of;
	char chName[MAXIMUM_ARRAY];
	int nKor;
	int nEng;
	int nMat;
	int nTotal;
	double Average;
	char chGrade;

}Student;	//Sturcure is Student

void Input(Student* nList, int nNum)	//Function: Input student's data
{
	for (int i = 0; i < nNum; i++)	//Repeat until nNum, input student's list
	{
		printf("Class of : ");
		scanf_s("%d", &nList[i].nClass_of);
		printf("Name : ");
		scanf_s("%s", &nList[i].chName, MAXIMUM_ARRAY);
		printf("Grade of Korean : ");
		scanf_s("%d", &nList[i].nKor);
		printf("Grade of Engish : ");
		scanf_s("%d", &nList[i].nEng);
		printf("Grade of Math : ");
		scanf_s("%d", &nList[i].nMat);
	}
}

void Calculation(Student* nList, int nNum)	//Function: Calculation student's score
{
	for (int i = 0; i < nNum; i++)	//Repeat until nNum
	{
		(nList +i)->nTotal = (nList + i)->nKor + (nList + i)->nEng + (nList + i)->nMat;
		//Cacluating total socore
		(nList + i)->Average = ((nList + i)->nTotal) / SUBJECT_NUMBER;
		//Cacluating Average socore
		if ((nList + i)->Average >= GRADE_A)	//If average >= 90.0, it is 'A'
		{
			(nList + i)->chGrade = 'A';
		}
		else if ((nList + i)->Average >= GRADE_B)	//If average >= 80.0, it is 'B'
		{
			(nList +i)->chGrade = 'B';
		}
		else if ((nList + i)->Average >= GRADE_C)	//If average >= 70.0, it is 'C'
		{
			(nList + i)->chGrade = 'C';
		}
		else	//If average < 70.0, it is 'F'
		{
			(nList + i)->chGrade = 'F';
		}
	}
}
void Print_List(Student* nList, int nNum)	//Function: Output student's score list
{
	printf("[In order: Class of, Name, Korean, English, Math, Total, Average, Grade]\n\n");
	for (int i = 0; i < nNum; i++)	//Repeat until nNum, output student's list
	{
		printf("%3d ", nList[i].nClass_of);
		printf("%5s", nList[i].chName);
		printf("%5d", nList[i].nKor);
		printf("%5d", nList[i].nEng);
		printf("%5d ", nList[i].nMat);
		printf("%5d  ", nList[i].nTotal);
		printf("%5.1lf", nList[i].Average);
		printf("%5c\n", nList[i].chGrade);
	}
}
void Sort(Student*nList, int nNum)	//Function: Sort in order of total score larger
{
	Student temp;	//Specify strucures as temporary variables to sort
	int i;
	for (i = 0; i < nNum - 1; i++)	//Repeat nNum-1
	{
		int j = i + 1;	//Variable j = i+1, To compare with following nTotal
		if (nList[i].nTotal < nList[j].nTotal)	//If nTotal[i] < nTotal[j]
		{
			temp = nList[i];	
			nList[i] = nList[j];	//Swap each other
			nList[j] = temp;
		}
	}
}

int main(void)
{
	int nNum;
	Student nList[MAXIMUM_ARRAY] = { NULL };	//Initialize sturcture nList

	printf("How many student? Maximum number of students is 50\n: ");
	scanf_s("%d", &nNum);	//Store student's number to nNum

	if (nNum > MAXIMUM_ARRAY)	//If nNum > 50
	{
		printf("To many students..\n");
		return 0;	//Exit
	}
	else	//Or
	{
		Input(&nList, nNum);	//Input student's data

		Calculation(&nList, nNum);	//Calculation student's score

		printf("\n# Data before sorting...\n");
		Print_List(&nList, nNum);	//Output student's score list
		
		Sort(&nList, nNum);	//Sort in order of total score larger
		
		printf("\n# After Data sorting...\n");
		Print_List(&nList, nNum);	//Output sorted the list
	}
	return 0;
}