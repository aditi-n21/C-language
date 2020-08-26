//dynamic implimentation of linear q.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct queue
{
  int info;
  struct queue *next;
};
typedef struct queue *q;
void insert(q*,q*,int);
int  del(q*,q*);
void display(q);
int lsize(q);
void main()
{
   q f=NULL,r=NULL;
  int ch,c,s,n,p;
  clrscr();
  do
  {
    printf(" 1.insertion \n 2.deletion \n 3.display\n4.size");
    printf("\n enter ur choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("enter element");
	     scanf("%d",&n);
	     insert(&f,&r,n);
	     break;
      case 2:
	    s= del(&f,&r);
	    printf("deleted element is=%d",s);
	    break;
      case 3:
	   display(f);
	   break;
      case 4:s=lsize(f);
	     printf("size of q is=%d",s);
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
void insert(q *f,q *r,int y)
{
  q temp;
  temp=(q)malloc(sizeof(struct queue));
  temp->info=y;
  temp->next=NULL;
  if(*f==NULL)
    *f=*r=temp;
  else
   {
     (*r)->next=temp;
     *r=temp;
   }
 }
 int del(q *f, q *r)
 {
   q t;
   int y;
   if(*f==NULL)
   {
     printf("deletion nt possible");
     return 0;
   }
   else
   {
     t=*f;
     if(*f==*r)
	*f=*r=NULL;
     else
	*f=t->next;
	y=t->info;
	free(t);
	return(y);
    }
 }
 void display(q f)
 {
   q t;
   if(f==NULL)
     printf("npt possible");
   else
   {
     printf("element in q is");
     for(t=f;t!=NULL;t=t->next)
      printf("%d",t->info);
   }
 }
 int lsize(q f)
 {
   q t;
   int i;
   for(t=f,i=0;t!=NULL;t=t->next,i++);
   return(i);
 }