//  P1
/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node 
{
	int cf,px,py,pz;
	struct node *link;
};

struct node *start=NULL;

struct node *allocate()
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->link=NULL;
	return new;
}
struct node *prepare_new_node(int cf,int px,int py,int pz)
{
	struct node *new;
	new=allocate();
	new->cf=cf;
	new->px=px;
	new->pz=pz;
	new->py=py;
	return new;
}
struct node *rinsert(struct node *head,int cf,int px,int py,int pz)
{
	struct node *n,*ptr;
	n=prepare_new_node(cf,px,py,pz);
	if(head->link==head)  
	{
		head->link=n;
		n->link=head;
	}
	else
	{
		ptr=head->link;
		while(ptr->link!=head)
		{
			ptr=ptr->link;
		}
		ptr->link=n;
		n->link=head;
	}
	return head;
}
struct node *read_poly(struct node *head)
{
	int n,i,cf,px,py,pz;
	printf("\n Enter the number of terms :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the CF,PX,PY,PZ for the term %d : ",i+1);
		scanf("%d%d%d%d",&cf,&px,&py,&pz);
		head=rinsert(head,cf,px,py,pz);

	}
	return head;
}
struct node *display(struct node *head)
{
	struct node *ptr;
	ptr=head->link;
	if(head->link == head)
	{
		printf(" Empty ");
	}
	else
	{
		while(ptr!=head)
		{
			printf("\t %d x^%d y^%d z^%d",ptr->cf,ptr->px,ptr->py,ptr->pz);
			ptr=ptr->link;
		}
	}
	return head;
}
struct node *eval(struct node *head)
{
	int x,y,z,sum=0;
	struct node *ptr;
	printf("\n Enter the value for X,Y,Z:");
	scanf("%d%d%d",&x,&y,&z);
	ptr=head->link;
	while(ptr!=head)
	{
		sum=sum+(ptr->cf *pow(x,ptr->px)*pow(y,ptr->py)*pow(z,ptr->pz));
		ptr=ptr->link;
	}
	printf(":%d",sum);
	return head;
}
void main()
{
	struct node *head;
	head=allocate();
	start=head;
	head->link=head;

	head=read_poly(head);

	printf("\n The entered polynomial is :");
	head=display(head);

	head=eval(head);
	printf("\n The result is :");
}
*/

// P2


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node 
{
	int cf,px,py,pz;
	struct node *link;
};

struct node *start1=NULL;
struct node *start2=NULL;

struct node *allocate()
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->link=NULL;
	return new;
}
struct node *prepare_new_node(int cf,int px,int py,int pz)
{
	struct node *new;
	new=allocate();
	new->cf=cf;
	new->px=px;
	new->pz=pz;
	new->py=py;
	return new;
}
struct node *rinsert(struct node *head,int cf,int px,int py,int pz)
{
	struct node *n,*ptr;
	n=prepare_new_node(cf,px,py,pz);
	if(head->link==head)  // empty 
	{
		head->link=n;
		n->link=head;
	}
	else
	{
		ptr=head->link;
		while(ptr->link!=head)
		{
			ptr=ptr->link;
		}
		ptr->link=n;
		n->link=head;
	}
	return head;
}
struct node *read_poly(struct node *head)
{
	int n,i,cf,px,py,pz;
	printf("\n Enter the number of terms :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the CF,PX,PY,PZ for the term %d : ",i+1);
		scanf("%d%d%d%d",&cf,&px,&py,&pz);
		head=rinsert(head,cf,px,py,pz);

	}
	return head;
}
struct node *display(struct node *head)
{
	struct node *ptr;
	ptr=head->link;
	if(head->link == head)
	{
		printf(" Empty ");
	}
	else
	{
		while(ptr!=head)
		{
			printf("\t %d x^%d y^%d z^%d",ptr->cf,ptr->px,ptr->py,ptr->pz);
			ptr=ptr->link;
		}
	}
	return head;
}
struct node *poly_add(struct node *head1,struct node *head2)
{
	struct node *p1,*p2;
	int found=0;
	p1=head1->link;
	while(p1!=head1)
	{
		found=0;
		p2=head2->link;
		while(p2!=head2 && found ==0)
		{
			if(p1->px==p2->px && p1->py==p2->py && p1->pz==p2->pz)
			{
				p2->cf=p2->cf+p1->cf;
				found=1;
			}
			p2=p2->link;
		}
		if(found==0)
		{
			head2=rinsert(head2,p1->cf,p1->px,p1->py,p1->pz);
		}
		p1=p1->link;
	}
	return head2;
}
void main()
{
	struct node *head1,*head2;
	// polynomial 1
	head1=allocate();
	start1=head1;
	head1->link=head1;

	// polynomial 2
	head2=allocate();
	start2=head2;
	head2->link=head2;


	// read both polynomials 
	printf("\n 1 st polynomial");
	head1=read_poly(head1);

	printf("\n 2nd Poynomial");
	head2=read_poly(head2);
	
	printf("\n The entered polynomial1  is :");
	head1=display(head1);

	printf("\n The Entered polynomial 2 is :");
	head2=display(head2);

	head2=poly_add(head1,head2);

	printf("\n the result is :");
	head2=display(head2);

}
