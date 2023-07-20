//This function is to explain the use of functional pointer


#include <stdio.h>
#include <string.h>

#if 0

int add(int a, int b){
	printf("Sum = %d\n",a+b);
	return 0;

}

int main(){

	int (*fun_ptr)(int, int) = &add;

	(*add)(10, 20);

	return 0;
}
#endif

#if 0

void fun1() {printf("Inside func1 \n");}
void fun2() {printf("Inside func2 \n");}

void wrapper(void (*fun)()){
	fun();
}

int main(){

	wrapper(fun1);
	wrapper(fun2);
	return 0;
}

#endif

int compare(const void * a, const void * b){

	printf("a = %d, b = %d\n ",*(int *)a,*(int *)b);
	return (*(int*)a == *(int*)b);
}


int main(){
	
	//int a = 10,b = 10;
	char a='1',b = '1';
	char *ptr1 = &a;
	char *ptr2 = &b;
	if(compare(*ptr1,*ptr2)){
		printf("Both are equal\n");
	}
	else{
		printf("Bot are different\n");
	}
	return 0;
}


