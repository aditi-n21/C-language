#include<stdio.h>
#include<conio.h>
struct node
{
int info;
struct node *lt,*rt;
};
typedef struct node *bt;
bt b;
void insert(int);
void pre(bt);
void post(bt);
void in(bt);
void main()
{
int i,n;
char ch;
clrscr();
do
{
 printf("enter the information in tree");
 scanf("%d",&n);
 insert(n);
 printf("wish to enter more...y/n");
 ch=getch();
}
while(ch=='y');
printf("preorder traverse tree\n");
pre(b);
/*printf("postorder traverse tree\n");
post(b);*/
printf("inorder traverse tree\n");
in(b);
getch();
}
void insert(int num)
{
 bt t,p,q;
 q=(bt)malloc(sizeof(struct node));
 q->rt=NULL;
 q->lt=NULL;
 q->info=num;
 if(b==NULL)
  b=q;
 else
 {
   p=t=b;
   while(t!=NULL)
   {
    p=t;
    if(num<t->info)
     t=t->lt;
    else if(num>t->info)
    t=t->rt;
    }
   if(p->info>num)
    p->lt=q;
   else if(p->info<num)
   p->rt=q;
 }//else
}//insert



void pre(bt p)
{
 bt stk[20];
 int top=-1;
if(b==NULL)
 printf("cannot traverse");
else
{
 do
 {
  printf("\ninfo=%d",p->info);
  stk[++top]=p;
  p=p->lt;
 if(p==NULL)
   for(p=stk[top--];(((p=p->rt)==NULL)&&(top>-1));p=stk[top--]);
 }
 while(p!=NULL);
 }
}








void post(bt p)
{
 if(p!=NULL)
 {
   post(p->lt);
   post(p->rt);
   printf("info=%d\n",p->info);
 }
}













void in(bt p)
{
 bt stk[20];
 int top=-1;
 do
 {
   while(p!=NULL)
   {
    stk[++top]=p;
    p=p->lt;
   }
   if(top>-1)
   { p=stk[top--];
   printf("info=%d\n",p->info);
   p=p->rt;
   }
  }while((p!=NULL)||(top>-1));
 }

