#include<stdio.h>
#include<string.h>

int HS=10;
struct emp
{
    int id;
    char name[10];
};

//create hash table
struct emp hash[20];

void init_H()
{
    int i;
    for(i=0;i<20;i++)
    {
        hash[i].id=0;
    }
}

int H(int k) //hash function to find hash value
{
    return k % HS;
}

void insert(int id, char name[])
{
    int i, index, h_val;
    //find hash value by using id
    h_val=H(id);
    
    for(i=0;i<HS;i++)
    {
        index=(h_val+i)%HS;
        if(hash[index].id==0) //if the hash index is free
        {
            hash[index].id=id;
            strcpy(hash[index].name,name);
            break;
        }
    }
    
    if(i==HS)
    {
        printf("\n Hash table is full");
    }
}

int search(int key)
{
    int i, index,h_val;
    //find hash value for the key
    h_val=H(key);
    for(i=0;i<HS;i++)
    {
        index=(h_val + i) % HS;
        if(hash[index].id == key) // if the index id == id given by the user
        {
            return 1;
        }
        if(hash[index].id == 0)   // if id == 0, empty row
        {
            return 0;
        }
    }
    if(i==HS)
    {
        return 0;
    }
}

void display()
{
    int i;
    printf("\n hash[index] -> ID NAME");
    for(i=0;i<HS;i++)
    {
        printf("\n hash[%d] -> %d  %s ", i, hash[i].id, hash[i].name);
    }
}
void main()
{
    int i,j,ele,found=0,key;
    int ch=0,id;
    char name[10];
    init_H();
    do
    {
        printf("\n 1.Insert 2.Search 3.Display 4.exit : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\n Enter the Employee id : ");
                   scanf("%d", &id);
                   printf("\n Name : ");
                   scanf("%s", &name);
                   // call insert function
                   insert(id, name);
                   break;
                   
            case 2 :printf("\n Enter the id to search : ");
                    scanf("%d", &key);
                    // call search function
                    found=search(key);
                    if(found==1)
                    {
                        printf("\n ID Found");
                    }
                    else
                    {
                        printf("\n ID Not Found");
                    }
                    break;
                    
            case 3 :display();
                    break;
        }
    }
    while(ch!=4);
}
