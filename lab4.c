#include<stdio.h>
#include<math.h>
#include<ctype.h>

int stack[20];
int top=-1;

void push(int ele)
{
  top=top+1;
  stack[top]=ele;
}
int pop()
{
  int dele;
  dele=stack[top];
  top=top-1;
  return dele;
}
int eval(int a,int b, char op)
{
  switch(op)
  {
    case '+': return a+b;
    break;
    case '-': return a-b;
    break;
    case '*': return a*b;
    break;
    case '^': return pow(a,b);
    break;
    case '/': if(b==0)
    {
      printf("\n division error");
      return -1;
    }
    else
    {
      return a/b;
    }
    break;
  }
}
void main() 
{
  char post[20];
  int i=0;
  int op1,op2,res;
  printf("\n Enter the postfix expression:");
  scanf("%s",post);
  printf("\n The input expression is :%s", post);
  while(post[i]!='\0')
  {
    if(isalnum(post[i]-'0'))
    {
      push(post[i]-'0');
    }
    else{
      op2=pop();
      op1=pop();
      res=eval(op1,op2,post[i]);
      push(res);
    }
    i++;
  }
  printf("\n The result is :%d",stack[top]);
}
