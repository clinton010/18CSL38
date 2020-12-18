#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};

struct node *root=NULL;

struct node *prepare_new_node()
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	printf("\n Node info : ");
	scanf("%d",&(new->info));
	new->llink=NULL;
	new->rlink=NULL;
	return new;
}


struct node *create(struct node *r)
{
	struct node *n,*pre,*cur;
	n=prepare_new_node();
    if(r==NULL)
	{
		r=n;
	}
	else
	{
		pre=NULL;
		cur=r;
		while(cur!=NULL)
		{
			pre=cur;
			if(n->info == cur->info)
			{
				printf("\n Duplicated infos are not allowed");
				free(n);
				return r;
			}
			if(n->info > cur->info)
			{
				cur=cur->rlink;
			}
			else
			{
				cur=cur->llink;
			}
		}
		if(pre->info > n->info)
		{
			pre->llink=n;
		}
		else
		{
			pre->rlink=n;
		}
	}
	return r;           
}

void pre_order(struct node *r)
{
	if(r==NULL)
	return;
	printf("%d->",r->info);
	pre_order(r->llink);
	pre_order(r->rlink);	
}

void post_order(struct node *r)
{
	 if(r==NULL)
    return;
    post_order(r->llink);
    post_order(r->rlink);
    printf("%d->",r->info);
}

void in_order(struct node *r)
{
	if(r==NULL)
	return;
	in_order(r->llink);
	printf("%d->",r->info);
	in_order(r->rlink);
}

void search(struct node *r)
{
	struct node *cur;
	int found=0,Key=0;
	printf("\n Key : ");
	scanf("%d", &Key);
	cur=r;
	while(cur!=NULL)
	{
		if(cur->info==Key)
		{
			found=1;
			break;
		}
		if(cur->info > Key)
		cur=cur->llink;
		else
		cur=cur->rlink;
	}
	if(found==1)
	{
		printf("\n The element found");
	}
	else
	{
		printf("\n Element not found");
	}
	
	
}
void main()
{
	int ch=0;
	do
	{
		printf("\n 1.Create BST \n 2.Pre_order \n 3.Post_order \n 4.In_order \n 5.Search \n 6.Exit \n");
		scanf("\n Choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : root=create(root);
			break;
			case 2 : pre_order(root);
			break;
			case 3 : post_order(root);
			break;
			case 4 : in_order(root);
			break;
			case 5 : search(root);
			break;
		}
	}while(ch!=6);
}
