#include<stdio.h>
#define MAXIMUM_ARRAY	20	//Maximum size of array
#define ANSWER_1	1	//Answer 1
#define ANSWER_2	2	//Answer 2

void Print_Deep_Learning(char* chStr1, FILE* fp_1)	//Function: Read file and print of Deep Learning
{
	printf("[Data for deep learning]\nInput order: id, object names in order\n");
	fopen_s(&fp_1, "C:\\Users\\kgh36\\Documents\\GitHub\\programmingCJUAE101\\10st week\\Prob_Read_Data\\yolo_label_data.txt", "rt");
	//Read file: yolo_label_data

	if (fp_1 == NULL)	//Confirm file opening
	{
		printf("File didn't open..\n");
		return 1;	//Exit
	}
	printf("\n[File open..]\n");

	fgets(chStr1, sizeof(chStr1), fp_1);	//Output the first sentence
	printf("class_id: %s", chStr1);

	fgets(chStr1, sizeof(chStr1), fp_1);	//Output the second sentence
	printf("x_center_normalized: %s", chStr1);

	fgets(chStr1, sizeof(chStr1), fp_1);	//Output the third sentence
	printf("y_center_normalized: %s", chStr1);

	fgets(chStr1, sizeof(chStr1), fp_1);	//Output the fourth sentence
	printf("width_center_normalized: %s", chStr1);

	fgets(chStr1, sizeof(chStr1), fp_1);	//Output the fifth sentence
	printf("height_center_normalized: %s", chStr1);

	printf("\n\n[File closed..]\n\n");
	fclose(fp_1);	//Close file
}

void Print_Object_Information(char* chStr2, FILE* fp_2)	//Function: Read file and print of Object Information
{
	printf("\n[Object information that exists in one image]\n");
	fopen_s(&fp_2, "C:\\Users\\kgh36\\Documents\\GitHub\\programmingCJUAE101\\10st week\\Prob_Read_Data\\yolo_bbox_data.txt", "rt");
	//Read file: yolo_bbox_data

	if (fp_2 == NULL)	//Confirm file opening
	{
		printf("File didn't open..\n");
		return 1;	//Exit
	}
	printf("\n[File open..]\n");

	while (fgets(chStr2, sizeof(chStr2), fp_2) != NULL)
	{
		printf("%s", chStr2);	//Output file's data
	}
	printf("\n[File closed..]\n\n");
	fclose(fp_2);	//Close file
}

int main(void)
{
	FILE* fp_1 = NULL;	//File pointer1 declaration
	FILE* fp_2 = NULL;	//File pointer2 declaration

	char chStr1[MAXIMUM_ARRAY] = { NULL };	//Initialization array of string1
	char chStr2[MAXIMUM_ARRAY] = { NULL };	//Initialization array of string2
	int nAns;

	while (1)	//Repeat
	{
		printf("Choose number\n1: Data for deep learning\t2: Object information that exists in one image\t3: Exit\n");
		scanf_s("%d", &nAns);	//Choose the number 1, 2, 3
		if (nAns == ANSWER_1)	//If choose 1
		{
			Print_Deep_Learning(chStr1, fp_1);	//Output Deep_Learning
		}
		else if (nAns == ANSWER_2)	//If choose 2
		{
			Print_Object_Information(chStr2, fp_2);	//Output Object_Information
		}
		else
		{
			printf("Exit..\n");	//Exit
			break;
		}
	}

	return 0;
}