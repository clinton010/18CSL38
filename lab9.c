//M1

//P1
#include<stdio.h>
#include<conio.h>
#include<math.h>

struct node 
{
  int cf;
  int px, py, pz;
  struct node * link;
};
typedef struct node * NODE;
NODE getnode() {
  NODE x;
  x = (NODE) malloc(sizeof(struct node));
  if (x == NULL) {
    printf("Out of memory");
    exit(0);
  }
  return x;
}
NODE insert_rear(int cf, int px, int py, int pz, NODE head) 
{
  NODE temp, cur;
  temp = getnode();
  temp -> cf = cf;
  temp -> px = px;
  temp -> py = py;
  temp -> pz = pz;
  cur = head -> link;
  while (cur -> link != head) {
    cur = cur -> link;
  }
  cur -> link = temp;
  temp -> link = head;
  return head;
}
NODE read_poly(NODE head) 
{
  int i, n;
  int cf, px, py, pz;
  printf("Enter the no. of terms in the polynomial: ");
  scanf("%d", & n);
  for (i = 1; i <= n; i++) {
    printf("Enter term:%d\n", i);
    printf("Cf Px, py, pz= ");
    scanf("%d %d %d %d", & cf, & px, & py, & pz);
    head = insert_rear(cf, px, py, pz, head);
  }
  return head;
}
void display(NODE head) 
{
  NODE temp;
  if (head -> link == head)
  {
    printf("polynomial does not exist");
    return;
  }
  temp = head -> link;
  while (temp != head) 
  {
    if (temp -> cf < 0)
      printf("%d", temp -> cf);
    else
      printf("+%d", temp -> cf);
    if (temp -> px != 0)
      printf("x^%d", temp -> px);
    if (temp -> py != 0)
      printf("y^%d", temp -> py);
    if (temp -> pz != 0)
      printf("z^%d", temp -> pz);
    temp = temp -> link;
  }
  printf("\n");
}
float evaluate(NODE head) 
{
  int x, y, z;
  float sum = 0;
  NODE p;
  printf("Enter the value of x,y,z: ");
  scanf("%d %d %d", & x, & y, & z);
  p = head -> link;
  while (p != head) {
    sum += p -> cf * pow(x, p -> px) * pow(y, p -> py) * pow(z, p -> pz);
    p = p -> link;
  }
  return sum;
}
void main() 
{
  NODE head;
  float res;
  head = getnode();
  head -> link = head;
  printf("Enter the polynomial\n");
  head = read_poly(head);
  res = evaluate(head);
  printf("The given polynomial is\n");
  display(head);
  printf("The result=%f\n", res);
}

//P2
#include<stdio.h>
#include<conio.h>
#include<math.h>

struct node 
{
  int cf;
  int px, py, pz;
  struct node * link;
};
typedef struct node * NODE;
NODE getnode() 
{
  NODE x;
  x = (NODE) malloc(sizeof(struct node));
  if (x == NULL) {
    printf("Out of memory");
    exit(0);
  }
  return x;
}
NODE insert_rear(int cf, int px, int py, int pz, NODE head) 
{
  NODE temp, cur;
  temp = getnode();
  temp -> cf = cf;
  temp -> px = px;
  temp -> py = py;
  temp -> pz = pz;
  cur = head -> link;
  while (cur -> link != head) 
  {
    cur = cur -> link;
  }
  cur -> link = temp;
  temp -> link = head;
  return head;
}
NODE read_poly(NODE head) 
{
  int i, n;
  int cf, px, py, pz;
  printf("Enter the no. of terms in the polynomial: ");
  scanf("%d", & n);
  for (i = 1; i <= n; i++) {
    printf("Enter term:%d\n", i);
    printf("Cf Px, py, pz= ");
    scanf("%d %d %d %d", & cf, & px, & py, & pz);
    head = insert_rear(cf, px, py, pz, head);
  }
  return head;
}
void display(NODE head) 
{
  NODE temp;
  if (head -> link == head) 
  {
    printf("polynomial does not exist");
    return;
  }
  temp = head -> link;
  while (temp != head) 
  {
    if (temp -> cf < 0)
      printf("%d", temp -> cf);
    else
      printf("+%d", temp -> cf);
    if (temp -> px != 0)
      printf("x^%d", temp -> px);
    if (temp -> py != 0)
      printf("y^%d", temp -> py);
    if (temp -> pz != 0)
      printf("z^%d", temp -> pz);
    temp = temp -> link;
  }
  printf("\n");
}
NODE search(NODE p1, NODE h2) 
{
  NODE p2;
  int cf1, px1, py1, pz1, cf2, px2, py2, pz2;
  px1 = p1 -> px;
  py1 = p1 -> py;
  pz1 = p1 -> pz;
  p2 = h2 -> link;
  while (p2 != h2) {
    px2 = p2 -> px;
    py2 = p2 -> py;
    pz2 = p2 -> pz;
    if (px1 == px2 && py1 == py2 && pz1 == pz2) break;
    p2 = p2 -> link; 
  }
  return p2;
}
NODE copy_poly(NODE h2, NODE h3) 
{
  NODE p2;
  int cf2, px2, py2, pz2;
  p2 = h2 -> link;
  while (p2 != h2) 
  {
    if (p2 -> cf != -999) 
    {
      cf2 = p2 -> cf;
      px2 = p2 -> px;
      py2 = p2 -> py;
      pz2 = p2 -> pz;
      h3 = insert_rear(cf2, px2, py2, pz2, h3);
    }
    p2 = p2 -> link; 
  }
  return h3;
}
NODE add_poly(NODE h1, NODE h2, NODE h3) 
{
  NODE p1, p2;
  int cf1, px1, py1, pz1, sum;
  p1 = h1 -> link;
  while (p1 != h1) {
    cf1 = p1 -> cf;
    px1 = p1 -> px;
    py1 = p1 -> py;
    pz1 = p1 -> pz;
    p2 = search(p1, h2);
    if (p2 != h2) 
    {
      sum = cf1 + p2 -> cf; 
      h3 = insert_rear(sum, px1, py1, pz1, h3);
      p2 -> cf = -999; 
    } else 
      h3 = insert_rear(cf1, px1, py1, pz1, h3);
    p1 = p1 -> link; 
  }
  h3 = copy_poly(h2, h3); 
  return h3; 
}
void main() {
  NODE h1, h2, h3;
  h1 = getnode();
  h2 = getnode();
  h3 = getnode();
  h1 -> link = h1;
  h2 -> link = h2;
  h3 -> link = h3;
  printf("Enter the first polynomial: \n");
  h1 = read_poly(h1);
  printf("Enter the second polynomial: \n");
  h2 = read_poly(h2);
  printf("Poly 1:");
  display(h1);
  printf("Poly2:");
  display(h2);
  printf("----------------------------------------------------------------\n");
  h3 = add_poly(h1, h2, h3);
  printf("Poly 3:");
  display(h3);
  printf("----------------------------------------------------------------\n");
  getch();
}
------------------------------------------------------------------------------------------------------------------------------------------------------------
//M2
	
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
