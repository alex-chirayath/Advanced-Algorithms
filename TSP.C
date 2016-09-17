#include <stdio.h>
#define MAX 100
#define INFINITY 999
 
int tsp_dp (int c[][MAX], int tour[], int start, int n);
 
int main()
{
int n;
int i, j; 
int c[MAX][MAX]; 
int tour[MAX]; 
int cost; 
 
printf ("This program demonstrates the TSP problem.");
printf ("\nHow many cities to traverse? ");
scanf ("%d", &n);
printf ("Enter the cost matrix: (999: no connection)\n");
for (i=0; i<n; i++)
for (j=0; j<n; j++)
scanf ("%d", &c[i][j]);
 
for (i=0; i<n; i++)
tour[i] = i;
 
cost = tsp_dp (c, tour, 0, n);
 
printf ("Minimum cost: %d.\nTour: ", cost);
for (i=0; i<n; i++)
printf ("%d ", tour[i]+1);
printf ("1\n");
}

int tsp_dp (int c[][MAX], int tour[], int start, int n)
{
int i, j, k; 
int temp[MAX]; 
int mintour[MAX];
int mincost; 
int ccost; 
 

if (start == n - 2)
return c[tour[n-2]][tour[n-1]] + c[tour[n-1]][0];

mincost = INFINITY;
for (i = start+1; i<n; i++)
{ for (j=0; j<n; j++)
temp[j] = tour[j];
 
/* Adjust positions. */
temp[start+1] = tour[i];
temp[i] = tour[start+1];
 
if (c[tour[start]][tour[i]] +
(ccost = tsp_dp (c, temp, start+1, n)) < mincost) {
mincost = c[tour[start]][tour[i]] + ccost;
for (k=0; k<n; k++)
mintour[k] = temp[k];
}
}
 
/* Set the minimum-tour array. */
for (i=0; i<n; i++)
tour[i] = mintour[i];
 
return mincost;
}

/*
OUTPUT :
How many cities to traverse? 3
Enter the cost matrix: (999: no connection)
10
5
12
30
4
5
11
50
13
Minimum cost: 21.
Tour: 1 2 3 1
*/
