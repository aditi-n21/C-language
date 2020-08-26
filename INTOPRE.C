#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
int st[20];
int top=-1;
void push(char);
int pre();
char pop();
void main()
{
  int i=0,l,pos=0,c,t,j;
  char post[10],infix[10];
  clrscr();
  printf("enter the infix expression");
  gets(infix);
  strrev(infix);
  l=strlen(infix);
  while(i<l)
  {
    c=infix[i];
    switch(c)
    {
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
      case '^':
      {
	for(j=top;j>=0;j--)
	{
	  if(st[j]=='(')
	  break;
	  if(pre(st[j])>=pre(c))
	  post[pos++]=pop();
	}
	  push(c);
	  break;
     }
     case ')':
	    push(c);
	    break;
     case '(':
	     for(j=top;st[j]!=')';j--)
	     post[pos++]=pop();
	     t=pop();
	     break;
     default:




	     post[pos++]=c;

  }
   i++;
 }

  for(j=top;j>=0;j--)
  post[pos++]=pop();
  printf("\n prefix expression is=");
  strrev(post);
  for(i=0;i<pos;i++)
  printf("%c",post[i]);
  getch();
}

  int pre(char c)
  {
    if(c=='^')
    return (9);
    if(c=='%'||c=='*'||c=='/')
    return (8);
    if(c=='+'||c=='-')
    return (5);
  }

  void push(char c)
{
    if(top>=20)
    {
      printf("overflow");
    }
    else
    {
     top=top+1;
     st[top]=c;
    }
 }
   char  pop()
  {
    char c ;
    if(top<-1)
    {
      printf("underflow");
      return 0;
    }
    else
    {
      c=st[top];
      top=top-1;
      return(c);
    }
  }
