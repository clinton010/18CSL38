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
