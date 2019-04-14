#include<stdio.h>
#include<dirent.h>
int main()
{
	DIR *d;
	struct dirent *de;
	d=opendir(".");
	if(d==NULL)
	{	
		printf("Can't Open the Directory\n");
		return 0;
	}
	printf("Contents in the current Directory\n");
	while((de=(readdir(d)))!=NULL)
	{
		printf("%s\n",de->d_name);		
	}
	closedir(d);
	return 0;
}
