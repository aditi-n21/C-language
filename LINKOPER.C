#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct NODE
{
	int info;
	struct NODE *next;
};
typedef struct NODE *node;
node createlist(node,int);
int size(node);
void display(node);
void search(node,int);
node sort(node);
void split(node,int);
node insertl(node,int);
node merge(node,node);
node reverse(node);
node dup(node);
node move(node,int,int);
void main()
{
	node start=NULL;
	node start1=NULL;
	node start2=NULL;
	int a,b,c,x,n,in,no,m1,n1,p1,p2;
	clrscr();
	do
	{
		printf("enter the choice");
		printf("\n1.create a list");
		printf("\n2.display\n3.search\n4.sorting\n5.spliting\n6.merging");
		printf("\n7.reverse\n");
		printf("8.duplicate removal\n");
		printf("9.move 1 pos to another\n");
		scanf("%d",&c);
		switch(c)
		{
			case 2:
				display(start);
				break;
			case 1:
			      printf("enter the no of nodes want to insert");
			      scanf("%d",&n);
			      start=createlist(start,n);
			      break;
			case 3:
			      printf("enter a element");
			      scanf("%d",&no);
			      search(start,no);
			      break;
			case 4:
			       printf("sorted element is");
			       start=sort(start);
			       display(start);
			       break;
			case 5:printf("enter pos from which u wnt to split");
			       scanf("%d",&in);
			       split(start,in);
			       break;
			case 6:printf("need 2 list");
			       printf("no of nodes in list1");
			       scanf("%d",&p1);
			       printf("no of nodes in list2");
			       scanf("%d",&p2);
			       start1=createlist(start1,p1);
			       start2=createlist(start2,p2);
			       start=merge(start1,start2);
			       display(start);
			       break;
		       case 7:start=reverse(start);
			      display(start);
			      break;

		       case 8:start=dup(start);
			      display(start);
			      break;
		       case 9:printf("enter 2 node pos");
			      scanf("%d%d",&m1,&n1);
			      start=move(start,m1,n1);
			      break;

			default:
				printf("wrong choice");


  }
  printf("\nif u want to continue press 1 else press 0");
  scanf("%d",&b);

}while(b==1);

  getch();
}

void display(node f)
{
	node t;
	int i;
	if(f==NULL)
	{
	 printf("not possible");
	 return;
	}
	else
	{
	 for(t=f;t!=NULL;t=(t->next))
	 printf("%d\n",t->info);
	}
   }
int size(node f)
{
	int i;
	node t;
	for(i=0,t=f;t!=NULL;t=t->next,i++);
	return i;
}
node createlist(node f,int n)
{
  int i,j,y;
  node temp,t;
  for(i=1;i<=n;i++)
  {
    printf("enter a value u want to insert");
    scanf("%d",&y);
    temp=(node)malloc(sizeof(struct NODE));
    temp->info=y;
    temp->next=NULL;
    if(f==NULL)
     f=temp;
    else
   {
    for(t=f;t->next!=NULL;t=t->next);
    t->next=temp;
   }
  }
   return(f);
}
void search(node f,int key)
{
  int c=0,i;
  node t;
  if(f==NULL)
  {
    printf("not  possible");
    return;
  }
  else
  {
    for(t=f,i=1;t!=NULL;i++,t=t->next)
    {
      if(t->info==key)
      {
	c++;
	printf("element found at %d position",i);
      }
    }
    if(c==0)
    printf("not found");
    else
    printf("\noccurance is of %d times",c);
  }
}
node sort(node f)
{
  node t,p;
  int temp;
  if(f==NULL)
  {
    printf("not possible");
    return(f);
  }
  else
  {
    for(t=f;t!=NULL;t=t->next)
      for(p=t->next;p!=NULL;p=p->next)
	if(t->info>p->info)
	{
	  temp=t->info;
	  t->info=p->info;
	  p->info=temp;
	 }
	 return(f);
    }
 }
void split(node f,int pos)
{
  node t,f1;
  int i,j;
  i=size(f);
  if(pos>i)
  {
    printf("not possible");
    return;
  }
  else
  {
    for(t=f,j=1;j<(pos-1);t=t->next,j++);
    f1=t->next;
    t->next=NULL;
    printf("1st linked list is");
    display(f);
    printf("2nd link list is");
    display(f1);
   }
 }
node merge(node f1,node f2)
{
  node f=NULL;
  node t1,p,q,r,t;
  sort(f1);
  sort(f2);
  if((f1==NULL)&&(f2==NULL))
  {
    printf("not possible");
    return;
  }
  else if((f1==NULL)&&(f2!=NULL))
  {
    return(f2);
  }
  else if((f1=!NULL)&&(f2==NULL))
  {
    return(f1);
  }
  else if((f1!=NULL)&&(f2!=NULL))
  {
    for(t=f1,p=f2;t!=NULL&&p!=NULL;  )
    {
      if(t->info<p->info)
      {
	f=insertl(f,t->info);
	t=t->next;
      }
      if(t->info>p->info)
      {
	f=insertl(f,p->info);
	p=p->next;
      }
      else if(t->info==p->info)
      {
	f=insertl(f,t->info);
	t=t->next;
	p=p->next;
      }
   }
   }
   while(t!=NULL)
   {
     f=insertl(f,t->info);
     t=t->next;
   }
   while(p!=NULL)
   {
     f=insertl(f,p->info);
     p=p->next;
   }
    return(f);
 }

node insertl(node f, int x)
{
	int i,y;
	node temp,t;
	printf("enter a value u want to insert");
	scanf("%d",&y);
	temp=(node)malloc(sizeof(struct NODE));
	temp->info=y;
	temp->next=NULL;
	if(f==NULL)
	{
		f=temp;
		return f;
	}
	else
	{
		for(t=f;t->next!=NULL;t=t->next);
		t->next=temp;

		return f;
	}
}
node reverse(node f)
{
  node t,t1,f1=NULL;
  int i,j=1;
  i=size(f);
  if(i<=1)
  {
    printf("not possible");
    return(f);
  }
  else
  {
    while(i>1)
    {
      for(t=f,j=1;j<i;t1=t,t=t->next,j++);
      if(f1==NULL)
       f1=t;
       t->next=t1;
       i--;
     }
     t1->next=NULL;
     return(f1);

    }
 }
 node dup(node f)
 {
  node t,t1;
  node f1=NULL;
  int i;
  i=size(f);
  if(i<=1)
  {
    printf("not possible");
    return(f);
  }

  else
  {
    f=sort(f);
    for(t=f;t->next!=NULL;  )
    {
    t1=t->next;
     if(t->info==t1->info)
     {
       t->next=t1->next;
       free(t1);
     }
     else
     {
       t=t->next;
     }
   }
 }
   return(f);
}
node move(node f,int p1,int p2)
{
  node t,t1;
  int i,j;
  i=size(f);
  if(i<=1)
  {
    printf("not possible");
    return(f);
  }
  else
  {
    for(t=f,j=1;j<p1;j++,t1=t,t=t->next);
     t1->next=t->next;
     if(p1==1)
     {
       t->next=f;
       f=t;
     }
     else
     {
      for(t1=f,j=1;j<(p2-1);j++,t1=t1->next);
      t->next=t1->next;
      t1->next=t;
     }
     return(f);
   }
 }
