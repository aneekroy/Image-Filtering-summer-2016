#include<stdio.h>

int main(void){
	printf("\nEnter n :");
	int n=0;
	scanf("%d",&n);
	int row=0;
	int col=0;
	int count=1;
	while(row<n+1){
		col=0;
		while((col++)<row){
			printf("%d ",(count));
			count++;
		}
			printf("\n");
			row++;
	} 
	return 0;
	}