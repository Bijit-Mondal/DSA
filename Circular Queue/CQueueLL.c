#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
typedef struct queue
{
    int data;
    struct queue *next;
}queue;

queue *front = NULL;
queue *rear = NULL;
int size = 0;

void enqueue(int data){
    if(front == NULL && rear == NULL){
        queue *newQ = (queue*)malloc(sizeof(queue));
        newQ->data = data;
        newQ->next = NULL;
        ++size;
        front = newQ;
        rear = newQ;
    }else if(size == MAX_SIZE){
        printf("Queue is full\n");
    }else{
        queue *newQ = (queue*)malloc(sizeof(queue));
        newQ->data = data;
        newQ->next = NULL;
        rear->next = newQ;
        rear = newQ;
        ++size;
    }
}
void dequeue(){
    if((!front)&& (!rear)){
        printf("Queue is empty\n");
    }else if(front == rear){
        printf("Dequeue : %d\n",front->data);
        free(front);
        front = NULL;
        rear = NULL;
        --size;
    }else{
        printf("Dequeue : %d\n",front->data);
        queue *RIPQ = front;
        front = front->next;
        free(RIPQ);
        --size;
    }
}
void display(){
    queue *current = front;
    while(current){
        printf("%d\t",current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    int flag=1,data;
    while(flag){
        printf("1 -> Enqueue\n2 -> Dequeue\n3 -> Display\n-1 -> Quit\n");
        int option;
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the data to enqueue ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case -1:
                flag=0;
                break;
            default:
                printf("Focus!!\n");
                break;
        }
    }
    return 0;
}
