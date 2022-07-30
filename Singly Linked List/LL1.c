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
void InsertAtBeginning(int data){
    if(head==NULL){
        return;
    }
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->next = head;
    tmp->data = data;
    head = tmp;
}
void InsertBefore(int data, int find){
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    node *ttm = head;
    if(head ==NULL){
        return;
    }
    else if(head->next == NULL||head->data == find){
        InsertAtBeginning(data);
    }
    else{
        node *prevtmp = head;
        while(ttm->next != NULL && find!=ttm->data){
            prevtmp = ttm;
            ttm = ttm->next;
        }
        prevtmp->next = tmp;
        tmp->next = ttm;
        tmp->data = data;
    }
}
void InsertAfter(int data, int find){
    if(head == NULL){
        return;
    }
    if(head->next == NULL && head->data == find){
        CreateAndInsertAtEnd(data);
    }
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    node *ttm = head;
    node *nexttmp = head;
    while(ttm->next!=NULL && find!=ttm->data){
        ttm = ttm->next;
        nexttmp = ttm->next;
    }
    ttm->next = tmp;
    tmp->data = data;
    tmp->next = nexttmp;   
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
void DeleteBeg(){
    node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
}
void DeleteEnd(){
    node *ptr, *preptr;
    ptr = head;
    while(ptr->next != NULL){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
}
void DeleteList(){
    node *current;
    if(head != NULL){
        current = head;
        while(current != NULL){
            printf("%d\t is going to be deleted\n",current->data);
            node *tmp;
            tmp = current->next;
            free(current);
            current = tmp;
        }
    }
}
int main(){
    printf("Enter the first node in the list ");
    int data,key;
    scanf("%d",&data);
    CreateAndInsertAtEnd(data);
    int flag=1;
    while(flag){
        int option;
            printf("Enter 1 for insert at end\nEnter 2 for insert at beginning\nEnter 3 for insert before some element\nEnter 4 for insert after some element\nEnter 5 for display\nEnter 6 for delete at start\nEnter 7 for delete at end\nEnter 8 for delete the entire list\nEnter -1 for exit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the data you wanna insert ");
                scanf("%d",&data);
                CreateAndInsertAtEnd(data);
                break;
            case 2:
                printf("Enter the data you wanna insert ");
                scanf("%d",&data);
                InsertAtBeginning(data);
                break;
            case 3:
                printf("Enter the data you wanna insert ");
                scanf("%d",&data);
                printf("Enter the key value ");
                scanf("%d",&key);
                InsertBefore(data,key);
                break;
            case 4:
                printf("Enter the data you wanna insert ");
                scanf("%d",&data);
                printf("Enter the key value ");
                scanf("%d",&key);
                InsertAfter(data,key);
                break;
            case 5:
                display();
                break;
            case 6:
                DeleteBeg();
                break;
            case 7:
                DeleteEnd();
                break;
            case 8:
                DeleteList();
                break;
            case -1:
                flag=0;
                break;
            default:
                printf("Take Deep Breath...");
        }
    }
    return 0;
}

