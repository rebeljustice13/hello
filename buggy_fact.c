# include <stdio.h>

int main()
{
	int i=0, num=0, j=1;
	printf ("Enter the number: ");
	scanf ("%d", &num );

	for (i=1; i<num; i++)
		j=j*i;    

	printf("The factorial of %d is %d\n",num,j);
}
