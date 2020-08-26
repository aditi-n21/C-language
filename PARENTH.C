#include<stdio.h>
#include<conio.h>
#include<string.h>
char stack[20];
int top=-1;
void push(char);
char pop();
void main()
{
  int l,i,p,pr=0,c=0,s=0;
  char ex[20];
  clrscr();
  printf("enter expression");
  gets(ex);
  l=strlen(ex);
  for(i=0;i<=l;i++)
  push(ex[i]);
  for(i=top;i>=0;i--)
  {
   p=pop(ex[i]);
   if(p=='[')
   s++;
   if(p==']')
   s--;
   if(p=='{')
   c++;
   if(p=='}')
   c--;
   if(p=='(')
   pr++;
   if(p==')')
   pr--;
  }
   if((s==0)&&(c==0)&&(pr==0))
   printf("expression has equal no of braces");
   else
   {
     if(s>0)
     printf("%d square brackets is extra in expression",s);
     if(s<0)
     printf("%d square brackets is less in expression",abs(s));
     if(c>0)
     printf("%d curley brackets is extra in expression",c);
     if(c<0)
     printf("%d curley brackets is less in expression",abs(c));
     if(pr>0)
     printf("%d parenthesis is extra in expression",pr);
     if(pr<0)
     printf("%d parenthesis is less in expression",abs(pr));
   }
   getch();
}

 void push(char c)
  {
    int i;
    if(top>=20)
    {
      printf("overflow");
    }
    else
    {
     top=top+1;
     stack[top]=c;
    }
 }
  char pop()
  {
    char i ;
    if(top<-1)
    {
      printf("underflow");
      return 0;
    }
    else
    {
      i=stack[top];
      top=top-1;
      return(i);
    }
  }
