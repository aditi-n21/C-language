#include<stdio.h>
#include<conio.h>
void push();
int pop();
void traverse();
struct stack
{
  int s[10];
  int top;
}st;
void main()
{
  int ch,n,p;
  clrscr();
  st.top=-1;
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
   }
     while(p!=0);
     getch();
}
  void push()
  {
    int i;
    printf("enter a element");
    scanf("%d",&i);
    if(st.top>=10)
    {
      printf("overflow");
    }
    else
    {
     st.top=st.top+1;
     st.s[st.top]=i;
    }
 }
  int pop()
  {
    int i;
    if(st.top<-1)
    {
      printf("underflow");
      return 0;
    }
    else
    {
      i=st.s[st.top];
      st.top=st.top-1;
      return(i);
    }
  }

  void traverse()
  {
    int i;
    if(st.top<-1)
    {
      printf("underflow");
    }
    else
    {
      for(i=st.top;i>=0;i--)
      printf("\n %d",st.s[i]);
    }
 }