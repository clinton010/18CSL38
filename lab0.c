#include <stdio.h>
int a[15];
int n,i,pos,elem,ch;
void create_a()
{
  printf("\n enter the number of elements :");
  scanf("%d", &n);
  printf("\n enter the elements one by  one: ");
  for (i=0;i<n;i++)
  {
    scanf("%d", &a[i]);
  } 
}
void display_a()
{
  printf("\n Entered array elements are: ");
  for(i=0;i<n;i++)
  {
    printf("\n a[%d]-> %d", i, a[i]);
  }
}
void insert_a()
{
  printf("\nEnter the new element: ");
  scanf("%d", &elem);
  printf("\n Enter the position: ");
  scanf("%d", &pos);
  if(pos>n || pos<0)
  {
    printf("\n Invalid postion");
  }
  else {
    for(i=n-1;i>=pos;i--)
    {
      a[i+1]=a[i];
    }
    a[pos]=elem;
    n=n+1;
  }
}
void delete_a()
{
  printf("\n Enter the postion : ");
  scanf("%d", &pos);
  if(pos>=n || pos<0)
  {
    printf("\n Invalid postion");
  }
  else
  {
    printf("\nDeleted element is: %d", a[pos]);
    for(i=pos+1;i<n;i++)
    {
      a[i-1]=a[i];
    }
    n=n-1;
  }
}
void main() 
{
  do {
  printf("\n Enter your choice : ");
  printf("\n 1. Create an array \n 2. Display an array \n 3. Insert \n 4. Delete \n 5. exit \n");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1: create_a();
    break;
    case 2: display_a();
    break;
    case 3: insert_a();
    break;
    case 4: delete_a();
    break;
  }
  }while(ch!=5);
}
