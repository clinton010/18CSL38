// method 1
#include<stdio.h>
#define MAX 5
int stack[MAX];
int top=-1;

void push()
{
     int item;
     if(top==(MAX-1))
            printf("\n Stack Overflow");
     else
        {
          printf("\n Enter the element to be pushed :");
          scanf("%d",&item);
          stack[++top]=item;
        }
     
}

void pop()
{
     if(top==-1)
          printf("\n Stack Underflow");
     else
        printf(" \nPoped element is %d ",stack[top--]);  
}

void display()
{
     int i;
     if(top==-1)
          printf("\n Sorry Empty Stack");
      else
        {
           printf("\nThe elements of the stack are\n");
           for(i=top;i>=0;i--)
                printf("stack[%d] = %d\n",i, stack[i]);
        }
 } 
 
void palindrome()
{
    int i,count=0;
    for(i=0; i<=(top/2); i++)
    {
        if(stack[i] == stack[top-i])
            count++;
    }
    if((top/2+1)==count)
        printf("\n Stack contents are Palindrome");
    else
        printf("\nStack contents are not palindrome");
}


void main()
{
    int choice;
    while(1)
     {
      printf("\n STACK OPERATIONS\n");
      printf(" 1.Push\n 2.Pop\n 3.Display\n 4.Palindrome\n 5.Exit\n");
      printf("Enter your choice\n");
      scanf("%d",&choice);
      switch(choice)
       {
        case 1:push();
               break;
        case 2:pop();
               break;
        case 3:display();
               break;
        case 4:palindrome();
               break;
        case 5:return;
        default: printf("Invalid choice\n");
        }
      }
}
-------------------------------------------------------------------------------------------------------------------
// method 2
#include<stdio.h>
int stack[10],i,j,ch,max=5,top=-1;
void push(int ele)
{
  top=top+1;
  stack[top]=ele;
}
void display()
{
  printf("\n The stack elements are:");
  for(i=0;i<=top;i++)
  {
    printf("\n stack[%d]->%d",i,stack[i]);
  }
}
int pop()
{
  int d;
  d=stack[top];
  top=top-1;
  return d;
}
void pal()
{
  int a[10],n,eq=0,top=-1;
  printf("\n Enter the value for n:");
  scanf("%d",&n);
  printf("\n Enter the array elements one by one:");
  for(i=0;i<n;i++)
  {
    scanf("%d", &a[i]);
  }
  for(i=0;i<n;i++)
  {
    push(a[i]);
  }
  for(i=0;i<n;i++)
  {
    if(a[i]!=pop())
    {
      eq=-1;
    }
  }
  if(eq==-1)
  {
    printf("\n array is not a Palindrome");
  }
  else 
  {
    printf("\n array is a Palindrome");
  }
}
void main()
{
  int ele,dele;
  do{
    printf("\n Enter your choice :");
    printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Palindrome \n 5.Exit");
    printf("\n Choice:");
    scanf("%d", &ch);
    switch(ch)
    {
      case 1: if(top==max-1)
      {
        printf("\n overflow");
      }
      else 
      {
        printf("\n Enter the element to insert:");
        scanf("%d", &ele);
        push(ele);
      }
      break;
        case 2: if (top==-1)
        {
          printf("\n underflow");
        }
        else
        {
        dele=pop();
        printf("\n the deleted element is %d", dele);
        }
        break;
        case 3: display();
        break;
        case 4: pal();
        break;
      }
    } while (ch!=5);
  }
