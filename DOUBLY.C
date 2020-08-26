#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct DNODE
{
  int info;
  struct DNODE *next;
  struct DNODE *prev;
};
typedef struct DNODE *dnode;
dnode insertb(dnode,int);
dnode inserte(dnode,int);
dnode insertsp(dnode,int,int);
dnode deleteb(dnode);
dnode deletee(dnode);
dnode deletesp(dnode,int);
dnode create(dnode,int);
void fdisplay();
void bdisplay();
int lsize(dnode);
void main()
{
  dnode start=NULL;
  int ch,c1,a,c,n,c2,c3,s;
  clrscr();
  do
  {





