#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *HEAD=NULL;
void CreateAndInsertAtEnd(int data){
	node *newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	if(HEAD==NULL){
		HEAD = newNode;
	}
	else{
		node *tmp = HEAD;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
}
void InsertAtBeg(int data){
	if(HEAD==NULL){
		return;
	}
	else{
		node *newNode;
		newNode = (node*)malloc(sizeof(node));
		newNode->data = data;
		newNode->next = HEAD;
		HEAD = newNode;
	}
}
void InsertAfterValue(int key, int data){
	node *newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	if(HEAD==NULL){
		return;
	}
	else{
		node *tmp = HEAD;
		while(tmp->data!=key){
			if(tmp->next==NULL){
				CreateAndInsertAtEnd(data);
				free(newNode);
			}
			else
				tmp = tmp->next; 
		}
		newNode->next=tmp->next;
		tmp->next = newNode;
	}
}
void InsertBeforeValue(int key, int data){
	node *newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	if(HEAD->next == NULL || HEAD == NULL){
		if(HEAD->data==key){
			newNode->next = HEAD;
			HEAD = newNode;
		}
		else{
			return;
		}
	}
	else if(HEAD->data==key){
			newNode->next = HEAD;
			HEAD = newNode;
	}
	else{
		node *tmp,*ttmp;
		tmp = HEAD;
		ttmp = HEAD;
		while(tmp->data!=key){
			ttmp = tmp;
			tmp = tmp->next;
		}
		ttmp->next = newNode;
		newNode->next = tmp; 
	}
}
void Display(){
	if(HEAD == NULL){
		return;
	}
	node *current=HEAD;
	while(current!=NULL){
		printf("%d\t",current->data);
		current = current->next;
	}
	printf("\n");
}
void DeleteAtBeg(){
	node *tmp = HEAD;
	HEAD = HEAD->next;
	printf("\nDeleting %d\n",tmp->data);
	free(tmp);
}
void DeleteAtLast(){
	node *tmp=HEAD;
	while(tmp->next->next!=NULL){
		tmp = tmp->next; 
	}
	free(tmp->next);
	tmp->next = NULL;
}
void DeleteEntireList(){
	while(HEAD!=NULL){
		DeleteAtBeg();
	}
	if(HEAD==NULL){
		printf("Entire List has been Deleted");
	}
}

void DeleteAtValue(int data){
	if(HEAD->data == data){
		DeleteAtBeg();
	}
	else{
		node *current,*prev;
		current=HEAD;
		while(current->data!=data){
			prev = current;
			if(current->next==NULL)
				DeleteAtLast();
			else
				current = current->next;
		}
		prev->next = current->next;
		free(current);
	}
}

int main(){
	printf("Enter 1st Element to Create a node ");
	int data;
	scanf("%d",&data);
	CreateAndInsertAtEnd(data);
	int flag=1;
	while(flag){
		printf("Enter 1 to add data at end\nEnter 2 to add data at start\nEnter 3 to add data after some element\nEnter 4 to add data before some element\nEnter 5 to display\nEnter 6 to Delete At Beginning\nEnter 7 to delete Last element\nEnter 8 to Delete Entire List\nEnter 9 to delete specific Data\nEnter -1 to exit\n");
		int option;
		int data,key;
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter the data ");
				scanf("%d",&data);
				CreateAndInsertAtEnd(data);
				break;
			case 2:
				printf("Enter the data ");
				scanf("%d",&data);
				InsertAtBeg(data);
				break;
			case 3:
				printf("Enter the data ");
				scanf("%d",&data); 
				printf("Enter the data after you want to insert");
				scanf("%d",&key);
				InsertAfterValue(key,data);
				break;	
			case 4:
				printf("Enter the data ");
				scanf("%d",&data); 
				printf("Enter the data before you want to insert");
				scanf("%d",&key);
				InsertBeforeValue(key,data);
				break;	
			case 5:
				Display();
				break;	
			case 6:
				DeleteAtBeg();
				break;
			case 7:
				DeleteAtLast();
				break;
			case 8:
				DeleteEntireList();
				break;
			case 9:
				printf("\nEnter the data to Delete ");
				scanf("%d",&data);
				DeleteAtValue(data);
				break;
			case -1:
				printf("Focus!!!");
				flag = 0;
				break;	
		}
	}
}
