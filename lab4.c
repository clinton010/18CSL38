// method 1 
#include<stdio.h>

void infix_to_postfix();
void push(char);
char pop();
int priority(char);
char infix[30], postfix[30], stack[30];
int top = -1;

void main() {
  printf("Enter the valid Infix expression \n");
  scanf("%s", infix);
  infix_to_postfix();
  printf("\n Infix expression : %s", infix);
  printf("\n Postfix expression : %s\n", postfix);
}

void push(char item) {
  stack[++top] = item;
} 

char pop() {
  return stack[top--];
} 

int priority(char symb) {
  int p;
  switch (symb) {
  case '+':
  case '-':
    p = 1;
    break;
  case '*':
  case '/':
  case '%':
    p = 2;
    break;
  case '^':
  case '$':
    p = 3;
    break;
  case '(':
  case ')':
    p = 0;
    break;
  case '#':
    p = -1;
    break;
  } 
  return p;
} 

void infix_to_postfix() 
{
    int i = 0, j = 0;
    char symb, temp;
    push('#');
    for (i = 0; infix[i] != '\0'; i++) {
      symb = infix[i];
      switch (symb) {
      case '(':
        push(symb); 
        break;
      case ')':
        temp = pop(); //pop symbol from top of stack
        while (temp != '(') 
        {
          postfix[j++] = temp;
          temp = pop();
        } 
        break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
      case '^':
      case '$':
        while (priority(stack[top]) >= priority(symb)) 
        {
          temp = pop();
          postfix[j++] = temp;
        }
        push(symb);
        break;
      default:
        postfix[j++] = symb;
      } 
    } 
    while (top > 0) 
    {
      temp = pop();
      postfix[j++] = temp;
    } 
    postfix[j] = '\0'; 
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
