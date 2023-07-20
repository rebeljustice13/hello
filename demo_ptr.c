#include <stdio.h>

int main(){
	
	int a = 10, *ptr, **ptr1;
	ptr = &a;
	ptr1 = &ptr;

	printf("%u %u %d %d\n",ptr,*ptr, &ptr,ptr1);

	return 0;

}
