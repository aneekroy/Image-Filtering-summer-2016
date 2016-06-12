#include <stdio.h>

int main(int argc, char *argv[])
{	
	char *src_path,*dst_path;
	FILE *src_file,*dst_file;
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
		ch=fgetc(src_file);
		while(ch!=EOF){
			fputc(ch,dst_file);
			ch=fgetc(src_file);
		}
		fclose(src_file);
		fclose(dst_file);

	return 0;
}