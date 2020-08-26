#include<stdio.h>
#include<conio.h>
typedef struct
{
  int s1[10];
  int top;
}stack;
void push(stack *s2);
int pop(stack *s2);
void traverse(stack *s2);
void main()
{
  int ch,n,p;
  stack s;
  clrscr();
  s.top=-1;
  do
  {
    printf(" 1.push \n 2.pop \n 3.traverse");
    printf("\n enter ur choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
	     push(&s);
	     break;
      case 2:
	    n=pop(&s);
	    printf("deleted element is=%d",n);
	    break;
      case 3:
	  traverse(&s);
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
  void push(stack *s2)
  {
    int i;
    printf("enter a element");
    scanf("%d",&i);
    if(s2->top>=10)
    {
      printf("overflow");
    }
    else
    {
     s2->top=s2->top+1;
     s2->s1[s2->top]=i;
    }
 }
  int pop(stack *s2)
  {
    int i;
    if(s2->top<-1)
    {
      printf("underflow");
      return 0;
    }
    else
    {
      i=s2->s1[s2->top];
      s2->top=s2->top-1;
      return(i);
    }
  }

  void traverse(stack *s2)
  {
    int i;
    if(s2->top<-1)
    {
      printf("underflow");
    }
    else
    {
      for(i=s2->top;i>=0;i--)
      printf("\n %d",s2->s1[i]);
    }
 }