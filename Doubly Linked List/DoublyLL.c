#include<stdio.h>
#include<stdlib.h>

typedef struct DoublyLL
{
    int data;
    struct DoublyLL *next;
    struct DoublyLL *prev;
}DoublyLL;

DoublyLL *head=NULL;
void CreateAndInsertAtEnd(int data){
    DoublyLL *newNode = (DoublyLL*)malloc(sizeof(DoublyLL));
    newNode->data = data;
    if(!head){
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }else{
        DoublyLL *current = head;
        while(current->next){
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        newNode->next = NULL;
    }
}
void InsertAtBeg(int data){
    DoublyLL *newNode = (DoublyLL*)malloc(sizeof(DoublyLL));
    newNode->data = data;
    if(!head){
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }else{
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = NULL;
        head = newNode;
    }
}
void InsertBefore(int data,int find){
    if(!head){
        return;
    }else if(head->data == find){
        InsertAtBeg(data);
    }else{
        DoublyLL *newNode = (DoublyLL*)malloc(sizeof(DoublyLL));
        newNode->data = data;
        DoublyLL *current = head;
        while(current->next && find!=current->data){
            current = current->next;
        }
        current->prev->next = newNode;
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev = newNode;
    }
}
void InsertAfter(int data,int find){
    if(!head){
        return;
    }else{
        DoublyLL *newNode = (DoublyLL*)malloc(sizeof(DoublyLL));
        newNode->data = data;
        DoublyLL *current = head;
        while(current->next && find!=current->data){
            current = current->next;
        }
        if(current->next == NULL){
            CreateAndInsertAtEnd(data);
        }else{
            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }
}
void DeleteAtBeg(){
    if(head == NULL){
        return;
    }
    DoublyLL *tmp = head;
    if(tmp->next){
        head = tmp->next;
        head->prev = NULL;
    }else{
        head = NULL;
    }
    free(tmp);
}
void DeleteAtLast(){
    if(head == NULL){
        return;
    }
    DoublyLL *current = head;
    while(current->next){
        current = current->next;
    }
    if(current->prev){
        current->prev->next = NULL;
        free(current);
    }else{
        free(current);
        head = NULL;
    }
}
void Delete(int find){
    if(head == NULL){
        return;
    }
    DoublyLL *current = head;
    if(head->data == find){
        DeleteAtBeg();
    }else{
        while(current->next && current->data != find){
            current = current->next;            
        }
        if(current->next == NULL)
            DeleteAtLast();
        else{
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
        }
    }
}
void Display(){
    if(!head){
        return;
    }
    printf("\nPrinting Data From Beginning \n");
    DoublyLL *current = head;
    DoublyLL *prevCur = head;
    while(current){
        printf("%d ",current->data);
        prevCur = current;
        current = current->next;
    }
    printf("\nPrinting Data From Last \n");
    while(prevCur){
        printf("%d ",prevCur->data);
        prevCur = prevCur->prev;
    }
    printf("\n");
}

int main(){
    
	printf("Enter 1st Element to Create a node ");
	int data;
	scanf("%d",&data);
	CreateAndInsertAtEnd(data);
	int flag=1;
	while(flag){
		printf("Enter 1 to add data at end\nEnter 2 to add data at start\nEnter 3 to add data after some element\nEnter 4 to add data before some element\nEnter 5 to display\nEnter 6 to Delete At Beginning\nEnter 7 to delete Last element\nEnter 9 to delete specific Data\nEnter -1 to exit\n");
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
				InsertAfter(data,key);
				break;	
			case 4:
				printf("Enter the data ");
				scanf("%d",&data); 
				printf("Enter the data before you want to insert");
				scanf("%d",&key);
				InsertBefore(data,key);
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
			case 9:
				printf("\nEnter the data to Delete ");
				scanf("%d",&data);
				Delete(data);
				break;
			case -1:
				printf("Focus!!!");
				flag = 0;
				break;	
		}
	}
}