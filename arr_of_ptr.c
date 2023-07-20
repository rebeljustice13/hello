//this program is for demnonstrating the use of array of pointer


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void add(int a, int b){
	printf("Sum = %d\n",a+b);
}

void sub(int a, int b){
	printf("Difference %d\n",a-b);
}


void main(){

	void (*ptr[2])(int, int) = {&add, &sub};

	for(int i=0; i < 2; i++){
		ptr[i](20,10);
	}

}



