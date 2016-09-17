#include <stdlib.h>
void optimal_bst(float p[],float q[],int n,float c[][50],float w[][50],int r[][50] )
{
	int i,j,l,k;
	float t;
	for(i=0;i<=n;i++)
	{
		c[i][i]=q[i];
		w[i][i]=q[i];
		r[i][i]=0;
	}
	for(l=1;l<=n;l++)
		for(i=0;i<=n-l;i++)
		{
			j=i+l;
			c[i][j]=9999;
			w[i][j]=w[i][j-1]+p[j]+q[j];
			for(k=i+1;k<=j;k++)
			{
				t=c[i][k-1]+c[k][j]+w[i][j];
				if(t<c[i][j])
				{
					c[i][j]=t;
					r[i][j]=k;
				}
			}

		}
}
int main()
{
int n,i,j,l,r[50][50];
float p[50],q[50],c[50][50],w[50][50];
//clrscr();
printf("Enter the number of keys:");
scanf("%d",&n);
printf("Enter the p values:");
for(i=1;i<=n;i++)
scanf("%f",&p[i]);

printf("Enter the q values:");
for(i=0;i<=n;i++)
scanf("%f",&q[i]);

optimal_bst(p,q,n,c,w,r);

printf("\nThe cost table is\n");
for(j=n;j>=0;j--)
{
for(l=0;l<=j-1;l++)
printf("  ");
for(i=0;i<=n-j;i++)

  printf("%.2f ",c[i][j+i]);
printf("\n");
}

printf("\nThe root table is\n");
for(j=n;j>=0;j--)
{
for(l=0;l<=j-1;l++)
printf(" ");
for(i=0;i<=n-j;i++)

  printf(" %d",r[i][j+i]);
printf("\n");
}

printf("\nThe cost of the OBST is %f and its root is %d",c[0][n],r[0][n]);
//getch();
 return 0;
}

/*OUTPUT:
Enter the number of keys:5
Enter the p values:.15 .1 .05 .1 .2                                             
Enter the q values:.05 .1 .05 .05 .05 .1                                        
                                                                                
The cost table is                                                               
          2.75                                                                  
        1.75 2.00                                                               
      1.25 1.20 1.30                                                            
    0.90 0.70 0.60 0.90                                                         
  0.45 0.40 0.25 0.30 0.50                                                      
0.05 0.10 0.05 0.05 0.05 0.10                                                   
                                                                                
The root table is                                                               
      2                                                                         
     2 4                                                                        
    2 2 5                                                                       
   1 2 4 5                                                                      
  1 2 3 4 5                                                                     
 0 0 0 0 0 0                                                                    
                                                                                
The cost of the OBST is 2.750000 and its root is 2
*/

                                                                                
                                                                                
