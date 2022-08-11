#include <stdio.h>
#include <stdlib.h>

int main()
{

	FILE *fp;
	char car[20];
	fp = fopen("fputs","w");
	if(fp==NULL)
	{
		printf("File impossible to open");
		exit(1);
	}
		printf("Enter a list of characters : ");
		fflush(stdin);
		gets(car);
		fputs(car,fp);
		
	fclose(fp);

}
