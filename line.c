#include <stdio.h>
#include <stdlib.h>
	typedef struct point
	{
		int x;
		int y;
	}poi;

	void onpixel(unsigned int** im,poi np,int v){
		im[np.x][np.y]=v;
	}
	unsigned int **line_plot(unsigned int **image,poi a,poi b){
			
			int d=0;
			int A=b.y-a.y;
			int B=a.x-b.x;
			poi temp;
			float m = -(float)A/B;
			temp.x=a.x;
			temp.y=a.y;
			d=2*A+B;
			while(temp.x<=b.x){
				onpixel(image,temp,0);
	
				if(d>=0){
					temp.x++;
					temp.y++;
					d+=A+B;
				}
				else{
					temp.x++;
					d+=A;
				}
				
			}
			return image;

		}

		void writeimage(unsigned int **image,int row,int col,char *dst_path,int max_value)
		{
			int i,j;
			FILE *dst_file,*matrix;
			dst_file= fopen(dst_path,"w+");
			if(dst_file==NULL){
				printf("Unable to open file for writing\n");
				exit(1);
			}
			fprintf(dst_file, "%s\n","P2");
			fprintf(dst_file, "%d %d\n",row,col );
			fprintf(dst_file, "%d\n",max_value);
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++){
					fprintf(dst_file, "%d ",image[i][j] );
				}
				
			}
			fclose(dst_file);

		}
int main(int argc, char *argv[])
{	
	char *dst_path;
	poi first,second;
	int row=0,col=0,max_value=255,i=0,j=0;
	char* loc;
	
	if (argc != 2)
	{
		printf("Usage <a.out> <destination_file> \n");
		return -1;
	}
	dst_path=argv[1];
	printf("Enter Row and Columns\n");
	scanf("%d %d",&row,&col);
	printf("Enter Start Vertices\n");
	scanf("%d %d",&first.x,&first.y);

	printf("Enter End Verices\n");
	
	scanf("%d %d",&second.x,&second.y);

	unsigned int **image=(unsigned int**)malloc(sizeof(unsigned int*)*(row));
	for(i=0;i<(row);i++)
		image[i]=(unsigned int*)malloc(sizeof(unsigned int)*(col));
	for(i=0;i<(row);i++)
	{
		for(j=0;j<(col);j++){
			image[i][j]=255;
		}
	}
	for(i=0;i<(row);i++)
	{
		for(j=0;j<(col);j++){
			if(i%10==0||j%10==0)
			image[i][j]=200;
		}
	}
			image=line_plot(image,first,second);
			writeimage(image,row,col,dst_path,max_value);
			return 0;
}
