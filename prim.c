#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
#define INF 9999

void create(int G[][SIZE],int n)
{
int i,j,v1,v2,k,e;
printf("\nEnter the no. of edges:");
scanf("%d",&e);
for(i=0;i<e;i++)
for(j=0;j<e;j++)
G[i][j]=0;
for(i=0;i<e;i++)
{
printf("Enter the vertex v1 and vertex v2 of an edge:");
scanf("%d%d",&v1,&v2);
printf("\nEnter the corresponding weight:");
scanf("%d",&G[v1][v2]);
}
}

void prim(int G[][SIZE],int n)
{
int total=0,v1=0,v2=0,min_dist,tree[n],i,j,k;
for(i=0;i<n;i++)
tree[i]=0;
tree[0]=1;

for(k=1;k<n;k++)
{
  min_dist=INF;
   
   for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
          {
            
             if(G[i][j] && ((tree[i] && !tree[j]) || (tree[j] && !tree[i])))
                {
                    if(G[i][j]<min_dist)
                     {
                         min_dist=G[i][j];
                         v1=i;v2=j;
 
                     }
                 }

          }

     }
            
printf("\nEdge : %d--->%d",v1,v2);
printf("\tWeight : %d",G[v1][v2]); 

tree[v1]=tree[v2]=1;
total+=G[v1][v2];

}
printf("\nTotal Cost : %d",total);
}                

int main ()
{
int G[SIZE][SIZE],nodes,edges,i,j;
printf("\nEnter the no. of nodes:");
scanf("%d",&nodes);
create(G,nodes);
prim(G,nodes);
return 0;
}
/*
Output:
Enter the no. of nodes:7

Enter the no. of edges:9 
Enter the vertex v1 and vertex v2 of an edge:0
1

Enter the corresponding weight:25
Enter the vertex v1 and vertex v2 of an edge:1
2

Enter the corresponding weight:14
Enter the vertex v1 and vertex v2 of an edge:2
3

Enter the corresponding weight:11
Enter the vertex v1 and vertex v2 of an edge:3
4

Enter the corresponding weight:20
Enter the vertex v1 and vertex v2 of an edge:4
5

Enter the corresponding weight:23
Enter the vertex v1 and vertex v2 of an edge:5
0

Enter the corresponding weight:10
Enter the vertex v1 and vertex v2 of an edge:4
6

Enter the corresponding weight:22
Enter the vertex v1 and vertex v2 of an edge:3
6

Enter the corresponding weight:7
Enter the vertex v1 and vertex v2 of an edge:6
1

Enter the corresponding weight:12

Edge : 5--->0   Weight : 10
Edge : 4--->5   Weight : 23
Edge : 3--->4   Weight : 20
Edge : 3--->6   Weight : 7
Edge : 2--->3   Weight : 11
Edge : 6--->1   Weight : 12
Total Cost : 83
*/
