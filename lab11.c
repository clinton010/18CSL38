#include<stdio.h>
int stack[10];
int top=-1;
int adj[10][10];
int vis[10]= {0};

void main()
{
int n,i,j,s,u,v,found = 0;
int row, col;
printf("\n How many nodes?: ");
scanf("%d", &n);
row = n;
col = n;

printf("\n Enter the adj matrix : \n");
for(i = 0; i < row; i++)
{
for(j = 0; j < col; j++)
{
scanf("%d", &adj[i][j]);

}
}

printf("\n Enter the source vertex:");
scanf("%d", &s);

stack[++top]= s;
vis[s] = 1;
printf("\n The source is: %d ", s);

while(top != -1)
{
found = 0;
u = stack[top];
for(v = 0; v <n && found == 0; v++)
{
if(adj[u][v] == 1 && vis[v]==0)
{
printf("%d  ", v);
stack[++top] = v;
vis[v] = 1;
found = 1;
}
}
if(found == 0)
{
top--;
}
}
}
