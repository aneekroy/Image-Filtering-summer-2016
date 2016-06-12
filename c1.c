#include<stdio.h>

int main(void){
	printf("\nEnter n :");
	int n=0;
	scanf("%d",&n);
	int row=0;
	int col=0;
	while(row<n){
		col=0;
		while((col++)<4){
			printf("%d ",(row+1));
		}
			printf("\n");
			row++;
	} 
	return 0;
	}