#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

void Ex01();
int GetDef(int*, int);

void Ex02();
int RecursionEx02(int);

void Ex03();
int CheckArrayEx03(char* , int , char* , int , char *, int );


void Ex04();
void RebuildArray(int*, int);

void main(){

	//Ex01();
	//Ex02();
	//Ex03();
	Ex04();
}


void Ex01(){

	int length;
	int arry[] = {-50,-10,-10,72,81,81,81,81,93,93};
	length = sizeof(arry) / sizeof(int);
	GetDef(arry, length);
	free(arry);

}
int GetDef(int* arraP, int length){
	// counter start on one because one number is must be.
	int counter = 1, index = 0, poze = 0;

	while(index<length){

		if(arraP[poze] != arraP[index])
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

void Ex02(){
	int result =RecursionEx02(9999);
}
int RecursionEx02(int n){
	int d, temp;

	if(n<10) {
		// get unit ++ and return new value
		return n++%10;
	}
	else
	{
		d = RecursionEx02(n/10) *10;
		// get unit
		temp = (++n)%10;
		// add to result number the new unit 
		return  d + temp;
	}
}


void Ex03(){
	int result = 0;
	char s[] = "c";
	char s1[] = "baaacab";
	char s2[] = "ababab";
	result = CheckArrayEx03(s1, strlen(s1), s2, strlen(s2), s , strlen(s));
}

int CheckArrayEx03(char *s1, int s1Lenght, char *s2, int s2Lenght, char *s, int sLenght ){
	int counter= 0 ;
	int code;
	int arry[26] = {0};


	// count s1 string
	while(counter< s1Lenght){
		code = s1[counter] - 'a';
		arry[code] ++;
		counter++;
	}
	counter = 0;

	// count s2 string
	while(counter<s2Lenght){
		code = s2[counter] - 'a';
		arry[code] --;
		counter++;
	}
	counter = 0;

	// check if mach the rules
	while(counter<sLenght){
		code = s[counter] - 'a';
		if(arry[code] < 0)
		{
			free(arry);
			return 0;
		}
		counter++;
	}
	free(arry);
	return 1;
}

void Ex04(){
	
	char string[] = "bssdffFdcrrrtttii ***#";
	// how to pass the reference of the pointer 
	RebuildArray(&string, strlen(string));

}
void RebuildArray(char **arr , int lenght ){
	
	int index = 1, counter = 0, poze = 0;
	int *input = *arr
	while(index<lenght){

		if(input[poze] != input[index])
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
		input = (char *) realloc(input, counter);

}


