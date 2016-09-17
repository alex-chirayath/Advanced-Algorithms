#include<stdio.h>

void schedule(int a[][20],int n)
{
	int day,i,j,value;
	if(n%2)
		value=n+1;
	else
		value=n;
	if(n%2)
		day=n;
	else
		day=n-1;	
	for(i=0;i<day;i++)
	{
		for(j=0;j<i;j++)
			a[i][j]=((day+i-j+1)+value)%value;
		for(j=i;j<n;j++)
			a[i][j]=(day+i-j+value)%value;
	}
	i=0;
	for(j=value-2;j>0;j--)
	{
		i=(i-2+day)%day;
		a[i][0]=a[i][j];
		a[i][j]=0;
	}
	if(value!=n)
		for(j=0;j<day;j++)
			a[j][j]=-1;
}

int main()
{
	int a[20][20]={0},n,i,j,day;
	printf("Enter no of players  ");
	scanf("%d",&n);
	schedule(a,n);
	if(n%2)
		day=n;
	else
		day=n-1;
	printf("\nPlayer->\n");
	printf( " ");
	for(j=0;j<n;j++)
		printf("%7d",j+1);
	printf("\n");
	printf("Day  \n");
	for(j=0;j<7*n;j++)
		printf("_");
	printf("\n");
	for(i=0;i<day;i++)
	{
		printf("%d",i+1);
		for(j=0;j<n;j++)
			printf("%7d",a[i][j]+1);
		printf("\n");
	}
	printf("\n");
	return 0;
}
/*
Output:
Enter no of players  8

Player->
       1      2      3      4      5      6      7      8
Day  
________________________________________________________
1      8      7      6      5      4      3      2      1
2      5      8      7      6      1      4      3      2
3      2      1      8      7      6      5      4      3
4      6      3      2      8      7      1      5      4
5      3      4      1      2      8      7      6      5
6      7      5      4      3      2      8      1      6
7      4      6      5      1      3      2      8      7

Output:
Enter no of players  7

Player->
       1      2      3      4      5      6      7
Day  
_________________________________________________
1      0      7      6      5      4      3      2
2      5      0      7      6      1      4      3
3      2      1      0      7      6      5      4
4      6      3      2      0      7      1      5
5      3      4      1      2      0      7      6
6      7      5      4      3      2      0      1
7      4      6      5      1      3      2      0

*/
