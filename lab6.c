#include <stdio.h>
char q[20];
int r=-1, f=0, count=0, MAX=5;
void insert()
{
  char ele;
  if(count==MAX)
  {
    printf("\n The queue is full");
  }
  else
  {
    printf("\n Element: ");
    scanf(" %c",&ele);
    r=(r+1)%MAX;
    q[r]=ele;
    count=count+1;
  }
}
void delete()
{
  int dele;
  if(count==0)
  {
    printf("\n Now the queue is empty, cannot delete element");
  }
  else
  {
    dele=q[f];
    f=(f+1)%MAX;
    printf("\n the deleted element is :%c",dele);
    count=count-1;
  }
}
void display()
{
  int i,j;
  if(count==0)
  {
    printf("\n No elements for display");
  }
  else
  {
    printf("\n the queue elements are :");
    for(i=1,j=f;i<=count;i++)
    {
      printf("\n queue[%d]=%c\n",j,q[j]);
      j=(j+1)%MAX;
    }
    printf("\n");
  } 
}
void main() 
{
  int ch=0;
  do
  {
    printf("1.insert \n2.delete \n3.display \n4.exit\n");
    printf("enter the choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
      case 1:insert();
      break;
      case 2:delete();
      break;
      case 3:display();
      break;
    }
  }while(ch!=4);
}
