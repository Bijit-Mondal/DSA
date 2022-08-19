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
        if(current->data == data){
            tmp->next = current->next;
            tmp->prev = current;
            if(current->next){
                current->next->prev =tmp;
            }
            current->next = tmp;
        }
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
        if(current->data == find){
            tmp->next = current;
            current->prev->next = tmp;
            tmp->prev = current->prev;
            current->prev = tmp;
        }
    }
}
void Display(){
    if(!HEAD){
        printf("No linked list is created.\n");
        return;
    }
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
void DeleteAtBeg(){
    if(HEAD == NULL){
        return;
    }
    node *tmp = HEAD;
    HEAD = tmp->next;
    if(HEAD)
        HEAD->prev = NULL;
    free(tmp);
}
void DeleteAtLast(){
    if(HEAD == NULL){
        return;
    }
    node *current = HEAD;
    while(current->next){
        current = current->next;
    }
    if(current->prev!=NULL){
        current->prev->next = NULL;
    }else{
        HEAD = NULL;
    }
    free(current);

}
void Delete(int find){
    if(HEAD == NULL){
        return;
    }
    node *current = HEAD;
    if(HEAD->data == find){
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
void Reverse(){
    node *tmp = NULL;
    node *current = HEAD;
    while(current!=NULL){
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }
    if(tmp!=NULL){
        HEAD = tmp->prev;
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
            printf("Enter 1 for insert at end\nEnter 2 for insert at beginning\nEnter 3 for insert before some element\nEnter 4 for insert after some element\nEnter 5 for display\nEnter 6 for delete at start\nEnter 7 for delete at end\nEnter 8 for delete the entire list\nEnter 9 for Reverse\nEnter -1 for exit\n");
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
                Display();
                break;
            case 6:
                DeleteAtBeg();
                break;
            case 7:
                DeleteAtLast();
                break;
            case 8:
                printf("Enter the data you wanna delete ");
                scanf("%d",&data);
                Delete(data);
                break;
            case 9:
                Reverse();
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

