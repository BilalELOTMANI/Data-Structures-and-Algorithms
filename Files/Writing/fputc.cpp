#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char car;
	fp = fopen("fputc.txt","w");
	if(fp==NULL){
		printf("File impossible to open");
		exit(1);
	}
	do{
		printf("Enter a character, to finish enter(.): ");
		fflush(stdin);
		scanf("%c",&car);
		fputc(car,fp);
	}
	while(car!='.');
	fclose(fp);
}
