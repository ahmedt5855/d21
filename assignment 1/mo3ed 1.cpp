#include <stdio.h>
int main ()
{
	int x,y,z=0;
	printf("Enter three numbers \n");
	scanf("%d %d %d",&x,&y,&z);
	if(x>y && x>z)
		printf("%d is the largest nuber \n",x);
		else if(y>x &&y>z)
		printf("%d is the largest number \n",y);
		else 
		printf("%d is the largest number \n ",z);
		if (x<y && x<z)
		printf("%d is the smallest number",x);
		else if (y<z && y<x)
		printf("%d is the smallest number",y);
		else
		printf("%d is the smallest number",z);
	return 0;
}
