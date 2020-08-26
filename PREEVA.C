#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int stack[20];
int top=-1;
void push(int);
int pop();
void main()
{
  char ex[10];
  int i=0,l,t,op1,op2,h;
  clrscr();
  printf("enter the expression");
  fflush(stdin);
  gets(ex);
  strrev(ex);
  l=strlen(ex);
  do
  {
   if(isalpha (ex[i]))
   {
     printf("enter values");
     scanf("%d",&t);
     push(t);
   }
   else
   {
    op1=pop();
    op2=pop();
    switch(ex[i])
    {
     case'+':
	  h=op1+op2;
	  push(h);
	  break;
    case'-':
	  h=op1-op2;
	  push(h);
	  break;
    case'*':
	  h=op1*op2;
	  push(h);
	  break;
    case'^':
	  h=pow(op2,op1);
	  push(h);
	  break;
    case'%':
	  h=op2%op1;
	  push(h);
	  break;
    }
  }
    i++;
 }while(i<l);
 printf("{evaluation of postfix expression is=%d",h);
 getch();
}

void push(int i)
{
    if(top>=20)
    {
      printf("overflow");
    }
    else
    {
     top=top+1;
     stack[top]=i;
    }
 }
  int pop()
  {
    int i;
    if(top<-1)
    {
      printf("underflow");
      return 0;
    }
    else
    {
      i=stack[top];
      top=top-1;
      return(i);
    }
  }
