#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

void Ex01();
int GetDef(int*, int);

void Ex02();
int RecursionEx02(int);

void Ex03();
int CheckArrayEx03(char*, int, char*, int, char *, int);


void Ex04();
void RebuildArray(char*, int);

void Ex05();
int CountArratZugiLength(int*, int);

void Ex05();
int CountArratZugiLength(int*, int);

void Ex06();
void PrintArray(int*, int);

void main() {

	Ex01();
	//Ex02();
	//Ex03();
	//Ex04();
	//Ex05();
	//Ex06();
}


void Ex01() {

	int length = 10;
	int counter = 0, i = 0 ;
	int result = 0;
	int* data = (int*)malloc(length * sizeof(int));
	
	for (i = 0; i < length; i++)
	{
		printf("Please enter the: %d number of %d \n", (i + 1), length);
		scanf("%d", (data + i));
	}



	result = GetDef(data, length);
	printf("%d return value is: ", &result);
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
	int result = RecursionEx02(9999);
	printf("%d return value is: ", &result);
}
int RecursionEx02(int n) {
	int d, temp;

	if (n < 10) {
		// get unit ++ and return new value
		return n++ % 10;
	}
	else
	{
		d = RecursionEx02(n / 10) * 10;
		// get unit
		temp = (++n) % 10;
		// add to result number the new unit 
		return  d + temp;
	}
}


void Ex03() {
	int result = 0;
	char s[] = "c";
	char s1[] = "baaacab";
	char s2[] = "ababab";
	result = CheckArrayEx03(s1, strlen(s1), s2, strlen(s2), s, strlen(s));
	printf("%d return value is: ", &result);
}

int CheckArrayEx03(char *s1, int s1Lenght, char *s2, int s2Lenght, char *s, int sLenght) {
	int counter = 0;
	int result = 1;
	int code;
	int arry[26] = { 0 };


	// count s1 string
	while (counter < s1Lenght) {
		code = s1[counter] - 'a';
		arry[code] ++;
		counter++;
	}
	counter = 0;

	// count s2 string
	while (counter < s2Lenght) {
		code = s2[counter] - 'a';
		arry[code] --;
		counter++;
	}
	counter = 0;

	// check if mach the rules
	while (counter < sLenght) {
		code = s[counter] - 'a';
		if (arry[code] < 0)
		{
			result = 0;
			counter = sLenght;
		}
		else
			arry[code] = 0;
		counter++;
	}
	//heck if has more latter than in s
	counter = 0;
	while (counter < sLenght && result == 1) {
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

	char string[] = "bssdffFdcrrrtttii ***#";
	// how to pass the reference of the pointer 
	RebuildArray(string, strlen(string));

}
void RebuildArray(char* input, int lenght) {

	int index = 1, counter = 0, poze = 0;
	//int *p = *arr;
	int *id;
	while (index < lenght) {

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

