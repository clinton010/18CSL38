#include<stdio.h>
int slen(char s[])
{
	int c=0,i=0;
	while(s[i]!='\0')
	{
		c=c+1;
		i++;
	}
	return c;
}
int cmpi(char s1[],char s2[],int i)
{
	int k=0,j=0;
	int n1,n2;
	n1=slen(s1); 
	n2=slen(s2);
	while(k<n2)
	{
		if (s1[k+i]==s2[k])
		{
			j++;
		}
		k++;
	}
	if(j==n2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
void my_s_r(char STR[],char PAT[],char REP[],char DEST[])
{
	int i,j,k;
	int lms,lps,lrs;
	int flag=0;
	i=k=j=0;
	lms=slen(STR); 
	lps=slen(PAT); 
	lrs=slen(REP); 
	while(i<lms-lps+1)
	{
		flag=cmpi(STR,PAT,i);
		if (flag==1)
		{
			while(j<i)
			{
				DEST[k]=STR[j];  
				k++;j++;
			}
			j=0; 
while(j<lrs)
			{
				DEST[k]=REP[j];
				k++;
				j++;
			}
			i=i+lps;
			j=i;
		}
		else
		{
			i++;
		}
	}
	while(j<lms)
	{
		DEST[k]=STR[j];
		k++;j++;
	}
	DEST[k]='\0';
}
void main()
{
	char STR[15];  
	char PAT[15];  
	char REP[15]; 
	char DEST[30]; 
	int loc=0;
	printf("\n enter the main string:");
	scanf("%s",STR); 
	printf("\n enter the pattern string:");
	scanf("%s",PAT);
	printf("\n enter the replacement string:");
	scanf("%s",REP);
	my_s_r(STR,PAT,REP,DEST);
	printf("\n the output is :%s \n",DEST);
}
