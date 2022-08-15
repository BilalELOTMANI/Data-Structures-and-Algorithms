#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
} node;

typedef node *list;

// Insert an element to the beginning of the list

void insertBeginning(list *head, int e)
{
	node *b;
	b = (node*)malloc(sizeof(node));
	b->next = b->prev =NULL;
	b->data = e;
	b->next = *head;
	if(*head!=NULL){
		(*head)->prev = b;
	}
	*head = b;

}

// Insert an element to the end of the list

void insertEnd(list *head, int e)
{
	node *temp, *b;
	b = (node*)malloc(sizeof(node));
	b->next = b->prev = NULL;
	b->data = e;
	if(*head == NULL) *head = b;
	else{
		temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		b->prev = temp;
		temp->next = b;
	}
	printf("\n");
}

// Insert an element after an element in the middle of the list

void insertMiddleAfter(list *head, int e, int v)
{
	node *temp, *b;
	if(*head!=NULL){
		temp = *head;
		while(temp->next!=NULL && temp->data!=v){
			temp = temp->next;
		}
		if(temp->data==v){
			b = (node*)malloc(sizeof(node));      
			b->next = b->prev = NULL;           
			b->data = e;                          
			b->next = temp->next;
			b->prev = temp;
			if(temp->next!=NULL) temp->next->prev = b;
			temp->next = b;
		}
	}
}

// Insert an element before an element in the middle of the list

void insertMiddleBefore(list *head, int e, int v)
{
	node *temp, *b;
	if(*head!=NULL){
		temp = *head;
		while(temp->next!=NULL && temp->data!=v){
			temp = temp->next;
		}
		if(temp->data==v){
			b = (node*)malloc(sizeof(node));      
			b->next = b->prev = NULL;           
			b->data = e;                          
			b->next = temp;
			b->prev = temp->prev;
			if(temp->prev!=NULL) temp->prev->next = b;
			else *head = b;
			
			temp->prev = b;
		}
	}
}


// delete the beginning of the list (head)

void deleteBeginning(list *head)
{
	node *temp;
	if(*head!=NULL){
		temp = *head;
		*head = temp->next;
		if(temp->next!=NULL) temp->next->prev = NULL;
		free(temp);
	}
}

// Delete the end of the list

void deleteEnd(list *head)
{
	node *temp;
	if(*head!=NULL){
		temp = *head;
		while(temp->next!=NULL){
			temp = temp->next;
			}
		if(temp->prev!=NULL) temp->prev->next=NULL;	
		else *head = NULL;
		
		free(temp);			
	}
}

// Delete an element in the middle of the list

void deleteMiddle(list *head, int v)
{
	node *temp;
	if(*head!=NULL){
		temp = *head;
		while(temp->data!=v && temp->next!=NULL){
			temp = temp->next;
		}
		if(temp->data == v){
			if(temp->prev!=NULL) temp->prev->next = temp->next;
			else{
				*head = temp->next;
				temp->next->prev = NULL;
			}
			if(temp->next!=NULL) temp->next->prev = temp->prev;	
		}
		free(temp);
	}
}

// Show the list

void showList(list head)
{
	node *temp;
	temp = head;
	printf("head --");
	while(temp!=NULL){
		printf("(%d)--",temp->data);
		temp = temp->next;
	}
	printf(" End");
	printf("\n");
}


int main(){
	
	list l1=NULL;
	int v;
	
	insertEnd(&l1,1);
	insertEnd(&l1,2);
	insertEnd(&l1,3);
	insertEnd(&l1,4);

	showList(l1);
	
	for(int i; i<10; i++){
	printf("Enter the element to be deleted: ");
	scanf("%d",&v);
	
	deleteMiddle(&l1,v);
	showList(l1);
	}
		
}
