#include<stdio.h>
#include<stdlib.h>
int main ()
{
	FILE *fp1,*fp2;
	char c;
	char file1[100],file2[100];
	printf("Enter the filename to open for reading \n"); 
	scanf("%s", file1); 
	fp1=fopen(file1,"r");
	if (fp1 == NULL) 
	{ 
		printf("Cannot open file %s \n", file1); 
		exit(0); 
	} 
	printf("Enter the filename to open for writing \n"); 
	scanf("%s", file2); 
	fp2=fopen(file2,"w");
	c=fgetc(fp1);
	while(c!=EOF)
	{
		fputc(c,fp2);
		c=fgetc(fp1);
	}
	printf("\nContents are copied from %s to the file %s\n",file1,file2);
	fclose(fp1); 
	fclose(fp2); 
	return 0;
}
