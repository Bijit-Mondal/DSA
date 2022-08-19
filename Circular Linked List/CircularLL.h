#include<stdio.h>
#include<stdlib.h>
typedef struct CircularLL{
    int data;
    struct CircularLL *next;
}CircularLL;
CircularLL *major = NULL;
CircularLL *minor = NULL;
void CreateLL(int data){
    CircularLL *newNode = (CircularLL*)malloc(sizeof(CircularLL));
    newNode->data = data;
    if(!major){
        newNode->next = newNode;
        major = newNode;
        minor = newNode;
    }else{
        minor->next = newNode;
        newNode->next = major;
        minor = newNode;
    }
}
void InsertAtBeg(int data){
    if(!major){
        CreateLL(data);
    }
    CircularLL *newNode= (CircularLL*)malloc(sizeof(CircularLL));
    newNode->data = data;
    newNode->next = major;
    minor->next = newNode;
    major = newNode;
}
void InsertAtLast(int data){
    CreateLL(data);
}
void InsertAfter(int data,int key){
    CircularLL *NewNode= (CircularLL*)malloc(sizeof(CircularLL));
    NewNode->data = data;
    if(!major){
       printf("Circular Linked List Not Found\nCreating a New Linked List\n");
       CreateLL(data);
    }else if(minor->data == key){
        InsertAtLast(data);
    }else{
        CircularLL *present = major;
        while(present->next!=major && present->data!=key){
            present = present->next;
        }
        if(present->data == key){
            NewNode->next = present->next;
            present->next = NewNode;
        }else{
            printf("Data wasn't found\n");
        }
    }
}
void InsertBefore(int data,int key){
    CircularLL *NewNode = (CircularLL*)malloc(sizeof(CircularLL));
    NewNode->data = data;
    if(!major){
       printf("Circular Linked List Not Found\nCreating a New Linked List\n");
       CreateLL(data);
    }else if(major->data == key){
        InsertAtBeg(data);
    }else{
        CircularLL *present = major;
        CircularLL *past = major;
        while(present->next!=major && present->data!=key){
            past = present;
            present = present->next;
        }
        if(present->data == key){
            past->next = NewNode;
            NewNode->next = present;
        }else{
            printf("Item not found\n");
        }
    }
}
void DeleteAtFirst(){
    if(!major){
        return;
    }
    if(major == minor){
        CircularLL *RIPNode = major;
        free(RIPNode);
        major = NULL;
        minor = NULL;
    }else{
        CircularLL *RIPNode = major;
        major = major->next;
        minor->next = major;
        free(RIPNode);
    }
}
void DeleteAtLast(){
    if(!major){
        return;
    }
    if(major == minor){
        CircularLL *RIPNode = major;
        free(RIPNode);
        major = NULL;
        minor = NULL;
    }else{
        CircularLL *RIPNode = minor;
        CircularLL *OldNode = major;
        while(OldNode->next != RIPNode){
            OldNode = OldNode->next;
        }
        OldNode->next = major;
        minor = OldNode;
        free(RIPNode);
    }
}
void Delete(int data){
    if(major->data == data){
        DeleteAtFirst();
    }else if(minor->data == data){
        DeleteAtLast();
    }else{
        CircularLL *present = major;
        while(present->next!=minor && present->next->data!=data){
            present = present->next;
        }
        if(present->next->data == data){
            CircularLL *tmp = present->next;
            present->next = present->next->next;
            free(tmp);
        }else{
            printf("Data not found \n");
        }
    }
}
void Display(){
    if(!major){
        return;
    }
    CircularLL *present = major;
    do{
        printf("%d ",present->data);
        present = present->next;
    }while(present!=major);
    printf("\n");
}
