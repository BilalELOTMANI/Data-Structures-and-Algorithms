#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	char name[20];
	int age;
	float score;
	fp = fopen("Students.txt","a");
	if(fp==NULL){
		printf("File impossible to open.\n");
		exit(1);
	}
	printf("Enter the name: ");
    scanf("%s",name);
	printf("Enter the age: ");
	scanf("%d",&age);
	printf("Enter the score: ");
	scanf("%f",&score);
	fprintf(fp,"%s\n%d\n%f\n",name,age,score);
	fclose(fp);
/*	rewind(fp);  */


	fp = fopen("Student.txt","r");
	while(fscanf(fp,"%s\n%d\n%f",name,&age,&score)==3){
		
	    printf("The name is: %s\n",name);
	    printf("The age is: %d\n",age);
	    printf("The score is: %f\n",score);
	    printf("**************************\n");
	}
	
	fclose(fp);

}
