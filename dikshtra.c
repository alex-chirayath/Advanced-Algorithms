#include<stdio.h>
#include<stdlib.h>

int n,e;
int cost[20][20],dist[20];

void display(int v)
{
	int i;
	int sum;
	for(i=1;i<=n;i++)
	{
		printf("\nLength of the shortest path from %c->%c=%d\n",v+64,i+64,dist[i]);
		sum=sum+dist[i];
	}
}

void readedges()
{
	int i,j,v1,v2;
	printf("\nEnter no of vertices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cost[i][j]=9999;
		cost[i][i]=0;
	}
	printf("\nEnter total no of edges: ");
	scanf("%d",&e);
	for(i=1;i<=e;i++)
	{
		printf("\nEnter the starting vertex-ending vertex: ");
		scanf("%d%d",&v1,&v2);
		printf("\nEnter cost: ");
		scanf("%d",&cost[v1][v2]);
	}
	for(i=1;i<=n;i++)
		dist[i]=9999;
}

void shortestpath(int v)
{
	int w,u,s[20],min,i,num;
	for(i=1;i<=n;i++)
	{
		s[i]=0;
		dist[i]=cost[v][i];
	}
	s[v]=1;
	dist[v]=0;
	for(num=2;num<n;num++)
	{
		min=9999;
		for(i=1;i<=n;i++)
		{
			if(s[i]!=1&&min>dist[i]&&dist[i]!=-1)
			{
				u=i;
				min=dist[i];
			}
		}
		s[u]=1;
		for(w=1;w<=n;w++)
			if((s[w]==0)&&(dist[w]>dist[u]+cost[u][w]))
				dist[w]=dist[u]+cost[u][w];
	}
}

int main()
{
	int v,i;
	readedges();
	printf("\nEnter the vertex for finding the shortest path: ");
	scanf("%d",&v);
	shortestpath(v);
	display(v);
}

/* OUTPUT :
Enter no of vertices: 5

Enter total no of edges: 7

Enter the starting vertex-ending vertex: 1 2
Enter cost: 10

Enter the starting vertex-ending vertex: 2 3
Enter cost: 50

Enter the starting vertex-ending vertex: 1 5
Enter cost: 100

Enter the starting vertex-ending vertex: 3 5
Enter cost: 10

Enter the starting vertex-ending vertex: 4 5
Enter cost: 60

Enter the starting vertex-ending vertex: 1 4
Enter cost: 30

Enter the starting vertex-ending vertex: 4 3
Enter cost: 20

Enter the vertex for finding the shortest path: 1

Length of the shortest path from A->A=0
Length of the shortest path from A->B=10
Length of the shortest path from A->C=50
Length of the shortest path from A->D=30
Length of the shortest path from A->E=60
*/
