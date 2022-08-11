#include <stdio.h>
#include <stdlib.h>

int main()
{

	
	FILE *fp;
	char car;
	fp = fopen("C:\\Users\\Owner\\Documents\\desktop\\file.txt","r");
	if(fp==NULL)
	{
		printf("File impossible to open");
		exit(1);
	}

	while(!feof(fp))   /* !feof(fp) : As long as it's not the end of the file */
	{
		car=fgetc(fp);
		printf("%c",car);
	}
	
	fclose(fp);

}

