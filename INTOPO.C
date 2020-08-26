#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
int prd(char c);
char st[10];
int top=-1;
void main()
{
  char in[10],pt[10],ch;
  int i,j=0,k;
  clrscr();
  printf("enter any infix expression");
  fflush(stdin);
  gets(in);
  for(i=0;in[i]!='\0';i++)
  {
    ch=in[i];
    if(isalpha(ch))
	pt[j++]=ch;
    else if(ch=='(')
	st[++top]=ch;
    else if(ch==')')
      {
       while(st[top]!='(')
       pt[j++]=st[top--];
       top--;
      }
    else
      {
	for(k=top;(k>=0&&st[k]!='(');k--)
		if(prd(st[k])>=prd(ch))
			pt[j++]=st[top--];
	st[++top]=ch;
      }
    }
    while(top>=0)
      pt[j++]=st[top--];
    pt[j]='\0';
    printf("postfix exp  is=");
    fflush(stdin);
    printf("%s",pt);
    getch();
}



  int prd(char c)
  {
    if(c=='^')
    return (9);
    if(c=='%'||c=='*'||c=='/')
    return (8);
    if(c=='+'||c=='-')
    return (5);

  }

