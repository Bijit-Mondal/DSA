#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
node *HEAD = NULL;
void CreateAndInsertAtEnd(int data){
    node *tmp = (node*) malloc(sizeof(node));
    tmp->data = data;
    if(HEAD == NULL){
        HEAD = tmp;
        tmp->prev = NULL;
    }else{
       node *current = HEAD;
       while(current->next){
           current = current->next;
       }
       current->next = tmp;
       tmp->prev = current;
       tmp->next = NULL;
    }
}
void InsertAtBeginning(int data){
    if(HEAD == NULL){
        return;
    }
    node *tmp = (node*) malloc(sizeof(node));
    tmp->data = data;
    tmp->next = HEAD;
    tmp->prev = NULL;
    HEAD->prev = tmp;
    HEAD = tmp;
}
void InsertAfter(int data,int find){
    if(HEAD == NULL){
        return;
    }
    else{
        node *tmp = (node*) malloc(sizeof(node));
        tmp->data = data;
        node *current = HEAD;
        while(current->next && find!=current->data){
            current = current->next;
        }
        tmp->next = current->next;
        tmp->prev = current;
        if(current->next){
            current->next->prev =tmp;
        }
        current->next = tmp;
    }
}
void InsertBefore(int data,int find){
    node *tmp = (node*) malloc(sizeof(node));
    tmp->data = data;
    if(HEAD == NULL){
        return;
    }
    else if(HEAD->data == find){
        InsertAtBeginning(data);
    }else{
        node *current = HEAD;
        while(current->next!=NULL && find!=current->data){
            current = current->next;
        }
        tmp->next = current;
        current->prev->next = tmp;
        tmp->prev = current->prev;
        current->prev = tmp;
    }
}
void Display(){
    node *current = HEAD;
    node *prevCur;
    while(current){
        printf("%d ", current->data);
        prevCur = current;
        current = current->next;
    }
    printf("\n");
    printf("Reversing Order \n");
    do{
        printf("%d ",prevCur->data);
        prevCur = prevCur->prev;
    }while(prevCur);
    printf("\n");
}
int main(){
    CreateAndInsertAtEnd(10);
    CreateAndInsertAtEnd(20);
    CreateAndInsertAtEnd(23);
    CreateAndInsertAtEnd(24);
    InsertAtBeginning(8);
    InsertAfter(34,23);
    InsertAfter(29,24);
    InsertAfter(11,8);
    Display();

    InsertBefore(40,29);
    InsertBefore(1,8);
    Display();
    return 0;
}

