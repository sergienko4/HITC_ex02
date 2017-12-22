#include<stdio.h>


void Ex01();
int GetDef(int*, int);

void Ex02();
int RecursionEx02(int);


void main(){

	//Ex01();
	//Ex02();
}


void Ex01(){

	int length;
	int arry[] = {-50,-10,-10,72,81,81,81,81,93,93};
	length = sizeof(arry) / sizeof(int);
	GetDef(arry, length);
	//free(arry);

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
