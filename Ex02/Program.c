#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>


// was created by Eugene Sergienko ID- 31407657 & Shlomi Hanan ID- 300908886


void Ex01();
int GetDef(int*, int);

void Ex02();
int RecursionEx02(int);

void Ex03();
int CheckArrayEx03(char*, char*, char *);


void Ex04();
void RebuildArray(char*);

void Ex05();
int CountArratZugiLength(int*, int);

void Ex05();
int CountArratZugiLength(int*, int);

void Ex06();
void PrintArray(int*, int);

int main() {

	int select=0, i, all_Ex_in_loop=0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i=1; i<=6; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select=0;
				printf("please select 0-6 : ");
				scanf_s("%d",&select);
			} while ((select<0)||(select>6));
			switch (select)
			{
			case 1: Ex01(); break;
			case 2: Ex02(); break;
			case 3: Ex03(); break;
			case 4: Ex04(); break;
			case 5: Ex05(); break;
			case 6: Ex06(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}


void Ex01() {

	int length;
	int counter = 0, i = 0;
	int result = 0;
	int* data;
	printf("Enter the number of number do you want to enter \n");
	scanf("%d", &length);

	data = (int*)malloc(length * sizeof(int));

	// get input from user
	for (i = 0; i < length; i++)
	{
		printf("Please enter the: %d number of %d \n", (i + 1), length);
		scanf("%d", (data + i));

		if (i != 0)
		{
			// check if the number bigger or equal to previous
			if (data[i - 1] > data[i]) {
				printf("The number must bigger or equal to previous ");
				i--;
			}

		}
	}

	result = GetDef(data, length);
	printf("return value is: %d \n", result);
	free(data);

}
int GetDef(int* arraP, int length) {
	// counter start on one because one number is must be.
	int counter = 1, index = 0, poze = 0;

	while (index < length) {

		if (arraP[poze] != arraP[index])
		{
			// update second index 
			poze++;
			// move to new position the new number
			arraP[poze] = arraP[index];

			// add counter
			counter++;
		}
		else
			index++;
	}
	return counter;
}
void Ex02() {
	int input = -1, result;
	while (input < 1) {
		printf("Please enter a number bigger than 0 \n");
		scanf("%d", &input);
	}
	result = RecursionEx02(input);
	printf("return value is: %d \n", result);
}
int RecursionEx02(int n) {
	int d, temp;

	if (n < 10) {
		// get unit ++ and return new value
		return (n = n + 1) % 10;
	}
	else
	{
		d = RecursionEx02(n / 10);
		d = d * 10;
		// get unit
		temp = (n + 1) % 10;
		// add to result number the new unit 
		return  d + temp;
	}
}
void Ex03() {
	int result = 0, length=1;

	// static array
	char* str1;
	char* str2;
	char* str;
	str1 = (char*)malloc(20 * sizeof(char));
	str2 = (char*)malloc(20 * sizeof(char));
	str = (char*)malloc(20 * sizeof(char));

	// get input
	printf("Enter a string s1 \n");
	scanf("%s",str1);
	flushall();

	printf("Enter a string s2 \n");
	scanf("%s",str2);
	flushall();

	printf("Enter a string s \n");
	scanf("%s",str);
	flushall();

	result = CheckArrayEx03(str1, str2, str);
	printf("return value is: %d \n", result);
	
	// revome memory
	free(str1);
	free(str2);
	free(str);
}
int CheckArrayEx03(char *s1, char *s2, char *s) {
	int counter = 0;
	int result = 1;
	int code;
	int s1length, s2length, slength;
	int arry[26] = { 0 };

	// get length of the strings
	s1length = strlen(s1);
	s2length = strlen(s2);
	slength = strlen(s);

	// count s1 string
	while (counter < s1length) {
		code = s1[counter] - 'a';
		arry[code] ++;
		counter++;
	}
	counter = 0;

	// count s2 string
	while (counter < s2length) {
		code = s2[counter] - 'a';
		arry[code] --;
		counter++;
	}
	counter = 0;

	// check if mach the rules
	while (counter < slength) {
		code = s[counter] - 'a';
		if (arry[code] < 0)
		{
			result = 0;
			counter = slength;
		}
		else
			arry[code] = 0;
		counter++;
	}
	//heck if has more latter than in s
	counter = 0;
	while (counter < slength && result == 1) {
		code = s[counter] - 'a';
		if (arry[counter] > 0) {
			counter = 26;
			result = 0;
		}
		counter++;
	}
	return result;
}
void Ex04() {
	char* input;
	input = (char*)malloc(10 * sizeof(char));

	printf("Enter a string \n");
	flushall();
	gets(input);
	// how to pass the reference of the pointer 
	RebuildArray(input);

	printf("reult: %s \n", input);
	free(input);
}
void RebuildArray(char* input) {
	int length;
	int index = 1, counter = 0, poze = 0;

	// get array length
	length = strlen(input);

	while (index < length && input[index] != '\0') {

		if (input[poze] != input[index])
		{
			// update second index 
			poze++;
			// move to new position the new number
			input[poze] = input[index];

			// add counter
			counter++;
		}
		else
			index++;
	}
	counter++;
	// cut the array
	if (length > 1)
		input[counter] = '\0';
}

void Ex05() {
	int length, result, i;
	// array 
	int* data;

	printf("Enter the number of number do you want to enter \n");
	scanf("%d", &length);
	// create array
	data = (int*)malloc(length * sizeof(int));

	// get input from user
	for (i = 0; i < length; i++)
	{
		printf("Please enter the: %d number of %d \n", (i + 1), length);
		scanf("%d", (data + i));
	}

	result = CountArratZugiLength(data, length);
	// print result
	printf("return value is: %d \n", result);
	// remove memory 
	free(data);
}
int CountArratZugiLength(int* list, int length) {

	int counter = 0;

	// get value
	int value = list[length - 1];
	// check if zugi
	if(value % 2 == 0)
		counter++;
	// not last call to recursion
	if (length - 1 != 0)
		counter += CountArratZugiLength(list, (length - 1));
	return counter;
}

void Ex06() {
	// array 
	int* data;

	int length,i;
	// get size of the array 
	printf("Enter the number of number do you want to enter \n");
	scanf("%d", &length);
	// create array
	data = (int*)malloc(length * sizeof(int));

	// get input from user
	for (i = 0; i < length; i++)
	{
		printf("Please enter the: %d number of %d \n", (i + 1), length);
		scanf("%d", (data + i));
	}

	PrintArray(data, length);
	free(data);
}
void PrintArray(int* input, int length)
{
	int poz = 0;
	int index = length - 1;
	if (index != 0)
	{
		PrintArray(input, (length - 1));
		printf("\n");
	}

	while (poz <= index)
	{
		printf("%d", input[poz]);
		poz++;
	}
}

