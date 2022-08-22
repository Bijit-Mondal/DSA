#include<stdio.h>
#include<stdlib.h>
typedef struct DCircularLL{
    int data;
    struct DCircularLL *next;
    struct DCircularLL *prev;
}DCircularLL;

DCircularLL *head = NULL;
DCircularLL *tail = NULL;

void CreateLL(int data){
    DCircularLL *newNode = (DCircularLL *) malloc(sizeof(DCircularLL));
    newNode->data = data;
    if(!head){
        head = newNode;
        tail = newNode;
        newNode->next = tail;
        newNode->prev = head;
    }else{
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
}
void InsertAtBeg(int data){
    DCircularLL *newNode = (DCircularLL *) malloc(sizeof(DCircularLL));
    newNode->data = data;
    if(!head){
        CreateLL(data);
    }else{
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}
void InsertAtLast(int data){
    CreateLL(data);
}
void InsertBefore(int data,int key){
    if(!head){
        printf("Linked list not created\nCreating a new Linked list\n");
        CreateLL(data);
    }else if(head->data == key){
        InsertAtBeg(data);
    }else{
        DCircularLL *newNode = (DCircularLL *) malloc(sizeof(DCircularLL));
        newNode->data = data;
        DCircularLL *current = tail;
        while(current!=head && current->data!=data){
            current = current->prev;
        }
        if(key == current->data){
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev = newNode;
            newNode->prev->next = newNode;
        }else{
            printf("Data Not Found\nInserting at first\n");
            free(newNode);
            InsertAtBeg(data);
        }
    }
}
void InsertAfter(int data,int key){
    if(!head){
        printf("Linked List Not Created\nCreating a New Linked List\n");
        CreateLL(data);
    }else if(tail->data == key){
        InsertAtLast(data);
    }else{
        DCircularLL *newNode = (DCircularLL *) malloc(sizeof(DCircularLL));
        newNode->data = data;
        DCircularLL *current = head;
        while(current!=tail && current->data!=data){
            current = current->next;
        }
        if(key == current->data){
            newNode->next = current->next;
            newNode->prev = current;
            current->next = newNode;
            newNode->next->prev = newNode;
        }else{
           printf("Data Not Found\nInserting At Last\n");
           free(newNode);
           CreateLL(data);
        }
    }
}
void DeleteAtLast(){
    if(!head){
        printf("No Linked List Find, Can't Delete Any Element\n");
    }else if(head->next == head){
        free(head);
        head = NULL;
        tail = NULL;
    }else{
        head->prev = tail->prev;
        tail->prev->next = head;
        free(tail);
        tail = head->prev;
    }
}
void Display(){
    if(!head){
        printf("No Linked List Find, Can't Display\n");
        return;
    }
    DCircularLL *current = head;
    do{
        printf("%d ",current->data);
        current = current->next;
    }while(current!=head);

    printf("\nIn Reverse Order\n");
    current = tail;
    do{
        printf("%d ",current->data);
        current = current->prev;
    }while(current!=tail);
    printf("\n");
}
