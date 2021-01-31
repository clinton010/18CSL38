//M1
#include<stdio.h>
#include<stdlib.h>

struct node 
{
  char usn[20], name[10], branch[5];
  unsigned long long int phno;
  int sem;
  struct node * link; 
};

typedef struct node * NODE;
NODE temp, FIRST = NULL;

NODE getnode() {
  NODE x;
  x = (NODE) malloc(sizeof(struct node)); 
  x -> link = NULL; 
  return x;
}

void read()
{
  temp = getnode();
  printf("Enter USN: ");
  scanf("%s", temp -> usn);
  printf("Enter NAME: ");
  scanf("%s", temp -> name);
  printf("Enter Branch: ");
  scanf("%s", temp -> branch);
  printf("Enter phone Number: ");
  scanf("%llu", & temp -> phno);
  printf("Enter Semester: ");
  scanf("%d", & temp -> sem);
}

void create_SSL() {
  int n, i;
  printf("Enter the number of students: ");
  scanf("%d", & n);
  for (i = 1; i <= n; i++) 
  {
    printf("\n Enter the details of %d students\n", i);
    read(); 
    if (FIRST == NULL) 
      FIRST = temp; 
    else {
      temp -> link = FIRST; 
      FIRST = temp; 
    }
  }
}

void display_count() 
{
  int count = 1;
  temp = FIRST;
  printf("Student details:\n");
  if (FIRST == NULL) 
    printf("Student detail is NULL and count is 0\n");
  else {
    printf("\nUSN\tNAME\tBRANCH\tPHNO\tSEMESTER\n");
    while (temp -> link != NULL) 
    {
      count++;
      printf("%s\t%s\t%s\t%llu\t%d\n", temp -> usn, temp -> name, temp -> branch, temp -> phno, temp -> sem);
      temp = temp -> link; 
    }
    printf("%s\t%s\t%s\t%llu\t%d", temp -> usn, temp -> name, temp -> branch, temp -> phno, temp -> sem);
    printf("\n Student count is %d\n", count);
  }
  return;
}

void insert_front() 
{
  printf("Enter the details of student\n");
  read();
  if (FIRST == NULL)
    FIRST = temp;
  else {
    temp -> link = FIRST;
    FIRST = temp;
  }
}

NODE insert_end() 
{
  NODE last = FIRST;
  printf("Enter the details of student\n");
  read();
  if (FIRST == NULL)
    FIRST = temp;
  else {
    while (last -> link != NULL) 
      last = last -> link;
    last -> link = temp; 
  }
  return FIRST;
}

void delete_front() 
{
  temp = FIRST;
  if (FIRST == NULL) 
    printf("List is empty\n");
  else {
    printf("deleted element is %s\n", temp -> usn);
    FIRST = FIRST -> link; 
    free(temp); 
  }
  return;
}

void delete_end() {
  NODE last = NULL;
  temp = FIRST;
  if (FIRST == NULL) 
    printf("List is empty\n");
  else if (FIRST -> link == NULL) 
  {
    printf("Deleted element is %s\n", temp -> usn);
    free(FIRST);
    FIRST = NULL;
  } else {
    while (temp -> link != NULL) {
      last = temp;
      temp = temp -> link;
    }
    last -> link = NULL;
    printf("Deleted element is %s\n", temp -> usn);
    free(temp); 
  }
  return;
}

void main() 
{
  int choice;
  while (1) {
    printf("\n1. Create SSL\n2.Display SSL\n3.Insert front\n4.Insert end\n5.Delete front\n6.Delete end\n7.EXIT\n");
    printf("Enter your choice\n");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      create_SSL();
      break;
    case 2:
      display_count();
      break;
    case 3:
      insert_front();
      break;
    case 4:
      insert_end();
      break;
    case 5:
      delete_front();
      break;
    case 6:
      delete_end();
      break;
    case 7:
      return;
    default:
      printf("\nInvalid choice\n");
    }
  }
}
--------------------------------------------------------------------------------------------------------------------------------
//M2
#include<stdio.h>
#include<stdlib.h>

int count=0;

struct node
{
  char usn[10];
  char name[10];
  char pgm[4];
  int sem;
  char phone[10]; 
  
  struct node *link;  
};

struct node *start=NULL;

struct node *create_new_node()
{
    char usn[10],name[20],pgm[4],pho[10];
    int sem;
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter the details of the student :(usn|name|pgm|sem|pho)");
    scanf("%s%s%s%d%s",new->usn,new->name,new->pgm,&(new->sem),new->phone);
    
    return new;
    
}
struct node *finsert()
{
    struct node *n;
    n=create_new_node(); 
    if(start==NULL)
    {
      start=n;  
    }
    else
    {
        n->link=start;
        start=n;
    }
    count++;
    return start;
}

struct node *create()
{
    int n;
    int i=0;
    printf("\n How many node you want?:");
    scanf("\n %d",&n);
    for(i=0;i<n;i++);
    {
        start=finsert();
    }
    return start;
}

struct node *display()
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
    {
        printf("\n we have empty list");
    }
    else
    {
        printf("\n my linked list is : ");
        printf("\n\tUSN\t|\tNAME\t|\tPGM\t|\tSEM\t|\tPHO\t");
        while(ptr!=NULL)
        {
            printf("\n\t%s\t|\t%s\t|\t%s\t|\t%d\t|\t%s\t",ptr->usn,ptr->name,ptr->pgm,ptr->sem,ptr->phone);
       ptr=ptr->link;
        }
        printf("\n The total number of nodes i have is : %d",count);
    }
    return start;
}

struct node *einsert()
{
    struct node *ptr;
    struct node *n;
    n=create_new_node();
    ptr=start;
    if(start==NULL)
    {
        start=n;
    }
    else
    {
    while(ptr->link!=NULL)
         {
            ptr=ptr->link;   
         }
         ptr->link=n;
    }
    count++;
    return start;
}

struct node *fdelete()
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
    {
        printf("\n queue is empty");
    }
    else
    {
        start=ptr->link;
        free(ptr);
        count--;
    }
    if(count==0)
    {
        start=NULL;
    }
    return start;
}

struct node *edelete()
{
    struct node *ptr,*pp;
    ptr=start;
    if(start==NULL)
    {
        printf("\n The linked list is empty ");
    }
    else if(ptr->link==NULL)
    {
        start=NULL;
        free(ptr);
    }
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
        {
           pp=ptr;
           ptr=ptr->link;
        }
        free(ptr);
        pp->link=NULL;
        count--;
    }
    if(count==0)
    {
        start=NULL;
    }
    return start;
}
void main()
{
    int ch=0;
    do{
        printf("\n 1.create linked list\n 2.insert at front\n 3.insert at end\n 4.delete at front\n 5.delete at end\n 6.display\n 7.exit");
        printf("\n enter ur choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
          case 1: start=create();
          break;
          case 2: start=finsert();
          break;
          case 3: start=einsert();
          break;
          case 4: start=fdelete();
          break;
          case 5: start=edelete();
          break;
          case 6: start=display();
          break;
        }
    }while(ch!=7);
}
