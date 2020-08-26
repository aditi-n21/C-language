#include<stdio.h>
#include<conio.h>
int stack[20];
int top=-1;
void push();
int pop();
void traverse();
void main()
{
  int ch,n,p;
  clrscr();
  do
  {
    printf(" 1.push \n 2.pop \n 3.traverse");
    printf("\n enter ur choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
	     push();
	     break;
      case 2:
	    n=pop();
	    printf("deleted element is=%d",n);
	    break;
      case 3:
	  traverse();
	  break;
      default:
	  printf("wrong choice");
	  break;
     }
      printf("if u want to continue press 1 else 0");
      scanf("%d",&p);
     while(p!=0);
     getch();
}
  void push()
  {
    int i;
    printf("enter a element");
    scanf("%d",i);
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
  int pop1()
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
      top=top;
      return(i);
    }
  }

  void traverse()
  {
    int i;
    if(top<-1)
     printf("underflow"); 
    else
    {
      for(i=top;i>=0;i--)
      printf("\n %d",stack[i]);
    }
 }
