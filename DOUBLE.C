#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct NODE
{
	int info;
	struct NODE *next;
	struct NODE *pre;
};
typedef struct NODE *node;
node insertl(node ,int);
node insertb(node ,int);
node insertsp(node ,int,int);
node createnode(node,int);
node createlist(node,int);
node deletel(node);
node deleteb(node );
node deletesp(node,int);
int lsize(node);
void display(node);
void displayb(node);
void main()
{
	node start=NULL;
	int a,b,c,x,e,n,s ;
	clrscr();
	do
	{
		printf("enter the choice \n 1.insert from begin\n 2:insert to last\n3:insert at specified position\n4:delete from first\n 5:delete at last\n 6: delete from specified position\n 7:display\n8:display reverse\n");
		printf(" \n9.create a list\n10.size\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("enter a no");
				scanf("%d",&x);
				start =insertb(start,x);
				break;
			case 2: printf("enter a no");
				scanf("%d",&x);
				start=insertl(start,x);

				break;
			case 3:printf("enter a no");
				scanf("%d",&x);
				printf("enter the position");
				scanf("%d",&a);
				start=insertsp(start,x,a);
				break;

			case 4:
				start=deleteb(start) ;
				break;

			case 5:

				start=deletel(start);
				break;
			case 6:
			       printf("enter position");
			       scanf("%d",&e);
			       start=deletesp(start,e);

				break;

			case 7:
				display(start);
				break;
			case 8:

				displayb(start);
				break;
			case 9:printf("enter no of node");
			       scanf("%d",&n);
			       start=createlist(start,n);
			       break;
			case 10:s=lsize(start);
				printf("size is=%d",s);
			       break;

			default:
				printf("wrong choice");
		}
  printf("if u want to continue press 1 ");
  scanf("%d",&b);
}while(b==1);
getch();
}
void display(node f)
{
	node t;
	int i;
	for(t=f;t!=NULL;t=(t->next))
		printf("%d\n",t->info);
}
void displayb(node f)
{
	node t;
	int i;
	for(t=f;t->next!=NULL;t=(t->next));
	for( ;t!=NULL;t=t->pre)
		printf("%d\n",t->info);
}
node insertb(node f, int x)
{
	node temp;
	temp=createnode(temp,x);

	if(f==NULL)
	{
		f=temp;
		return f;
	}
	else
	{
		temp->next=f;
		f->pre=temp;
		f=temp;
		return f;
	}
}
node insertl(node f, int x)
{
	int i;
	node temp,t;
	temp=createnode(temp,x);

	if(f==NULL)
	{
		f=temp;
		return f;
	}
	else
	{
		for(t=f;t->next!=NULL;t=t->next);
		t->next=temp;
		temp->pre=t;
		return f;
	}
}
node createnode(node f,int x)
{
	f=(node)malloc(sizeof(struct NODE));
	f->info=x;
	f->next=NULL;
	f->pre=NULL;
	return f;
}
node insertsp(node f, int x,int pos)
{
	int i,j;
	node temp,t;
	temp=createnode(temp,x);
	i=lsize(f);
	if(pos==1)
	{
		f=insertb(f,x);
		return f;
	}
	else if(pos==i+1)
	{
		f=insertl(f,x);
		return f;
	}

	else if(pos>(i+1))
	{
		printf("insertion at this position not possible");

		return f;
	}
	else  if(pos<=i)
	{
		node t1;
		temp=createnode(temp,x);
		for(t=f,j=1;j<(pos-1);j++,t=t->next);

		temp->next=t->next;
		(t->next)->pre=temp;

		t->next=temp;
		temp->pre=t;
		return f;
	}
}
int lsize(node f)
{
	int i;
	node t;
	for(i=0,t=f;t!=NULL;t=t->next,i++);
	return i;
}
node deleteb(node f)
{
	node t;
	if(f==NULL)
	{
		printf("underflow");
		return f;
	}
	else
	{
		t=f;
		f=f->next;
		printf("deleted item=%d",t->info);
		free(t);
		if(f!=NULL)
		f->pre=NULL;
		return f;
	}
}
node deletel(node f)
{
	node t,t1;
	if(f==NULL)
	{
		printf("underflow");
		return f;
	}
	else if(f->next==NULL)
	{
		t=f;
		printf("deleted item=%d",t->info);
		free(t);
		f=NULL;
		return f;
	}
	else
	{
		for(t=f;t->next!=NULL;t=t->next);
		t1=t->pre;
		t1->next=NULL;
		t->pre=NULL;
		printf("deleted item=%d",t->info);
		free(t);
		return f;
	}
}
node deletesp(node f,int pos)
{
	node t,t1;
	int i,j;
	if(f==NULL)
	{
		printf("not posssible");
		return f;
	}
	i=lsize(f);
	if(pos==1)
	{
		f=deleteb(f);
		return f;
	}
	if(pos==i)
	{
	     f=deletel(f);
	     return f;
	}
	if(pos>i)
	{
		printf("not possible");
		return f;
	}
	if(pos>1 && pos <i)
	{
		for(t=f,j=1;j<(pos);j++,t=t->next);
		t1=t->pre;
		t1->next=t->next;
		(t->next)->pre=t1;
		printf("%d\n ",t->info);
		free(t);
		return f;
	}
}
node createlist(node f,int n)
{
  int i,y;
  node temp,t;
  for(i=1;i<=n;i++)
  {
    printf("enter info");
    scanf("%d",&y);
    temp=createnode(temp,y);
    if(f==NULL)
      f=temp;
    else
    {
     for(t=f;t->next!=NULL;t=t->next);
      t->next=temp;
      temp->pre=t;
    }
  }
    return(f);
}