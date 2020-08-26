//dynamic implimentation of stack.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct stk
{
  int info;
  struct stk *next;
};
typedef struct stk *stack;
void push(stack *,int);
int pop(stack *);
void display();
int lsize(stack);
void main()
{
  stack start=NULL;
  int ch,c,s,n,p;
  clrscr();
  do
  {
    printf(" 1.push \n 2.pop \n 3.traverse\n4.size");
    printf("\n enter ur choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("enter element");
	     scanf("%d",&n);
	     push(&start,n);
	     break;
      case 2:
	    s= pop (&start);
	    printf("deleted element is=%d",s);
	    break;
      case 3:
	   display(start);
	   break;
      case 4:s=lsize(start);
	     printf("size of stack is=%d",s);
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
  void push(stack *f,int y)
  {
    stack temp;
    temp=(stack)malloc(sizeof(struct stk));
    temp->info=y;
    temp->next=NULL;
    if(*f==NULL)
      *f=temp;
    else
    {
      temp->next=*f;
      *f=temp;
    }
  }

  int pop(stack *f)
  {
    stack t;
    int y;
    if(*f==NULL)
    {
      printf("deletion nt possible");
      return 0;
    }
    else
    {
      t=*f;
      *f=t->next;
      y=t->info;
      free(t);
      return y;
    }
  }

  void  display(stack f)
  {
    stack t;
    if(f==NULL)
    {
      printf("underflow");
    }
    else
    {
      printf("elements of stack is\n");
      for(t=f;t!=NULL;t=t->next)
      printf("\n %d",t->info);
    }
 }

int lsize(stack f)
{
 int i;
 stack t;
 for(t=f,i=0;t!=NULL;t=t->next,i++);
 return(i);
}


