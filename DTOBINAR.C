#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
int stack[20];
int top=-1;
void push(int);
int pop();
void main()
{
  int n,i,r,s;
  clrscr();
  printf("enter any decimal no");
  scanf("%d",&n);
  while(n>0)
  {
    r=n%2;
    n=n/2;
    push(r);
  }
   for(i=top;i>=0;i--)
   {
    s=pop();
    printf("%d",s);
  }
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
