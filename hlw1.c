#include<stdio.h>
int main()
{
	int a,b,c,d;
	float  percentage;
	int Totalmarks;
	char garde ;
	printf("Enter the marks of a\n");
	scanf("%d",&a);
	printf("Enter the marks of b\n");
	scanf("%d",&b);
	printf("Enter the marks of c\n");
	scanf("%d",&c);
	printf("Enter the marks of d\n");
	scanf("%d",&d);
	Totalmarks=a+b+c+d;
	percentage=(float)Totalmarks/ 400*100;
	if(	percentage>=80)
	{
		printf("Garde A");
		
	}
	else if 
	
	(	percentage<80 & 	percentage>=60)
	{
	
	printf("Garde b");
}
	else if (	percentage<60 & 	percentage>=50)
	{
		printf("	Garde c");
	}
	else if(	percentage<50 & 	percentage>=40 ) {
	printf("Garde D");
	}
	else 
	{
		printf("Garde E");
	}

	
	


	
	return 0;
	
	
	
	
}

