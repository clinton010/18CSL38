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
