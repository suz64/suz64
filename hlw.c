// WAP to print a number that is divides by 3 or not  and that is even or not.
#include<stdio.h>
int main()
{
 int a;
 printf("Enter the number :\n");
 scanf("%d",& a);

 if (a%2==0)
 {
	printf("Number is even \n");
	if (a%3==0)
	{
		printf("The number is divisible by 3 ");
	}
 } else {
	printf("Number is odd \n");
	
		printf("The number is not divisible by 3 ");
 }
	
 

return 0;

}
	



