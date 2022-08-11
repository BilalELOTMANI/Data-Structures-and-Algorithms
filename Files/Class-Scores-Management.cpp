#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int code;
char lastName[20], firstName[20];
float writingScore, speakingScore;
FILE *fp;


void addStudent()
{
	int codeR , tr=0;
	fp = fopen("Grades","a+");
	if(fp==NULL){
		printf("File impossible to open.");
	}
	printf("Enter the code: ");
	scanf("%d",&codeR);

	while(!feof(fp)){
		fscanf(fp,"%d\n%s\n%s\n%.2f\n%.2f\n",&code,lastName,firstName,&writingScore,&speakingScore);
		if(code==codeR){
			tr = 1;
			break;
		}
	}
	if(tr==1) printf("The student exist !!!\n");
	else{
		printf("Enter the lastName: ");
		scanf("%s",lastName);
		printf("Enter the firstName: ");
		scanf("%s",firstName);
		do{
			printf("Enter the writing score: ");
			scanf("%f",&writingScore);
		}while(writingScore<0 || writingScore>20);
		do{
			printf("Enter the speaking score: ");
			scanf("%f",&speakingScore);
		}while(writingScore<0 || writingScore>20);

		fprintf(fp,"%d\n%s\n%s\n%f\n%f\n",codeR,lastName,firstName,writingScore,speakingScore);
		}

	fclose(fp);
}

void Grades()
{
    int codeR, tr=0;
    fp = fopen("Grades","r");
    if(fp==NULL){
        printf("choice.");
    }
    printf("Enter the code: ");
    scanf("%d",&codeR);
    while(!feof(fp)){
        fscanf(fp,"%d\n%s\n%s\n%f\n%f\n",&code,lastName,firstName,&writingScore,&speakingScore);
        if(code==codeR){
            tr=1;
            printf("The lastName is: %s\n",lastName);
            printf("The firstName is: %s\n",firstName);
            printf("The writing score is: %.2f\n",writingScore);
            printf("The speaking score is: %.2f\n",speakingScore);
            printf("The final score is: %.2f\n\n",(writingScore+speakingScore)/2);
        }
    }
    if(tr==0) printf("The student doesn't exist'.\n");
    fclose(fp);
}

void classMeanScore()
{
    float Smoy=0;
    int Netd=0;
    fp = fopen("Grades","r");
    if(fp==NULL){
        printf("File impossible to open.");
    }
    while(fscanf(fp,"%d\n%s\n%s\n%f\n%f\n",&code,lastName,firstName,&writingScore,&speakingScore)==5){
        Netd++;
        Smoy+=(writingScore+speakingScore)/2;
    }
    if(Netd==0){
        printf("No registered student.\n");
    }
    else{
        printf("The mean score of the class is: %.2f\n\n",Smoy/Netd);
    }
    fclose(fp);
}

void acceptedList()
{
    int Netd = 0;
    float moy;
    fp = fopen("Grades","r");
    if(fp==NULL){
        printf("File impossible to open.\n");
    }
    printf("Code\tname\tPrename\tNote\tENoteO\tMoy\n");
    while(fscanf(fp,"%d\n%s\n%s\n%f\n%f\n",&code,lastName,firstName,&writingScore,&speakingScore)==5){
        Netd++;
        moy = (writingScore+speakingScore)/2;
        if(moy >= 10){
                printf("%d\t%s\t%s\t%.2f\t%.\t%.2f\n",code,lastName,firstName,writingScore,speakingScore,moy);
        }
    }
    if(Netd==0) printf("No registered student.\n");
    fclose(fp);
}

void editStudent()
{
    FILE *temp, *fp;
    int codeR;
    int tr = 0;
    fp = fopen("Grades","r");
    if(fp==NULL){
        printf("File impossible to open.\n");
    }
    temp = fopen("temp","w");
    if(fp==NULL){
        printf("File impossible to open.\n");
    }
    printf("Enter the code of student to be modified: ");
    scanf("%d",&codeR);
    while(fscanf(fp,"%d\n%s\n%s\n%f\n%f\n",&code,lastName,firstName,&writingScore,&speakingScore)==5){
        tr = 1;
        if(code==codeR){
            printf("The new lastName: ");
            scanf("%s",lastName);
        }
        fprintf(temp,"%d\n%s\n%s\n%f\n%f\n",code,lastName,firstName,writingScore,speakingScore);
    }
    fclose(fp);
    fclose(temp);
    if(tr==0) printf("The list is empty !!!!!\n");
    else printf("Le lastName is modified.\n\n");
    remove("Grades");
    rename("temp","Grades");
}

void deleteStudent()
{
    FILE *fp, *temp;
    int codeR, tr=0;
    fp = fopen("Grades","r");
    if(fp==NULL){
        printf("File impossible to open.\n");
    }
    temp = fopen("temp","w");
    if(fp==NULL){
        printf("File impossible to open.\n");
    }
    printf("Enter the code of the student to be deleted: ");
    scanf("%d",&codeR);
    while(fscanf(fp,"%d\n%s\n%s\n%f\n%f\n",&code,lastName,firstName,&writingScore,&speakingScore)==5){
        tr = 1;
        if(code!=codeR){
            fprintf(temp,"%d\n%s\n%s\n%f\n%f\n",code,lastName,firstName,writingScore,speakingScore);
        }
    }
    fclose(fp); fclose(temp);
    if(tr==0) printf("The list is empty !!!!!\n");
    else printf("Le lastName a ete supprime.\n\n");
    remove("Grades");
    rename("temp","Grades");
}

int main() {
	int choice;
	do{
		printf("**** Menu of management of students ****\n\n");
		printf("1-New student\n");
		printf("2-Show grades\n");
		printf("3-Modify the lastName\n");
		printf("4-Delete a student\n");
		printf("5-Show the mean score of the class\n");
		printf("6-Accepted list\n");
		printf("0-End of work.\n\n");
		printf("Your choice: "); scanf("%d",&choice);
        switch(choice)
        {
        	case 1:
        		{
        			addStudent();
        			break;
				}
			case 2:
        		{
        			Grades();
        			break;
				}
			case 3:
        		{
        			editStudent();
        			break;
				}
			case 4:
        		{
        			deleteStudent();
        			break;
				}
			case 5:
        		{
        			classMeanScore();
        			break;
				}
			case 6:
        		{
        			acceptedList();
        			break;
				}
			case 0:
        		{
        			printf("End of work\n");
        			break;
				}
			default : 	printf("choice errored !!");
		}
	}
	while(choice!=0);
	return 0;
}

