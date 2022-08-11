#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char name[20];
	int age;
	float score;
	fp = fopen("fprintf","w");
	if(fp==NULL)
	{
		printf("File impossible to open");
		exit(1);
	}
		printf("Enter your name : ");
		fflush(stdin);
		gets(name);
		printf("Enter your age: ");
		scanf("%d",&age);
		printf("Enter your score: ");
		scanf("%f",&score);
		fprintf(fp,"%s\n%d\n%f",name,age,score);
	 

	fclose(fp);
}
