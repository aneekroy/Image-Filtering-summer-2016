#include <stdio.h>
/*void insertion_sort(int *a,int size){
	
}*/
int main(void){
	int a[10]={0};
	int no=0,curr=0,count=0,n=0;
	scanf("%d",&n);
	while(count++<n){
		scanf("%d",&curr);
		if(curr<11&&curr>0)
			a[curr]++;
	}
	count=0;
	while(count++<11){
			no=a[count-1];
			if(count-1!=0)printf("|%d|",count-1);
		while(no!=0){
			printf("*");
			no--;
		}printf("\n");
	}
	return 0;
}