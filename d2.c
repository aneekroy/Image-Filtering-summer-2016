#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char id[2];
	fscanf(f,"%s",loc);
	int row=0,col=0,max_value=0,i=0,j=0;
	char *src_path,*dst_path;
	FILE *src_file,*dst_file,*matrix;
	char ch;
	// <a.out> <src_file> <destination_file>
		
		if (argc != 3)
		{
			printf("Usage <a.out> <src_file> <destination_file> \n");
			return -1;
		}
		src_path=argv[1];
		dst_path=argv[2];

		src_file= fopen(src_path,"r");
		if(src_file==NULL){
			printf("Unable to open file for reading\n");
			return -1;
		}
		dst_file= fopen(dst_path,"w+");
		if(dst_file==NULL){
			printf("Unable to open file for writing\n");
			return -1;
		}
		matrix= fopen("/home/aneek/summer/matrix.txt","w");
		/*ch=fgetc(src_file);
		while(ch!=EOF){
			fputc(ch,dst_file);
			ch=fgetc(src_file);
		}
		fclose(src_file);
		fclose(dst_file);
		*/

		/**/
		fscanf(src_file,"%s",id);
		//fscanf(f,%c)
		fscanf(src_file,"%d",row);
		fscanf(src_file,"%d",col);
		fscanf(src_file,"%d",max_value);
		 int **image =(int**)malloc(sizeof(int*)*row);
		for(i=0;i<row;i++){
			image[i]=( int*)malloc(sizeof(int)*col);
		}
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				fscanf(src_file,"%d",((image+i)+j));
				fprintf(matrix,"%d",image[i][j]);
			}
		}
		/**/
		fprintf(dst_file, "%s\n",id );
		fprintf(dst_file, "%d ", row);
		fprintf(dst_file,"%d\n",col);
		fprintf(dst_file,"%d",max_value);
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				fprintf(dst_file,"%d",image[i][j]);
			}
		}
		



	return 0;
}

	
	