#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct NODE
{
	int info;
	struct NODE *next;
};
typedef struct NODE *node;
node insertbsp(node,int,int);
node insertasp(node,int,int);
node insertl(node ,int);
node insertb(node ,int);
node insertsp(node ,int,int);
node createnode(node,int);
node createlist(node,int);
node deletel(node);
node deleteb(node );
node deletesp(node,int);
node deletebe(node,int);
node deleteaf(node,int);
node delinfo(node,int);
node insertmid(node,int);
int size(node);
void display(node);

void main()
{
	node start=NULL;
	int a,b,c,x,n,in,no,ch,c1,c2,c3,s;
	clrscr();
	do
	{
	   printf("1.insertion\n2.deletion\n3.display\n4.creation\n5.size\n");
	   printf("enter ur choice");
	   scanf("%d",&ch);
	   switch(ch)
	   {
	     case 1:
		do
		{
		  printf("1: insert begin\n 2:insert last\n 3:insert specified position\n4.insert mid\n5.insert before sp\n6.insert after sp\n");
		  printf("enter ur choice");
		  scanf("%d",&c1);
		  switch(c1)
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
		    case 4:printf("enter a no");
			   scanf("%d",&no);
			   start=insertmid(start,no);
			   break;
		     case 5:printf("enter element and pos");
			    scanf("%d%d",&x,&a);
			    start=insertbsp(start,x,a);
			    break;
		     case 6:printf("enter element and pos");
			    scanf("%d%d",&x,&a);
			    start=insertasp(start,x,a);
			    break;

		     default:
				printf("wrong choice");
		   }
		     printf("press 1 to continue insertion");
		     scanf("%d",&c2);
		  }while(c2!=0);
		  break;

	     case 2:
		  do
		  {
		    printf("1.delete from first\n2:delete at last\n3: delete specified position\n4.acc to info\n5.delete before sp\n6.delete after sp");
		    printf("enter ur choice");
		    scanf("%d",&c1);
		    switch(c1)
		    {
		      case 1:
			      start=deleteb(start) ;
			      break;
		      case 2:
			      start=deletel(start);
			      break;
		      case 3:
			       printf("enter a position");
			       scanf("%d",&a);
			       start=deletesp(start,a);
			       break;
		      case 4:printf("enter a info");
			       scanf("%d",&in);
			       start=delinfo(start,in);
			       break;
		      case 5:printf("enter a position");
			       scanf("%d",&a);
			       start=deletebe(start,a);
			       break;
		      case 6:printf("enter a position");
			     scanf("%d",&a);
			     start=deleteaf(start,a);
			     break;

		       default:
				printf("wrong choice");

		    }
		     printf("press 1 to continue deletion");
		     scanf("%d",&c3);
		   }while(c3!=0);
		    break;

	      case 3:
		     display(start);
		     break;
	       case 4:
		     printf("enter the no of nodes want to insert");
		     scanf("%d",&n);
		     start=createlist(start,n);
		     break;
	       case 5:
		     s=size(start);
		     printf("size=%d",s);
		     break;
	      default:
		      printf("wrong choice");

   }
  printf("if u want to continue press 1 else press 0");
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

		return f;
	}
}
node createnode(node f,int x)
{
	f=(node)malloc(sizeof(struct NODE));
	f->info=x;
	f->next=NULL;
	return f;
}
node insertsp(node f, int x,int pos)
{
	int i,j;
	node temp,t;
	i=size(f);
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
		t->next=temp;
		return (f);
	}
}
int size(node f)
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
		for(t=f;t->next!=NULL;t1=t,t=t->next);
		t1->next=NULL;
		printf("deleted item=%d",t->info);
		free(t);
		return f;
	}
}

node deletesp(node f,int pos)
{
  int i,j;
  node t,t1;
  if(f==NULL)
  {
    printf("not possible");
    return(f);
  }
  i=size(f);
  if(pos==1)
  {
    f=deleteb(f);
    return(f);
  }
  else if(pos==i)
  {
    f=deletel(f);
    return(f);
  }
  else if(pos>i)
  {
    printf("not possible");
    return(f);
  }
  else if(pos>1&&pos<i)
  {
    for(t=f,j=1;j<pos;t1=t,j++,t=t->next);

    t1->next=t->next;
    printf("%d",t->info);
    free(t);
    return(f);
  }
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

node delinfo(node f,int in)
{
  node t,t1;
  int i,j;
  if(f==NULL)
  {
   printf("not possible");
   return(f);
  }
  else
  {
    for(t=f;t!=NULL;t1=t,t=t->next)
    {
      if(t->info==in)
      {
	if(t==f)
	{
	  f=deleteb(f);
	}
	else
	{
	  t1->next=t->next;
	  free(t);
	  break;
	}
      }
    }
  }
    return(f);
}

node insertmid(node f, int x)
{
	int i,j,pos;
	node temp,t;
	i=size(f);
	pos=(i/2)+1;
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
	else  if(pos<=i)
	{
		node t1;
		temp=createnode(temp,x);
		for(t=f,j=1;j<(pos-1);j++,t=t->next);
		temp->next=t->next;
		t->next=temp;
		return (f);
	}
}

node insertbsp(node f,int x,int pos)
{
  f=insertsp(f,x,pos);
}
node insertasp(node f,int x,int pos)
{
	int i,j;
	node temp,t;
	i=size(f);
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
		for(t=f,j=1;j<pos;j++,t=t->next);
		temp->next=t->next;
		t->next=temp;
		return (f);
	}
}
node deletebe(node f,int pos)
{
  int i,j;
  node t,t1;
  if(f==NULL)
    printf("list is empty");
    i=size(f);
    f=deletesp(f,pos);
  return f;
}
node deleteaf(node f,int pos)
{
  int i,j;
  node t,t1;
  if(f==NULL)
  {
    printf("not possible");
    return(f);
  }
  i=size(f);
  if(pos==1)
  {
    f=deleteb(f);
    return(f);
  }
  else if(pos==i)
  {
    f=deletel(f);
    return(f);
  }
  else if(pos>i)
  {
    printf("not possible");
    return(f);
  }
  else if(pos>1&&pos<i)
  {
    for(t=f,j=1;j<(pos+1);t1=t,j++,t=t->next);

    t1->next=t->next;
    printf("%d",t->info);
    free(t);
    return(f);
  }
}