#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

double compute(char symbol, double op1,double op2)
{
  switch(symbol)
  {
     case '+': return op1+op2;
     break;
     case '-': return op1-op2;
     break;
     case '*': return op1*op2;
     break;
     case '/': return op1/op2;
     break;
     case '^': return pow(op1,op2);
     break;
     default: printf("invalid operator:%c\n",symbol);
     return 0;
    }
}
int main()
{
  double s[20],res,op1,op2;
  int top=-1,i;
  char postfix[20],symbol;
  printf("\nEnter a valid postfix expression: ");
  scanf("%s",postfix);
  //start of evaluation
  for(i=0;i<strlen(postfix);i++)
  {
    symbol=postfix[i];
    if(isdigit(symbol))
       s[++top]=symbol-'0';
    else
     {
       op2=s[top--];
       op1=s[top--];
       //perform the operation

       res=compute(symbol,op1,op2);
       s[++top]=res;

    }

   }
res=s[top--];
printf("\n The postfix evaluation result is:%f",res);
return 0;
}







