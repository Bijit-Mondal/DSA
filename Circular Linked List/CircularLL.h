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

void DeleteAtFirst(){
    if(!major){
        return;
    }
    CircularLL *RIPNode = major;
    major = major->next;
    minor->next = major;
    free(RIPNode);
}
void DeleteAtLast(){
    if(!major){
        return;
    }
    CircularLL *RIPNode = minor;
    CircularLL *OldNode = major;
    while(OldNode->next != RIPNode){
        OldNode = OldNode->next;
    }
    OldNode->next = major;
    minor = OldNode;
    free(RIPNode);
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