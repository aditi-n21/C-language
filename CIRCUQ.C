#include<stdio.h>
#include<conio.h>
#define max 10
struct cqueue
{
  int info[max];
  int r,f;
};
 typedef struct cqueue cq;
 cq initcq(cq CQI);
 char cqfull(cq CQF);
 char cqempty(cq CQI);
 void cqinsert(cq *CQP,int x);

 cq del (cq);
 void cdisplay(cq CQD);
 int csize(cq);


void main()
{

  cq CQ;
  char c;
  int ch,n,p,no,s;
  clrscr();
  CQ=initcq(CQ);
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
	     cqinsert(&CQ,no);
	     break;
       case 2:
	     CQ=del(CQ);
	     break;
       case 3:
	    cdisplay(CQ);
	    break;
       case 4:
	     s=csize(CQ);
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

   cq initcq(cq CQI)
 {
   int i;
   for(i=0;i<max;i++)
   CQI.info[i]=0;
   CQI.r=-1;
   CQI.f=-1;
   return(CQI);
 }

  char cqfull(cq CQF)
 {
   if(((CQF.r==(max-1))&&(CQF.f==0))||(CQF.f==(CQF.r+1)))
   return('y');
   else
   return('n');
 }

 char cqempty(cq CQE)
 {
   if(CQE.f==-1)
   return('y');
   else
   return('n');
 }

 void cqinsert(cq *CQP,int x)
 {
    if(cqfull(*CQP)=='y')
    {
       printf("not possible");
       return;
    }
    else
    {
      CQP->r=((CQP->r+1)%max);
      CQP->info[CQP->r]=x;
      if(CQP->f==-1)
       CQP->f=0;
    }
 }

  cq  del(cq CQL)
  {
   int x;
   if(cqempty(CQL)=='y')
   {
     printf("not delete any element");
     return(CQL);
   }
   else
   {
     printf("%d",CQL.info[CQL.f]);
     if(CQL.f==CQL.r)
       CQL=initcq(CQL);
     else
       CQL.f=(CQL.f+1)%max;
     return(CQL);
   }
 }
  void cdisplay(cq CQD)
  {
    int i;
    if(cqempty(CQD)=='y')
     {
      printf("not display any element");
      return;
     }
    else
    {
      if(CQD.r>=CQD.f)
       {
	for(i=CQD.f;i<=CQD.r;i++)
	printf(" %d",CQD.info[i]);
       }
      else
      {
	for(i=CQD.f;i<max;i++)
	printf(" %d",CQD.info[i]);
	for(i=0;i<=CQD.r;i++)
	printf(" %d",CQD.info[i]);
      }
   }
 }
  int csize(cq CQS)
  {
    if(CQS.r>=CQS.f)
      return(CQS.r-CQS.f+1);
    else
      return(max-CQS.f+CQS.r+1);
   }
