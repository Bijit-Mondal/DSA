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
}
