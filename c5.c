#include <stdio.h>
#include <stdlib.h>

int** multiply(int **a, int row1,int col1,int **b,int col2,int **c)
{
	/*int **c = (int**)(malloc(sizeof(int*)*row1));
	
	for ( i = 0; i < row1; ++i)
	{
		c[i]=(int*)(malloc(sizeof(int)*col2));
	}*/
		int i=0,j=0,k=0;
		for ( i = 0; i < row1; ++i)
		{	
			for (j = 0; j < col2; ++j)
			{

				for (k = 0; k < col1; ++k)
				{

					c[i][j]+=a[i][k]*b[k][j];
				}

			}
		}
		return c;
	}


	int main(void){
		int row1=0,col1=0,col2=0;
		printf("Enter Row Number and Column Number of Matrix 1\n" );
		scanf("%d %d",&row1,&col1);
		printf("Enter Column Number of Matrix 2\n" );
		scanf("%d",&col2);
		printf("Enter MATRIX 1 in ROW major form\n");
		int **a = (int**)(malloc(sizeof(int*)*row1));
		int i=0,j=0,k=0;
		for ( i = 0; i < row1; ++i)
		{
			a[i]=(int*)(malloc(sizeof(int)*col1));
		}
		for ( i = 0; i < row1; ++i)
		{
			for (j = 0; j < col1; ++j)
			{
				scanf("%d",&a[i][j]);
			}
		}
		printf("Enter MATRIX 2 in ROW major form\n");

		int **b = (int**)(malloc(sizeof(int*)*col1));
		i=0,j=0,k=0;
		for ( i = 0; i < col1; ++i)
		{
			b[i]=(int*)(malloc(sizeof(int)*col2));
		}
		for ( i = 0; i < col1; ++i)
		{
			for (j = 0; j < col2; ++j)
			{
				scanf("%d",&b[i][j]);
			}
		}
		int **c = (int**)(malloc(sizeof(int*)*row1));
		i=0,j=0,k=0;
		for ( i = 0; i < row1; ++i)
		{
			c[i]=(int*)(malloc(sizeof(int)*col2));
		}
		for (i = 0; i <row1; ++i)
		{
		/* code */
			for (j = 0; j < col2; ++j)
			{
				c[i][j]=0;
			}
		}
		c=multiply(a,row1,col1,b,col2,c);
		for ( i = 0; i < row1; ++i)
		{
			for (j = 0; j < col2; ++j)
			{
				printf("%d ",c[i][j]);
			}
			printf("\n");
		}
	}

