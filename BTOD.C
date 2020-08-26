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
  int r,i,l,p=0;
  int n,c=0;
  clrscr();
  printf("enter digits in  binary no");
  scanf("%d",&c);
  printf("enter the binary no");
  scanf("%d",&n);
  for(i=0;i<c;i++)
  {
    r=n%10;
    n=n/10;
    push(r);
  }
  for(i=0;i<c;i++)
  {
    p=p+pop()*pow(2,i);

  }
    printf("%d",p);
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
