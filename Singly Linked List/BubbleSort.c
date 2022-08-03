#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node node;
node *head=NULL;
int length = 0;
void CreateAndInsertAtEnd(int data){
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = data;
    if(head==NULL){
        head = tmp;
    }
    else{
        node *ttm = head;
        while(ttm->next!=NULL){
            ttm = ttm->next;
        }
        ttm->next = tmp;
    }
    ++length;
}
void display(){
    if(head == NULL){
        return;
    }
    node *tmp;
    tmp = head;
    while(tmp != NULL){
        printf("%d\t",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
void BubbleSort(){
    node *lastNode=NULL;
    while(--length){
        node *current = head;
        node *nextCurrent = current->next;
        do{
            if(current->data>nextCurrent->data){
                int tmp = nextCurrent->data;
                nextCurrent->data = current->data;
                current->data = tmp;
            }
            current = nextCurrent;
            nextCurrent = nextCurrent->next;
        }while(nextCurrent!=lastNode);
        lastNode = current;
    }
}
int main(){
    CreateAndInsertAtEnd(120);
    CreateAndInsertAtEnd(10);
    CreateAndInsertAtEnd(150);
    CreateAndInsertAtEnd(300);
    CreateAndInsertAtEnd(12);
    display();
    BubbleSort();
    display();
}
