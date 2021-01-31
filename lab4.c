// method 1 (lab manual)
#include<stdio.h>
#include<string.h>
#include<conio.h>

int F(char symbol) {
  switch (symbol) {
  case '+':
  case '-':
    return 2;
  case '*':
  case '/':
    return 4;
  case '^':
  case '$':
    return 5;
  case '(':
    return 0;
  case '#':
    return -1;
  default:
    return 8;
  }
}
int G(char symbol) {
  switch (symbol) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 3;
  case '^':
  case '$':
    return 6;
  case '(':
    return 9;
  case ')':
    return 0;
  default:
    return 7;
  }
}
void infix_postfix(char infix[], char postfix[]) {
  int top, j, i;
  char s[30], symbol;
  top = -1;
  s[++top] = '#';
  j = 0;
  for (i = 0; i < strlen(infix); i++) {
    symbol = infix[i];
    while (F(s[top]) > G(symbol)) {
      postfix[j] = s[top--];
      j++;
    }
    if (F(s[top]) != G(symbol))
      s[++top] = symbol;
    else
      top--;
  }
  while (s[top] != '#') {
    postfix[j++] = s[top--];
  }
  postfix[j] = '\0';
}
void main() 
{
  char infix[20], postfix[20];
  printf("\nEnter a valid infix expression\n");
  gets(infix);
  infix_postfix(infix, postfix);
  printf("\nThe infix expression is:\n");
  printf("%s", infix);
  printf("\nThe postfix expression is:\n");
  printf("%s", postfix);
  getch();
}
--------------------------------------------------------------------------------------------------------------
// method 2
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
