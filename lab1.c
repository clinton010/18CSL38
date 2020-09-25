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
