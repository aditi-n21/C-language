#include<stdio.h>
#include<conio.h>
#define max 3
int top=-1;
int top1=max+1;
int stack[max];
void push(int);
void push1(int);
int pop();
int pop1();
void traverse();
void main()
{
  int c,n,p,i,ele;
  clrscr();
  do
  {
    printf(" 1.push from bottom \n 2push from top\ n3.pop from bottom \n 4.pop from top\n5.traverse");
    printf("\n enter ur choice");
    scanf("%d",&c);
    switch(c)
    {
      case 1:
	     printf("enter a element");
	     scanf("%d",&ele);
	     push(ele);
	     break;
      case 2:
	    printf("enter a element");
	    scanf("%d",&ele);
	    push1(ele);
	    break;
      case 3:
	   if(top==-1)
	   {
	     printf("underflow");
	   }
	   else
	   {
	     i=pop();
	     printf("poped element is=%d",i);
	   }
	   break;
     case 4:
	   if(top==max+1)
	   {
	     printf("stack underflow");
	   }
	   else
	   {
	     i=pop1();
	     printf("\n poped element is=%d",i);
	   }
	   break;


      case 5:
	  traverse();
	  break;
      default:
	  printf("wrong choice");
	  break;
     }
      printf("if u want to continue press 1 else 0");
      scanf("%d",&p);
   }
     while(p!=0);
     getch();
}
  void push(int ele)
  {
    //int i;
    //printf("enter a element");
   // scanf("%d",&i);
    if(top+2==top1)
    {
      printf("overflow");
    }
    else
    {
     top=top+1;
     stack[top]=ele;
    }
 }


 void push1(int ele)
 {
   if(top+2==top1)
    {
      printf("overflow");
    }
    else
    {
     top1=top1-1;
     stack[top1]=ele;
    }
 }

 int pop()
 {
   int k;
   k=stack[top];
   top--;
   return(k);
 }
 int pop1()
 {
   int k;
   k=stack[top1];
   top1++;
   return(k);
 }
  void traverse()
  {
    int i;
    if(top==-1)
     printf("\n stack underflow");
    else
    {
       printf("element of stack is");
       for(i=max;i>=top;i--)
	 printf("\n %d",stack[i]);
       for(i=top;i>=0;i--)
	 printf("\n %d",stack[i]);
     }

  }

