#include <stdio.h>
int main()
{
	int x,remainder,rev=0;
	printf("enter number \n");
	scanf("%d",&x);
	for(int i=0 ;x!=0;i++)
	{
		remainder=x%10; 
		rev=rev*10+remainder;
		x/=10;
	}
	printf("%d",rev);
	return 0;
}
