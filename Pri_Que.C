#include<stdio.h>
#include<conio.h>
#define max 10
struct queue
{
  int info[2][max];
  int r,f;
};
 typedef struct queue pq;
pq initq(pq);
char qfull(pq);
char qempty(pq);
pq insertq(pq,int,int);
pq delq(pq);
void display(pq);
int size(pq);
pq arrenge(pq);


void main()
{
  int ch,n,p,no,s;
  pq PQ;
  clrscr();
  PQ=initq(PQ);
  do
  {
    printf(" 1.insert \n 2.delete \n 3.display \n 4.size");
    printf("\n enter ur choice");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
	     printf("enter the no u want to insert and prority of it=");
	     scanf("%d%d",&no,&p);
	     PQ=insertq(PQ,no,p);
	     break;
       case 2:
	    PQ=delq(PQ);
	    break;
       case 3:
	    display(PQ);
	    break;
       case 4:
	     s=size(PQ);
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

  pq initq(pq PI)
 {
   int i,j;
   for(i=0;i<2;i++)
    for(j=0;j<max;j++)
    PI.info[i][j]=0;
    PI.r=-1;
    PI.f=-1;
    return(PI);
 }

  char qfull(pq PI)
 {
   if(PI.r==(max-1))
   return('y');
   else
   return('n');
 }

 char qempty(pq PI)
 {
   if(PI.f==-1)
   return('y');
   else
   return('n');
 }

  pq insertq(pq PI,int x,int p1)
 {
    if(qfull(PI)=='y')
    {
       printf("not possible");
       return(PI);
    }
    else
    {
      PI.r++;
      PI.info[0][PI.r]=x;
      PI.info[1][PI.r]=p1;
      if(PI.f==-1)
       PI.f=0;
       PI=arrenge(PI);
       return(PI);
    }
 }

 pq delq(pq pd)
 {
   int x,y;
   if(qempty(pd)=='y')
   {
     printf("not delete any element");
     return(pd);
   }
   else
   {
     x=pd.info[0][pd.f];
     y=pd.info[1][pd.f];
     printf("deleted element is=%d",x);
     printf("priority of that element is=%d",y);
     if(pd.f==pd.r)
	pd=initq(pd);
     else
       pd.f++;

     return(pd);
   }
 }
  void display(pq pd)
  {
    int i;
    if(qempty(pd)=='y')
     {
      printf("not display any element");
      return;
     }
    else
    {
      for(i=pd.f;i<=pd.r;i++)
      printf(" %d",pd.info[0][i]);
    }
  }

  int size(pq ps)
  {
    return(ps.r-ps.f+1);
  }

  pq arrenge(pq pr)
  {
    int i,j,t;
    for(i=pr.f;i<=pr.r;i++)
     for(j=i+1;j<=pr.r;j++)
      if(pr.info[1][i]>pr.info[1][j])
      {
	t=pr.info[0][i];
	pr.info[0][i]=pr.info[0][j];
	pr.info[0][j]=t;
	t=pr.info[1][i];
	pr.info[1][i]=pr.info[1][j];
	pr.info[1][j]=t;

      }
       return(pr);

  }