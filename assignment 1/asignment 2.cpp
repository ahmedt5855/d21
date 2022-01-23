#include <stdio.h>
#include <math.h>
int main()
{
	int x,y;
	char op;
	printf("please enter the first and operator and the second number \n"); // num1 op num 2 ex: 1+2
	scanf("%d %c %d",&x,&op, &y);	

	if(op == '+' )
	{
		printf("x+y = %d ",x+y);
	}
	else if(op == '-')
	printf("x-y = %d",x-y);
	else if(op == '*')
	printf("x*y = %d",x*y);
	else if(op == '%')
	printf("x%y = %d",x%y);
	else if((op == '/')&& (y>0))
	printf("x/y = %d",x/y);
	else 
	printf("Invalid because second number is zero");
	return 0;
}
