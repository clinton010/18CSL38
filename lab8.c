// M1
#include<stdio.h>

struct node 
{
  char ssn[12], name[20], dept[25], desig[20];
  unsigned long long int phno;
  float sal;
  struct node * prev;
  struct node * next;
};
typedef struct node * NODE;

NODE temp, FIRST = NULL, END = NULL;

NODE getnode() 
{
  NODE x;
  x = (NODE) malloc(sizeof(struct node));
  x -> prev = NULL;
  x -> next = NULL;
  return x;
}

void read() 
{
  temp = getnode();
  printf("Enter SSN:");
  scanf("%s", temp -> ssn);
  printf("Enter Name:");
  scanf("%s", temp -> name);
  printf("Enter Dept:");
  scanf("%s", temp -> dept);
  printf("Enter Designation:");
  scanf("%s", temp -> desig);
  printf("Enter Phno:");
  scanf("%llu", & temp -> phno);
  printf("Enter Salary:");
  scanf("%f", & temp -> sal);
  return;
}

void Create_DLL()
{
  int n, i = 1;
  printf("Enter the number of Employees \n");
  scanf("%d", & n);
  while (i <= n) {
    printf("Enter the details of the %d employee\n", i++);
    read();
    if (FIRST == NULL) {
      FIRST = temp;
      END = temp;
    } else {
      END -> next = temp;
      temp -> prev = END;
      END = temp;
    }
  }
}

void display_count() 
{
  temp = FIRST;
  int count = 0;

  if (FIRST == NULL) // check for empty list
    printf("the Employee detail is NULL and count is %d\n", count);
  else {
    printf("Employee details:\n");
    printf("SSN \t EMPLOYEE NAME \t DEPARTMENT \t DESIGNATION \t PHONE NUMBER \t SALARY");
    while (temp != NULL) // display all nodes in the list
    {
      count++;
      printf("\n%s\t%s\t%s\t%s\t%llu\t%0.2f", temp -> ssn, temp -> name, temp -> dept, temp -> desig, temp -> phno, temp -> sal);
      temp = temp -> next;
    }
    printf("\n Employee count is %d\n", count);
  }
  return;
}

void Insertionfront() 
{
  printf("Enter the details of the employee\n");
  read();
  if (FIRST == NULL) {
    FIRST = temp;
    END = temp;
  } else {
    temp -> next = FIRST;
    FIRST -> prev = temp;
    FIRST = temp;
  }
}

void Insertionend() 
{
  printf("Enter the details of the new employee\n");
  read();
  if (FIRST == NULL) {
    FIRST = temp;
    END = temp;
  } else {
    END -> next = temp;
    temp -> prev = END;
    END = temp;
  }
  return;
}

void Deletionfront() 
{
  temp = FIRST;
  if (FIRST == NULL)
    printf("List is empty\n");
  else if (FIRST == END) {
    printf("deleted element is %s\n", temp -> ssn);
    FIRST = NULL;
    END = NULL;
    free(temp);
  } else {
    printf("deleted element is %s\n", temp -> ssn);
    FIRST = FIRST -> next;
    FIRST -> prev = NULL;
    free(temp);
  }
  return;
}

void Deletionend()  
{
  temp = END;
  if (FIRST == NULL)
    printf("List is empty\n");
  else if (FIRST == END) {
    printf("deleted element is %s\n", temp -> ssn);
    FIRST = NULL;
    END = NULL;
    free(temp);
  } else {
    printf("deleted element is %s\n", temp -> ssn);
    END = END -> prev;
    END -> next = NULL;
    free(temp);
  }
  return;
}

void main() 
{
  int choice;
  while (1) {
    printf(" \n 1 - Create DLL of N Employees \n 2 - Display DLL \n 3 - Insertion at front \n 4 - Insertion at end");
    printf("\n 5 - Deletion at front \n 6 - Deletion  at end \n 7 - Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d", & choice);
    switch (choice) 
    {
    case 1:
      Create_DLL();
      break;
    case 2:
      display_count();
      break;
    case 3:
      Insertionfront();
      break;
    case 4:
      Insertionend();
      break;
    case 5:
      Deletionfront();
      break;
    case 6:
      Deletionend();
      break;
    case 7:
      return;
    default:
      printf("Invalid Choice\n");
    }
  }
}

------------------------------------------------------------------------------------------------------------------------------------------------------
  
//M2
#include<stdio.h>
#include<stdlib.h>
int count=0;

struct node
{
    int ssn;
    char name[20];
    char dept[10];
    char desig[20];
    int sal;
    char ph[10];
    
    struct node *llink;
    struct node *rlink;
};

struct node *start=NULL;

struct node *prepare_new_node()
{
    struct node *new;
    int data;
    new=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter the details of employee");
    printf("\n SSN | NAME | DEPARTMENT | DESIGNATION | SALARY | PHONE NUMBER");
    scanf("%d%s%s%s%d%s",&(new->ssn),new->name,new->dept,new->desig,&(new->sal),new->ph);
    new->llink=NULL;
    new->rlink=NULL;
}

struct node *finsert()
{
    struct node *ptr,*n;
    n=prepare_new_node();
    if(start==NULL)
    {
        start=n;
    }
    else
    {
        ptr=start;
        n->rlink=start;
        start=n;
        ptr->llink=n;
        count++;
    }
    return start;
}

struct node *display()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\n The list is empty");
    }
    else
    {
       printf("\n The total number of employees : %d",count);
       ptr=start;
       printf("\n Start->");
       while(ptr!=NULL)
       {
           printf("<-");
           printf("||%d|%s|%s|%s|%d|%s||",ptr->ssn,ptr->name,ptr->dept,ptr->desig,ptr->sal,ptr->ph);
           ptr=ptr->rlink;
           printf("->");
       }
    }
    return start;
}

struct node *rinsert()
{
    struct node *n,*ptr;
     n=prepare_new_node();
     if(start==NULL)
     {
         start=n;
     }
     else
     {
         ptr=start;
         while(ptr->rlink!=NULL)
         {
             ptr=ptr->rlink;
         }
         ptr->rlink=n;
         n->llink=ptr;
         count++;
     }
     return start;
}

struct node *fdelete()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\n The list is empty");
    }
    else
    {
        ptr=start;
        start=ptr->rlink;
        free(ptr);
        count--;
    }
    return start;
}

struct node *rdelete()
{
  struct node *ptr;
    if(start==NULL)
    {
        printf("\n The list is empty");
    }
    else
    {
        ptr=start;
        while(ptr->rlink!=NULL)
        {
            ptr=ptr->rlink;
        }
        (ptr->llink)->rlink=NULL;
        free(ptr);
        count--;
    }
    return start;
}

struct node *create()
{
    int i,n;
    printf("\n How many node :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        start=finsert();
    }
    return start;
}
void main()
{
    int ch=0;
    do 
    {
        printf("\n 1.Creation of DLL \n 2.Insert at front end \n 3.Insert at rear end \n 4.Delete at front end \n 5.Delete at rear end \n 6.Display \n 7.Exit");
        printf("\n enter ur choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:start=create();
            break;
            case 2:start=finsert();
            break;
            case 3:start=rinsert();
            break;
            case 4:start=fdelete();
            break;
            case 5:start=rdelete();
            break;
            case 6:start=display();
            break;
        }
    }while(ch!=7);
}
