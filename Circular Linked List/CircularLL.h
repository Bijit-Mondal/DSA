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
        return;
    }
    CircularLL *newNode= (CircularLL*)malloc(sizeof(CircularLL));
    newNode->data = data;
    newNode->next = major;
    minor->next = newNode;
    major = newNode;
}
void InsertAtLast(int data){
    if(!major){
        return;
    }
    CreateLL(data);
}
void InsertAfter(int data,int key){
    CircularLL *NewNode= (CircularLL*)malloc(sizeof(CircularLL));
    NewNode->data = data;
    if(!major){
        return;
    }else if(minor->data == key){
        InsertAtLast(data);
    }else{
        CircularLL *present = major;
        while(present->next!=major && present->data!=key){
            present = present->next;
        }
        NewNode->next = present->next;
        present->next = NewNode;
    }
}
void InsertBefore(int data,int key){
    CircularLL *NewNode = (CircularLL*)malloc(sizeof(CircularLL));
    NewNode->data = data;
    if(!major){
        return;
    }else if(major->data == key){
        InsertAtBeg(data);
    }else{
        CircularLL *present = major;
        CircularLL *past = major;
        while(present->next!=major && present->data!=key){
            past = present;
            present = present->next;
        }
        past->next = NewNode;
        NewNode->next = present;
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
