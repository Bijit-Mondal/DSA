#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int data){
    if(rear == MAX-1){
        printf("Can't enqueue\n");
    }
    else if(rear == -1 && front == -1){
        queue[++rear] = data;
        front = rear;
    }else{
        queue[++rear]=data;
    }
}
void dequeue(){
    if(front == rear && rear == MAX-1){
        front = -1;
        rear = -1;
        printf("\n-----------------Reinitialized--------------------\n");
    }else if(front<=rear){
        front++;
    }else{
        printf("Can't dequeue\n");
    }
}
void display(){
    if(front == -1)
        printf("Empty queue");
    else{
        for(int i = front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main(){
    int data,flag=1;
    while(flag){
        printf("1 -> Enqueue\n2 -> Dequeue\n3 -> Display\n-1 -> Exit\n ");
        int option;
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the data you wanna queue: ");
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
                flag = 0;
                break;
            default:
                printf("Watch!\n");
                break;
        }
    }
    return 0;
}

