#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node node;
node *head=NULL;
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
void Reverse(node *current,node *prevCurrent){
   if(!head) return; 
   else if(current->next==NULL){
       head = current;
       current->next = prevCurrent;
       return;
   }
   node *nextCurrent = current->next;

   current->next = prevCurrent;

   Reverse(nextCurrent, current);
}

int main(){
    CreateAndInsertAtEnd(10);
    CreateAndInsertAtEnd(12);
    CreateAndInsertAtEnd(15);
    CreateAndInsertAtEnd(30);
    CreateAndInsertAtEnd(120);
    display();
    Reverse(head,NULL);
    printf("\n----------------After Reverse-------------------------\n");
    display();
}
