#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char file[10],pattern[10],temp[200];
	FILE *fp;
	printf("Enter file name\n");
	scanf("%s",file);
	fp=fopen(file,"r");
	if (fp == NULL) 
	{ 
		printf("Cannot open file %s \n", file); 
		exit(0); 
	} 
	printf("Enter pattern to be searched\n");
	scanf("%s",pattern);

	while(!feof(fp))
	{
		fgets(temp,100,fp);
		if(strstr(temp,pattern))
			printf("%s",temp);
	}
	fclose(fp);
}
