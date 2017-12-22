#include<stdio.h>

void Ex01();
int GetDef(int*, int);

void main(){

	Ex01();
}


void Ex01(){
	int length;
	int arry[] = {-50,-10,-10,72,81,81,81,81,93,93};
	length = sizeof(arry) / sizeof(int);
	GetDef(arry, length);

}
int GetDef(int* arraP, int length){
	int counter = 0, i, replace = -1;
	int to = length -1;
	int *P2 = arraP;

	//double value mark as ZERO
	for(i=0; i<to; i++){
		if(arraP[i]==arraP[i+1]){
			arraP[i+1]=arraP[i+2];
		}
		else
		{
				counter ++;
		}
	}
	return counter;
}

		////// sort the array
		//for(i = 0; i< counter; i++)
		//	if(arraP[i+2]==0){
		//		arraP[i+1]=arraP[i+2];
		//		arraP[i+2] = 0;
		//	}
		//	return counter;
	//}