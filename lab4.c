#include<stdio.h>
#include<ctype.h>
char stack[20];
int top=-1;
void push(char ch)
{
  top = top+1;
  stack[top] = ch;
}
int pop()
{
  int dele=0;
  if(top==-1)
  {
    return -1;
  }
  else 
  {
    dele=stack[top];
    top=top-1;
    return dele;
  }
}
int pre (char op)
{
  if(op=='(') return 0;
  if(op=='+' || op== '-') return 1;
  if(op=='*'|| op=='/' || op=='%') return 2;
  if(op== '^' || op=='$') return 3;
}
int main()
{
  char exp[20];
  int i=0,x=0;
  printf("\n Enter the infix expression:");
  scanf("%s",exp);
  while(exp[i]!='\0')
  {
		if(exp[i]=='(')
		{
			push(exp[i]);
		}
		else if(exp[i]==')')
		{
			while((x=pop())!='(')
			{
				printf("%c",x);
			}
		}
		else if(isalnum(exp[i]))
		{
			printf("%c",exp[i]);
		}
			else
			{
				while(pre(stack[top])>=pre(exp[i]))
				{
					printf("%c",pop());
				}
				push(exp[i]);
			}
			i++;
		}
		while(top!=-1)
		{
			printf("%c",pop());
		}
	}
