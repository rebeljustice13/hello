//this program is for structure pointer
//
#include <stdio.h>
#include <string.h>

struct employee{
	int id;
	char name[20];
};


struct employee emp, *ptr;

int main(){
	//struct employee emp;
	//struct employee *ptr = &emp;
		
	ptr = &emp;

	(*ptr).id = 20;
	strcpy((*ptr).name,"shivam sing");
		
	printf("The id is %d\n",(*ptr).id);
	printf("The name is %s\n",(*ptr).name);

	return 0;
}


