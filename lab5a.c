// method 1
#include<stdio.h>
#include<ctype.h>
#include<math.h>

int top = -1,i;
float op1, op2, res, s[25];
char postfix[25], symbol;

float operation(char op, float op1, float op2) {
  switch (op) {
  case '+':
    return (op1 + op2);
  case '-':
    return (op1 - op2);
  case '*':
    return (op1 * op2);
  case '/':
    return (op1 / op2);
  case '^':
    return (pow(op1, op2));
  case '%':
    return ((int) op1 % (int) op2);
  default:
    return (0);
  }
}
void push(float symbol) {
  s[++top] = symbol;
}
float pop() {
  return (s[top--]);
}
void main() {
  printf("Enter the Postfix Expression\n");
  scanf("%s", postfix);
  for (i = 0; postfix[i] != '\0'; i++) {
    symbol = postfix[i];
    if (isdigit(symbol))
      push(symbol - '0');
    else {
      op2 = pop();
      op1 = pop();
      res = operation(symbol, op1, op2);
      push(res);
    }
  }
  res = pop();
  printf("Result=%.2f \n", res);
}
----------------------------------
//method 2 
#include<stdio.h>
#include<math.h>

void push(float);
float pop();
void evaluate(char[]);
float stack[20];
int top = -1;

void main() {
  int choice, n;
  char postfix[100];
  while (1) 
  {
    printf("\n STACK APPLICATIONS");
    printf("\n Enter your Choice: ");
    printf("\n 1. Evaluation of postfix expression with single digit operands and operators");
    printf("\n 2. Solving Tower of Hanoi problem with N disks");
    printf("\n 3. Exit \n");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      printf("Enter a valid postfix expression\n");
      scanf("%s", postfix);
      evaluate(postfix);
      break;
    case 2:
      printf("\n Enter the number of discs:\n");
      scanf("%d", & n);
      tower(n, 'A', 'C', 'B');
      printf("\n Total number of moves are %d", (int) pow(2, n) - 1);
      break;
    case 3:
      return;
    default:
      printf("\n Invalid Choice");
    } 
  } 
} 

void push(float item)
{
  stack[++top] = item;
} 


float pop() 
{
  return stack[top--];
} 


void evaluate(char postfix[100]) {
  int i;
  float op1, op2, res;
  char symb;
  for (i = 0; postfix[i] != '\0'; i++) 
  {
    symb = postfix[i];
    if (isdigit(symb)) 
      push(symb - '0'); 
    switch (symb) {
    case '+':
      op2 = pop();
      op1 = pop();
      res = op1 + op2;
      push(res);
      break;
    case '-':
      op2 = pop();
      op1 = pop();
      res = op1 - op2;
      push(res);
      break;
    case '*':
      op2 = pop();
      op1 = pop();
      res = op1 * op2;
      push(res);
      break;
    case '/':
      op2 = pop();
      op1 = pop();
      if (op2 == 0) {
        printf("Division by zero Error\n");
        return;
      }
      res = op1 / op2;
      push(res);
      break;
    case '%':
      op2 = pop();
      op1 = pop();
      if (op2 == 0) {
        printf("Division by zero Error\n");
        return;
      }
      res = (int) op1 % (int) op2; 
      push(res);
      break;
    case '^':
      op2 = pop();
      op1 = pop();
      res = pow(op1, op2);
      push(res);
      break;
    } 
  } 
  res = pop(); 
  if (top == -1) 
    printf("\n Result: %f\n ", res); 
  else { 
    printf("\nINVALID POSTFIX EXPRESSION\n");
    top = -1; 
  }
}
void tower(int n,int source,int destination,int aux)
{
     if(n==0)
        return;
     tower(n-1,source,aux,destination);
     printf("\n Move disc %d from %c to %c",n,source,destination);
     tower(n-1,aux,destination,source);
} 
----------------------------------------------------------------------------------------------
// method 2
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
    case '^': return pow(a,b);
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
    if(isalnum(post[i]))
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
