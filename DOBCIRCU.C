#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct NODE
{
	int info;
	struct NODE *next;
	struct NODE *pre;
};
typedef struct NODE *cdnode;
cdnode insertl(cdnode ,int);
cdnode insertb(cdnode ,int);
cdnode insertsp(cdnode ,int,int);
cdnode createnode(cdnode,int);
cdnode deletel(cdnode);
cdnode deleteb(cdnode );
cdnode deletesp(cdnode,int);
int lsize(cdnode);
void displayf(cdnode);
void displayb(cdnode);
void main()
{

	cdnode start=NULL;
	int a,b,c,x,e,n ;
	clrscr();
	do
	{
		printf("enter the choice \n 1: insert from begin\n 2:insert to last\n 3:insert at specified position\n 4:delete from first\n 5:delete at last\n 6: delete from specified position\n 7:display\n 8:display backward\n  9:size\n");
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
		  case 3: printf("enter a no");
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
			 printf("enter a position");
			 scanf("%d",&e);
			 start=deletesp(start,e);
			 break;
		  case 7:
			 displayf(start);
			 break;
		  case 8: displayb(start);
			  break;
		  case 9:printf("length is =%d",lsize(start));
			 break;

		  default:printf("wrong choice");


  }
  printf("if u want to continue press 1 ");
  scanf("%d",&b);

}while(b==1);

  getch();
}
void displayb(cdnode f)
{
	cdnode t,l;
	int i;
	if(f==NULL)
		printf("underflow");
	else
	{
		l=f->pre;
		t=l;
		do
		{
			printf("%d\n",t->info);
			t=t->pre;
		}while(t!=l);
	}
}
void displayf(cdnode f)
{
	cdnode t;
	int i;
	if(f==NULL)
		printf("underflow");
	else
	{
		t=f;
		do
		{
			printf("%d\n",t->info);
			t=t->next;
		}while(t!=f);
	}
}

cdnode insertb(cdnode f, int x)
{
	cdnode temp,t;
	temp=createnode(temp,x);
	if(f==NULL)
	{
		f=temp;
		temp->next=f;
		temp->pre=f;
		return f;
	}
	else
	{       (f->pre)->next=temp;
		temp->pre=f->pre;
		f->pre=temp;
		temp->next=f;
		f=temp;
		return (f);
	}
}
cdnode insertl(cdnode f, int x)
{
	int i;
	cdnode temp,t,l;
	temp=createnode(temp,x);

	if(f==NULL)
	{
		f=temp;
		temp->next=f;
		temp->pre=f;
		return f;
	}
	else
	{
		l=f->pre;
		l->next=temp;
		temp->pre=l;
		temp->next=f;
		f->pre=temp;
	       return f;
	}
}
cdnode createnode(cdnode f,int x)
{
	f=(cdnode)malloc(sizeof(struct NODE));
	f->info=x;
	f->pre=NULL;
	f->next=NULL;
	return f;
}
cdnode insertsp(cdnode f, int x,int pos)
{
	int i,j;
	cdnode temp,t;
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
		cdnode t1;
		temp=createnode(temp,x);
		for(t=f,j=1;j<(pos-1);j++,t=t->next);
		temp->next=t->next;
		(t->next)->pre=temp;
		t->next=temp;
		temp->pre=t;
		return f;
	}
}

int lsize(cdnode f)
{
	int i;
	cdnode t;
	for(i=0,t=f;t->next!=f;t=t->next,i++);
	return i+1;
}
cdnode deleteb(cdnode f)
{
	cdnode t,t1,l;
	if(f==NULL)
	{
		printf("underflow");
		return f;
	}
	else if(f->next==f)
	{
		t=f;
		printf("deleted item=%d",t->info);
		f=NULL;
		free(t);
		return f;
	}
	else
	{
		l=f->pre;
		t=f;
		f=f->next;
		l->next=f;
		f->pre=l;
		printf("deleted item=%d",t->info);
		free(t);
		return f;
	}
}
cdnode deletel(cdnode f)
{
	cdnode t,t1,l;
	if(f==NULL)
	{
		printf("underflow");
		return f;
	}
	else if(f->next==f)
	{
		t=f;
		f=NULL;
		printf("deleted item=%d",t->info);
		free(t);
		return f;
	}
	else
	{
		l=f->pre;
		t1=l->pre;
		t1->next=f;
		f->pre=t1;
		printf("deleted item=%d",l->info);
		free(l);
		return f;
	}
}

cdnode deletesp(cdnode f,int pos)
{
	cdnode t,t1;
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

