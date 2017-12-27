#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

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

void main() {

	//Ex01();
	//Ex02();
	//Ex03();
	Ex04();
	//Ex05();
	//Ex06();
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
	printf("return value is: %d ", &result);
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
	int result = 0;
	char s[] = "c";
	char s1[] = "baaacab";
	char s2[] = "ababab";

	//get input from user

	// static array
	char str1[51];
	char str2[51];
	char str[51];
	printf("Enter a string s1 ( not more that 50 chars) \n");
	gets(str1);

	printf("Enter a string s2 ( not more that 50 chars) \n");
	gets(str2);

	printf("Enter a string s ( not more that 50 chars) \n");
	gets(str);

	result = CheckArrayEx03(str1, str2, str);
	printf("return value is: %d \n", result);
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
	//free(*arry);
	return result;
}

void Ex04() {

	char* input, length, i;
	input = (char*)malloc(51 * sizeof(char));


	printf("Enter a string ( not more that 50 chars) \n");
	gets(input);
	// how to pass the reference of the pointer 
	RebuildArray(input);

	printf("reult: %s \n", input);

}
void RebuildArray(char* input) {
	int length;
	int index = 1, counter = 0, poze = 0;
	//int *p = *arr;
	char* newArray;

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
	
	// resize the string
	//id = (char *)realloc(input, counter*sizeof(char));

}

void Ex05() {
	int result = 0;
	int array[] = { 4, 4, 8, 0, 1, 2, 7, 8 };
	result = CountArratZugiLength(array, sizeof(array) / sizeof(int));
	printf("%d return value is: ", &result);
}
int CountArratZugiLength(int* array, int length) {

	int counter = 0;
	int value = array[length - 1];
	if (length - 1 == 0 && value % 2 == 0)
		counter++;
	else {
		counter = CountArratZugiLength(array, (length - 1));
		if (value % 2 == 0)
			counter++;
	}
	return counter;
}

void Ex06() {
	int array[] = { 9,0,2,6 };
	PrintArray(array, sizeof(array) / sizeof(int));
}
void PrintArray(int* input, int length)
{
	int poz = 0;
	int index = length - 1;
	if (index == 0)
	{
	}
	else
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

