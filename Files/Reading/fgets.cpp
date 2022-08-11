#include <stdio.h>
#include <stdlib.h>

int main()
{

	
	FILE *fp;
	char car[20];
	fp = fopen("C:\\Users\\Owner\\Documents\\desktop\\file.txt","r");
	if(fp==NULL)
	{
		printf("File impossible to open");
		exit(1);
	}

	while(!feof(fp))  
	{
		fgets(car,19,fp);
		printf("%s",car);
	}
	
	fclose(fp);

}
