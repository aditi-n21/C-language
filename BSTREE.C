
bst bdelete(bst,int)#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct bnode
{
  int data;
  struct bnode *lc,*rc ;
};
typedef struct bnode *bst;
bst insert(bst,int);
void search(bst,int);;
void pretrav(bst);
void main()
{
  int a,b,c,i,j,info;
  char ch,p;
  bst root=NULL;
  clrscr();
  do
  {
    printf("1:insertion \n2:deletion\n3:search\n4.traverse\n" );
    printf("enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("enter a element");
	      scanf("%d",&a);
	      root=insert(root,a);
	      break;
      case 2:printf("enter the info u want to delete");
	     scanf("%d",&info);
	     root=bdelete(root,info);
	     break;
      case 3:printf("enter a no");
	     scanf("%d",&b);
	     search(root,b);
	     break;
      case 4:pretrav(root);
	     break;
      default:printf("wrong choice");
	      break;

    }
    printf("if u want to continue press 1 else 0");
    scanf("%d",&c);
  }
    while(c!=0);
    getch();
}
bst insert(bst f,int x)
{
  bst temp,t,p;
  temp=(bst)malloc(sizeof(struct bnode));
  temp->data=x;
  temp->lc=temp->rc=NULL;
  if(f==NULL)
  {
    f=temp;
    return(f);
  }
  else
  {
    t=f;
    do
    {
       p=t;
       if(temp->data<t->data)
	  t=t->lc;
       else if(temp->data>t->data)
	  t=t->rc;
       else
	  {
	   printf("insertion not possible");
	   return(f);
	  }
      }
       while(t!=NULL);
	if(temp->data<p->data)
	  p->lc=temp;
	else
	  p->rc=temp;
     }

    return(f);
}
void pretrav(bst f)
{
  if(f!=NULL)
  {
    printf("%d",f->data);
    pretrav(f->lc);
    pretrav(f->rc);
   }
}
void search(bst f,int x)
{
  bst t,p;
  int i=0;
  if(f==NULL)
  {
    printf("nt possible");
    return;
  }
  else
  {
    t=f;
    do
    {
      i++;
      if(x<t->data)
	 t=t->lc;
      else if(x>t->data)
	 t=t->rc;
      else if(x==t->data)
	 {
	   printf("found at %d level",i);
	   return;
	  }
    }
     while(t!=NULL);
     printf("not found at any level");
  }
}
bst bdelete(bst f,int x)
{
  bst t,p,q,t1,t2,t3;
  if(f==NULL)
  {
     printf("not possible");
     return(f);
  }
  else
  {
     t=f;
     while((t!=NULL) && (x==t->data))
     {
       p=t;
       if(x<t->data)
	  t=t->lc;
       else if(x>t->data)
	  t=t->rc;
       }
   }
      if(t==NULL)
      {
	printf("not found");
	return(f);
      }
      else
      {
	if((t->lc==NULL)&&(t->rc==NULL))
	{
	  if(t->data<p->data)
	      p->lc=NULL;
	  else
	      p->rc=NULL;
	 }
	 if((t->lc!=NULL)&&(t->rc==NULL))
	 {
	  if(t->data<p->data)
	      p->lc=t->lc;
	  else
	      p->rc=t->lc;
	 }
	 if((t->lc==NULL)&&(t->rc!=NULL))
	 {
	  if(t->data<p->data)
	      p->lc=t->rc;
	  else
	      p->rc=t->rc;
	 }
	 if((t->lc!=NULL)&&(t->rc!=NULL))
	 {
	   t1=t->lc;
	   t2=t->rc;
	   while(t1!=NULL)
	   {
	     t3=t1;
	     t1=t1->rc;
	   }
	     t3->rc=t2;
	     if(t==p)
		f=t->lc;
	     else if(t->rc!=NULL)
		 f=t->rc;
	     else if(t->lc!=NULL)
		 f=t->lc;
	     else
	     {
	       if(t->data<p->data)
		  p->lc=t->lc;
	       else
		  p->rc=t->lc;
	     }
	  }
       }

    free(t);
    return(f);
}

