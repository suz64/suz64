#include<stdio.h>
int main()
{
double   num1,num2,sum,mul,div,mod,sub,result;
char  operator;


// user enter the value 
 printf("Enter calculation (e.g., 2 + 4): ");
    scanf("%lf %c %lf", &num1, &operator, &num2);



switch(operator)
{

 case '+':
  sum = num1+num2;
  result = sum;
  break;

  case '-':
  sub =num1 -num2;
  result = sub;
  break;

  case '/':
  if (num2!=0)
  {

 
      div =num1/num2;
      result = div;
    
  }
  else  
  printf("Error");
  break;

  case '*':
  mul = num1 * num2;
  result = mul;
  break ;
   


  default:
  printf(" Error");




}

printf("result: %.21f",result);


 return 0;

}