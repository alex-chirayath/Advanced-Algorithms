#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int kmp( char substring [] , char string[])
{
	int i , j , l_string, l_substr, * d; 

	l_string = strlen(string);
	l_substr= strlen(substring);

	d = (int * ) malloc (l_substr * sizeof(int ));
	d[0]=0;

	for(i= 0, j = 0; i< l_substr;i++)
	{
		while(j > 0 && substring[j]!= substring[i])
			j = d[j-1];

		if(substring[j]==substring[i])
		{
			j++;
			d[i]=j;
		}

	}//end of for loop

	for(i = 0 , j= 0; i< l_string;i++)
	{
		while(j>0 && (substring[j]!=string[i]))
		{
			j=d[j-1];
		}
		if(substring[j]==string[i])
			j++;

		if(j==l_substr)
		{
			free(d);
			return i - j + 1;
		}
	}// end of for loop

	free(d);
	return -1;
}

int main()
{
	char string[100];
	char substr[50];
	int pos;
	printf("enter the string \n");
	gets(string);
	printf("enter the substring \n");
	gets(substr);
	pos = kmp(substr, string);

	printf("\nans = %d ", pos);
	return 0 ;
}
/*
output
enter the string 
hello world
enter the substring 
world
11 length of string  
 5 length of sub string 
ans = 6 
*/
