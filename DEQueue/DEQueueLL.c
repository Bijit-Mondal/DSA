#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef struct Queue{
    int data;
    struct Queue* next;
}Queue;

Queue *front = NULL;
Queue *rear = NULL;
int size = 0;
void enqueueAtRear(int data){
    if(front == NULL && rear == NULL){
        Queue *queue = (Queue *) malloc(sizeof(Queue));
        queue->data = data;
        queue->next = NULL;
        ++size;
        front = queue;
        rear = queue;
    }else if(size == MAX_QUEUE_SIZE){
        printf("Queue is full.\n");
    }else{
        Queue *queue = (Queue *) malloc(sizeof(Queue));
        queue->data = data;
        queue->next = NULL;
        rear->next = queue;
        rear = queue;
        ++size;
    }
}
void enqueueAtFront(int data){
    if(front == NULL && rear == NULL){
        enqueueAtRear(data);
    }else if(size == MAX_QUEUE_SIZE){
        printf("Queue is full.\n");
    }else{
        Queue *queue = (Queue *) malloc(sizeof(Queue));
        queue->data = data;
        queue->next = front;
        front = queue;
        ++size;
    }
}
void dequeueAtFront(){
    if((!front) && (!rear)){
        printf("Queue is empty\n");
    }else if(front == rear){
        printf("Dequeue : %d\n",front->data);
        free(front);
        front = NULL;
        rear = NULL;
        --size;
    }else{
        printf("Dequeue : %d\n",front->data);
        Queue *RIPqueue = front;
        front = front->next;
        free(RIPqueue);
        --size;
    }
}
void dequeueAtRear(){
    if((!front) && (!rear)){
        printf("Queue is empty\n");
    }else if(front == rear){
        printf("Dequeue : %d\n",rear->data);
        free(rear);
        rear = NULL;
        front = NULL;
        --size;
    }else{
        printf("Dequeue : %d\n",rear->data);
        Queue *RIPqueue = rear;
        Queue *present = front;
        while(present->next!=RIPqueue){
            present = present->next;
        }
        present->next = NULL;
        rear = present;
        free(RIPqueue);
        --size;
    }
}
void display(){
    Queue *queue = front;
    while(queue){
        printf("%d\t",queue->data);
        queue = queue->next;
    }
    printf("\n");
}
int main(){
    int flag = 1, data;
    while(flag){
        printf("1 -> Enqueue at rear\n2 -> Enqueue at front\n3 -> Dequeue at front\n4 -> Dequeue at rear\n5 -> Display\n-1 ->Exit\n");
        int option;
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the data to enqueue ");
                scanf("%d",&data);
                enqueueAtRear(data);
                break;
            case 2:
                printf("Enter the data to enqueue ");
                scanf("%d",&data);
                enqueueAtFront(data);
                break;
            case 3:
                dequeueAtFront();
                break;
            case 4:
                dequeueAtRear();
                break;
            case 5:
                display();
                break;
            case -1:
                flag = 0;
                break;
        }
    }
    return 0;
}

