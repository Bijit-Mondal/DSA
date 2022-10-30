#include<stdio.h>
#define MAX_QUEUE_SIZE 5
int queue[MAX_QUEUE_SIZE];
int front=-1,rear=-1;
void enqueueAtRear(int data){
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
void enqueueAtFront(int data){
    if(front == -1 && rear == -1){
        queue[++front] = data;
        rear = front;
    }else if(((rear+1)%MAX_QUEUE_SIZE) == front){
        printf("Queue is full\n");
    }else{
        if(front == 0){
            front = MAX_QUEUE_SIZE -1;
        }else{
            front = front - 1;
        }
        queue[front] = data;;
    }
}
void dequeueAtFront(){
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
void dequeueAtRear(){
    if(front==-1&&rear==-1){
        printf("Queue is empty");
    }else if(front == rear){
        front = -1;
        rear = -1;
    }else{
        printf("dequeue\n");
        if(rear == 0){
            rear = MAX_QUEUE_SIZE -1;
        }else{
            rear--;
        }
    }
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
        printf("1 -> Enqueue At Rear\n2 -> Dequeue At Front\n3 -> Display\n4 -> Enqueue At Front\n5->Dequeue At Rear\n-1 -> Quit\n");
        int option;
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the data to enqueue ");
                scanf("%d",&data);
                enqueueAtRear(data);
                break;
            case 2:
                dequeueAtFront();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter the data to enqueue ");
                scanf("%d",&data);
                enqueueAtFront(data);
                break;
            case 5:
                dequeueAtRear();
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

