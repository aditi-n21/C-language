
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
char stack[20];
int top=-1;
void push(char);
char pop();
void main()
{
  int n,i,l,p=0,it;
  char s[20],c;
  clrscr();
  printf("enter any binary no");
  fflush(stdin);
  gets(s);
  for(i=0;i<strlen(s);i++)
  push(s[i]);
  for(i=0;i<strlen(s);i++)
  {
    c=pop();
    it=c-'0';
    p=p+it*pow(2,i);

  }
    printf("%d",p);
    getch();
 }

  void push(char m)
  {
    if(top>=20)
    {
      printf("overflow");
    }
    else
    {
     top=top+1;
     stack[top]=m;
    }
 }
  char pop()
  {
    char m;
    if(top<-1)
    {
      printf("underflow");
      return 0;
    }
    else
    {
      m=stack[top];
      top=top-1;
      return(m);
    }
  }
