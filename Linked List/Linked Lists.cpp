#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} node;

// Create a new node in the memory (Heap Memory)
node *newNode(int v)
{
	node *ptr;
	ptr = (node*)malloc(sizeof(node));
	ptr->data = v;
	ptr->next = NULL;
}

// Insert an element in the beginning of the list (or the head)
void addBeginning(node **head,int v)
{
	node *b;
	b = newNode(v);
	b->next = *head;
	*head = b;
	
}

// Insert an element in the end of the list
void addEnd(node **head, int v)
{
	node *temp, *b;
	temp = *head;
	b = newNode(v);
	if(*head == NULL){
		*head = b;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = b;
	}
}

// Insert an element in the middle of the list
void addMiddle(node **head, int elem, int v)
{
	node *temp, *b;
	if(*head==NULL) printf("The List is empty!!\n");
	else{
		b = newNode(v);
	    temp = *head;
	    while(temp != NULL && temp->data != elem){
		    temp = temp->next;
	    }
	    if(temp != NULL){
	    	b->next = temp->next;
	        temp->next = b;
		}
	    else{
	    	printf("The element %d doesn't exist !!!\n",elem);
		}
	}
}

// Delete the element in the beginning of the list
void deleteBiginning(node **head)
{
	node *temp;
	if(*head == NULL) printf("The list is empty !!!\n");
	else{
		temp = *head;
		*head = temp->next;
		free(temp);
	}
}

// Delete an element in the middle of the list
void deleteMiddle(node **head, int v)
{
	node *temp, *ptr;
	if(*head != NULL){
		if((*head)->data == v){
			ptr = *head;
			*head = NULL;
			free(ptr);
		}
		else{
			temp = *head;
			while(temp->next != NULL && temp->next->data != v){
			temp = temp->next;
		    }
		    if(temp->next != NULL){
		    	ptr = temp->next;
		        temp->next = ptr->next;
		         free(ptr);
			}
		}
	}
}

// Delete the element in the end of the list
void deleteEnd(node **head)
{
	node *temp;
	if(*head != NULL){
		if((*head)->next == NULL){
			temp = *head;
			free(temp);
			*head = NULL;	
		}
		else{
			temp = *head;
			while(temp->next->next != NULL){
				temp = temp->next;
			}
			free(temp->next);
			temp->next = NULL;
		}
	}
}

// Sort the list
void sortList(node **head)
{
	int a;
	node *temp, *p;
	if(*head != NULL){
		for(temp = *head; temp->next != NULL; temp = temp->next){
			for(p = temp->next; p->next != NULL; p = p->next){
				if(temp->data > p->data){
					a = temp->data;
					temp->data = p->data;
					p->data = a;
				}
			}
		}
	}
}


// Show the elements of the list iteratively
void showListIter(node *head)
{
	node *temp;
	if(head != NULL){
		temp = head;
		while(temp != NULL){
			printf("%d --> ",temp->data);
			temp = temp->next;
		}
	}
	else printf("\nThe list is empty !!!\n");
}

// Show the elements of the list recursively
void showListRec(node *head)
{
	if(head == NULL) return;
	else{
		printf("%d --> ",head->data);
		showListRec(head->next);
	}
}

// Show the reverse list
void showRevList(node *head)
{
	if(head == NULL) return;
	else{
		showRevList(head->next);
		printf("%d --> ",head->data);
	}
}

// Show the reverse list iteratively
void mirrorListIter(node **head)
{
	node *current, *prev, *after;
	current = *head;
	prev = NULL;
	while(current != NULL){
		after = current->next;
		current->next = prev;
		prev = current;
		current = after;
	}
	*head = prev;
}


// Show the reverse list recursively
node *mirrorListRec(node *head)
{
	node *revHead;
	if(head == NULL || head->next == NULL) return head;
	
	revHead = mirrorListRec(head->next);
	head->next->next = head;
    head->next = NULL;
    
    return revHead;
}


int main()
{
	node *L1=NULL;
	int n,i,nbr,v;
	printf("Enter the number of elements: ");
	scanf("%d",&nbr);
	for(i=0;i<nbr;i++){
		scanf("%d",&n);
		addEnd(&L1,n);
	}

	showListRec(L1);
	printf("\n");
/*	showRevList(L1);*/
	printf("\n");
	mirrorListIter(&L1);
	showListRec(L1);
}
