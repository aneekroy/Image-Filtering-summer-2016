#include <stdio.h>
#include <stdlib.h>

unsigned int **readimage(char *src_path,int *m,int *n,int *max_value,char** id)
{	 *id =(char*) malloc(3*sizeof(char));
	FILE *src_file;
	src_file= fopen(src_path,"r");
		if(src_file==NULL){
			printf("Unable to open file for reading\n");
			exit(1);
		}
	fscanf(src_file,"%s",*id);
	fscanf(src_file,"%d",m);	
	fscanf(src_file,"%d",n);
	fscanf(src_file,"%d",max_value);
	int i,j;
	unsigned int **image=(unsigned int**)malloc(sizeof(unsigned int*)*(*m));
	for(i=0;i<(*m);i++)
		image[i]=(unsigned int*)malloc(sizeof(unsigned int)*(*n));
	for(i=0;i<(*m);i++)
	{
		for(j=0;j<(*n);j++)
			fscanf(src_file,"%u",&image[i][j]);
	}
	fclose(src_file);
	return image;
}
void writeimage(unsigned int **image,int row,int col,char *dst_path,int max_value)
{
	int i,j;
	FILE *dst_file;
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
			fprintf(dst_file, "%u ",image[i][j] );
		}
		
	}
	fclose(dst_file);

}

unsigned int **contrast_stretch(unsigned int **image,int *m,int *n,int max_value){
	int i=0,j=0;
	int sum=0;
	int in_i=0,in_j=0;
	
	unsigned int **new_image=(unsigned int**)malloc(sizeof(unsigned int*)*(*m));
	for(i=0;i<(*m);i++)
		new_image[i]=(unsigned int*)malloc(sizeof(unsigned int)*(*n));
	for(i=0;i<(*m);i++)
	{
		for(j=0;j<(*n);j++)
			new_image[i][j]=255;

	}
	
	for(i=1;i<*m-1;i++)
	{
		sum=0;
		for(j=1;j<*n-1;j++){
			//if((i>=1||i<=*m-2)&&(j>=1||j<=*n-2)){
			for(in_i=i-1;in_i<=i+1;in_i++)
				for(in_j=j-1;in_j<=j+1;in_j++)
				sum+=image[in_i][in_j];
				sum=sum/((9*(9+1))/2);
				new_image[i][j]=sum;
			//}
			
		}
	}
	
	return new_image;
}
int main(int argc, char *argv[])
{	
	char *src_path,*dst_path;
	
	int row=0,col=0,max_value=255;
	char* loc;//int i,j;
	
	// <a.out> <src_file> <destination_file>
		
		if (argc != 3)
		{
			printf("Usage <a.out> <src_file> <destination_file> \n");
			return -1;
		}
		src_path=argv[1];
		dst_path=argv[2];
			unsigned int **new_image = readimage(src_path,&row,&col,&max_value,&loc);
		new_image=contrast_stretch(new_image,&row,&col,max_value);
		writeimage(new_image,row,col,dst_path,max_value);


		
		
	return 0;
}
