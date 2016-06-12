#include <stdio.h>
#include <math.h>
/*int main(void){
	//printf("%lu\n",sizeof(int));
	int x=0x765432f2;
	char *p=(char*)&x;
	printf("x=%d\n",x );
	printf("first byte=%d\n",(int)*p);
	printf("Second byte=%d\n",(int)(*(p+1)));
	printf("Third byte=%d\n",(int)(*(p+2)));
	printf("Fourth byte=%d\n",(int)(*(p+3)));
	double x1=0,x2=0;
	int count =0;
	while(count<4){
		x1=pow(16,count);
		x2+=(int)x1*(*(p+count));
		count++;
	}
	printf("x2=%d\n",x2);
}
*/
int main(void){
	int x=0x10030421;
	printf("x=%x\n",x );
	char *p=(char*)&x;
	printf("x=%d\n",x );
	printf("first byte=%x\n",(int)*p);
	printf("Second byte=%x\n",(int)(*(p+1)));
	printf("Third byte=%x\n",(int)(*(p+2)));
	printf("Fourth byte=%x\n",(int)(*(p+3)));
	/*double x1=0,x2=0;
	int count =0,count1=3;
	while(count<4){
		x1=pow(16,count1);
		x2+=(int)x1*(*(p+count1));
		count++;count1--;
	}
	printf("x2=%lf\n",x2);
	*/
	
}
