#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int data;
    int priority;
    struct Queue* next;
}Queue;
Queue *front = NULL;
void Insert(Queue* queue){
    if(front == NULL || queue->priority < front->priority){
        queue->next = front;
        front = queue;
    }else{
        Queue *current = front;
        while(current->next!=NULL && current->next->priority <= queue->priority){
           current = current->next;
        }
        queue->next = current->next;
        current->next = queue;
    }
}
void Delete(){
    Queue* RIPqueue;
    if(front == NULL){
        printf("Queue is empty\n");
    }else{
        RIPqueue = front;
        printf("Deleted: %d\n",RIPqueue->data);
        front = front->next;
        free(RIPqueue);
    }
}
void display(){
    Queue *present = front;
    if(front == NULL){
        printf("Queue is empty\n");
    }else{
        printf("Priority Queue is\n");
        while(present!=NULL){
            printf("%d [priority - %d]\t",present->data, present->priority);
            present = present->next;
        }
        printf("\n");
    }
}
int main(){
    int flag=1,data,priority;
    while(flag){
        int option;
        printf("1 -> Insert\n2 -> Delete\n3 -> Display\n-1 -> Exit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Insert the data and priority respectively\n");
                scanf("%d",&data);
                scanf("%d",&priority);
                Queue *queue = (Queue*)malloc(sizeof(Queue));
                queue->data = data;
                queue->priority = priority;
                queue->next = NULL;
                Insert(queue);
                break;
            case 2:
                Delete();
                break;
            case 3:
                display();
                break;
            case -1:
                flag=0;
                break;
        }
    }
    return 0;
}

