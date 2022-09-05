#include<stdio.h>
#define MAX_QUEUE_SIZE 5
int queue[MAX_QUEUE_SIZE];
int front=-1,rear=-1;
void enqueue(int data){
    if(front == -1 && rear == -1){
        queue[++rear] = data;
        front = rear;
    }else if(((rear+1)%MAX_QUEUE_SIZE)==front){
        printf("Queue is full\n");
    }else{
        rear = (rear+1)%MAX_QUEUE_SIZE;
        queue[rear] = data;
    }
    printf("front = %d\trear = %d\n", front, rear);
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("Queue is empty");
    }else if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        printf("dequeue\n");
        front = (front+1)%MAX_QUEUE_SIZE;
    }
    printf("front = %d\trear = %d\n", front, rear);
}
void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }else{
        for(int i = front;i!=rear;i=(i+1)%MAX_QUEUE_SIZE){
            printf("%d\t",queue[i]);
        }
        printf("%d\t",queue[rear]);
        printf("\n");
    }
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

