#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
int stack[20];
int top=-1;
void push(char);
char pop();
void main()
{
  int i,l,x;
  char s[20],s1[20],c;
  clrscr();
  printf("enter any string=");
  gets(s);
  l=strlen(s);
  for(i=0;i<l;i++)
  push(s[i]);
  for(i=0;i<l;i++)
  {
    c=pop();
    s1[i]=c;
    printf("%c",s1[i]);
  }
    s1[i]='\0';
    x=strcmp(s1,s);
    if(x==0)
    printf("\n string is palindrome");
    else
    printf("\n not palindrome");
   getch();
}

  void push(char a)
  {
    if(top>=20)
    {
      printf("overflow");
    }
    else
    {
     top=top+1;
     stack[top]=a;
    }
 }
   char pop()
  {
    char a;
    if(top<-1)
    {
      printf("underflow");
      return 0;
    }
    else
    {
      a=stack[top];
      top=top-1;
      return(a);
    }
  }
