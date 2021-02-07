//M1 DFS method
#include<stdio.h>

int a[10][10], s[10], n;
void read_AM(int a[10][10], int n) 
{
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) 
    {
      scanf("%d", & a[i][j]);
    }
  }
}
void dfs(int u)
{
  int v;
  s[u] = 1;
  printf("%d", u);
  for (v = 0; v < n; v++) {
    if (a[u][v] == 1 && s[v] == 0)
      dfs(v);
  }
  printf("\n");
}
void main() 
{
  int i, source;
  printf("Enter the number of nodes in the graph: ");
  scanf("%d", &n);
  printf("Enter the adjacency matrix: \n");
  read_AM(a, n);
  for (source = 0; source < n; source++) {
    for (i = 0; i < n; i++)
      s[i] = 0;
    printf("The nodes reachable from %d: ", source);
    dfs(source);
  }
}

--------------------------------------
//M2
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
