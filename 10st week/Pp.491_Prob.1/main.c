#include<stdio.h>
#include<stdlib.h>

#define MAXIMUM_ARRAY	100	//Maximum size of array
#define NUMBER_OF_BOOK	20	//Maximum number of books

typedef struct	//Redefine strucure
{
	char chTitle[MAXIMUM_ARRAY];	//Array of title
	char chAuthor[MAXIMUM_ARRAY];	//Array of author
	int nPage;						//Variable of page
	int nPrice;						//Variable of price
} Book;		//Redefine name is Book

void Input(Book* B, int nNum)	//Function: Input the book's data
{
	for (int i = 0; i < nNum; i++)	//Repeat the number of books
	{
		printf("Title : ");
		scanf_s("%s", &(B + i)->chTitle, MAXIMUM_ARRAY);	//Store to chTitle of structure B
		printf("Author : ");
		scanf_s("%s", &(B + i)->chAuthor, MAXIMUM_ARRAY);	//Store to chAuthor of structure B
		printf("Page : ");
		scanf_s("%d", &(B + i)->nPage);		//Store to nPage of structure B
		printf("Price : ");
		scanf_s("%d", &(B + i)->nPrice);	//Store to nPrice of structure B
		printf("\n");

		if (((B + i)->nPage > 0) && ((B + i)->nPrice > 0))	//If nPage and nPrice are positive numbers,
		{
			continue;	//Continue(go to line 16)
		}
		else	//Otherwise,
		{
			printf("This is not a valid input..\n");
			exit(1);	//EXIT
		}
	}
}

void Output(Book* B, int nNum)	//Function: Output the book's data
{
	for (int i = 0; i < nNum; i++)
		{
			printf("Title: %s, Author: %s, Page: %d, Price: %d\n", (B + i)->chTitle, (B + i)->chAuthor, (B + i)->nPage, (B + i)->nPrice);
		}	//Output data of structure B
}

int main(void)
{
	int nNum;	//Variable to store a number of total
	Book B[NUMBER_OF_BOOK] = { NULL };		//Structure Book to B
	printf("Input total number of book : ");
	scanf_s("%d", &nNum);	//Store the answer to nNum
	if (nNum > NUMBER_OF_BOOK)	//If nNum > maximum number of books
	{
		printf("To many books..(Maximum book's number : 20)\n");	//The reason '20' is because of memory limit
		return 0;	//Exit
	}
	else	//Or
	{
		Input(&B, nNum);	//Input book's data
		Output(&B, nNum);	//Output book's data
	}

	return 0;
}