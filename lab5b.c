// method 1
#include<stdio.h>
#include<math.h>

void tower(int n, int source, int temp, int destination) 
{
  if (n == 0)
    return;
  tower(n - 1, source, destination, temp);
  printf("\nMove disc %d from %c to %c", n, source, destination);
  tower(n - 1, temp, source, destination);
}
void main() 
{
  int n;
  printf("\nEnter the number of discs: \n");
  scanf("%d", & n);
  tower(n, 'A', 'B', 'C');
  return 0;
}

-------------------------------------------------------------------------------------------------------------------
// method 2	
#include <stdio.h> 

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
	if (n == 1) 
	{ 
		printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
		return; 
	} 
	towerOfHanoi(n-1, from_rod, aux_rod, to_rod); 
	printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
	towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
} 
int main() 
{ 
	int n = 0;// Number of disks
	printf("\n Enter the number of Disks :");
	scanf("%d",&n); 
	towerOfHanoi(n, 'A', 'C', 'B');
	return 0; 
}
