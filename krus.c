#include<stdio.h>

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void sort(int a[20][20],int n)
{
	int pass,t,j;
	for(pass=0;pass<=n-1;pass++)
	{
		for(j=1;j<=n-pass;j++)
		{
			if(a[j][2]>a[j+1][2])
			{
				swap(&a[j+1][0],&a[j][0]);
				swap(&a[j+1][1],&a[j][1]);
				swap(&a[j+1][2],&a[j][2]);	
			}
		}
	}
}


void krusk(int edges[20][20],int set[15],int v,int e)
{
 	int k,a,b,mincost,i,j,selected[50];
	for(i=1;i<=v;i++)
	set[i]=i;
	k=0; mincost=0;
	printf("\n");
	for(i=1;i<=e;i++)
  	{
		a=edges[i][0];
		b=edges[i][1];
		printf("\nConsidering edge %d %d ",a,b);
    		if(set[a]!=set[b])
    		{
       			selected[i]=1;
       			printf("\n%d is selected",i);
       			for(j=1;j<=e;j++)
         		if(set[j]==set[b] && j!=b)
          		   set[j]=set[a];
                      	set[b]=set[a];
			mincost+=edges[i][2];
    			k++;
  		}
 	}
  	if(k!=v-1)
     	printf("\n No spanning tree exists");
  	else
    	printf("\n\nMinimum cost is %d",mincost);
}


int main()
{
	int edge[20][20],set[15],i,e,n,j;
	printf("\nEnter Total No of vertices: ");
	scanf("%d",&n);
	printf("\nEnter No of Edges: ");
	scanf("%d",&e);
	for(i=1;i<=e;i++)
	{
		printf("\nEnter edge: ");
		scanf("%d %d",&edge[i][0],&edge[i][1]);
		printf("\nEnter cost: ");
		scanf("%d",&edge[i][2]);
	}
	sort(edge,e);
	printf("\nEdges sorted in Ascending order:\n\n ");	
	for(i=1;i<=e;i++)
	printf("%d\t%d\tcost: %d\n",edge[i][0],edge[i][1],edge[i][2]);
	krusk(edge,set,n,e);
	return 0;
}

/*
OUTPUT:

Enter Total No of vertices: 7

Enter No of Edges: 9

Enter edge: 1 2

Enter cost: 25

Enter edge: 2 3

Enter cost: 14

Enter edge: 3 4

Enter cost: 11

Enter edge: 4 5

Enter cost: 20

Enter edge: 5 6

Enter cost: 23

Enter edge: 6 1

Enter cost: 10

Enter edge: 7 2

Enter cost: 12

Enter edge: 7 5

Enter cost: 22

Enter edge: 7 4

Enter cost: 17

Edges sorted in Ascending order:

0       0       cost: 0
6       1       cost: 10
3       4       cost: 11
7       2       cost: 12
2       3       cost: 14
7       4       cost: 17
4       5       cost: 20
7       5       cost: 22
5       6       cost: 23

Considering edge 0 0 
Considering edge 6 1 
2 is selected
Considering edge 3 4 
3 is selected
Considering edge 7 2 
4 is selected
Considering edge 2 3 
5 is selected
Considering edge 7 4 
Considering edge 4 5 
7 is selected
Considering edge 7 5 
Considering edge 5 6 
9 is selected

Minimum cost is 90
*/



