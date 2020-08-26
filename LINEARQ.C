#include<stdio.h>
#include<conio.h>
#define max 10
void initq();
char qfull();
char qempty();
void insertq(int);
int delq();
void display();
int size();
struct queue
{
  int info[max];
  int r,f;
};
 typedef struct queue sq;
 sq q;

void main()
{
  int ch,n,p,no,s;
  clrscr();
  initq();
  do
  {
    printf(" 1.insert \n 2.delete \n 3.display \n 4.size");
    printf("\n enter ur choice");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
	     printf("enter the no u want to insert=");
	     scanf("%d",&no);
	     insertq(no);
	     break;
       case 2:
	    n=delq();
	    printf("deleted element is=%d",n);
	    break;
       case 3:
	    display();
	    break;
       case 4:
	     s=size();
	     printf("size is=%d",s);
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

 void initq()
 {
   int i;
   for(i=0;i<max;i++)
   q.info[i]=0;
   q.r=-1;
   q.f=-1;
 }

  char qfull()
 {
   if(q.r==(max-1))
   return('y');
   else
   return('n');
 }

 char qempty()
 {
   if(q.f==-1)
   return('y');
   else
   return('n');
 }

 void insertq(int x)
 {
    if(qfull()=='y')
    {
       printf("not possible");
       return(-99);
    }
    else
    {
      q.r++;
      q.info[q.r]=x;
      if(q.f==-1)
       q.f=0;
    }
 }

 int  delq()
 {
   int x;
   if(qempty()=='y')
   {
     printf("not delete any element");
     return(-99);
   }
   else
   {
     x=q.info[q.f];
     if(q.f==q.r)
       initq();
     else
       q.f++;
     return(x);
   }
 }
  void display()
  {
    int i;
    if(qempty()=='y')
     {
      printf("not display any element");
      return(-99);
     }
    else
    {
      for(i=q.f;i<=q.r;i++)
      printf(" %d",q.info[i]);
    }
  }

  int size()
  {
    return(q.r-q.f+1);
  }

