#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX_SIZE 100
typedef struct queue
{
    int data;
    struct queue *next;
}queue;

queue *front = NULL;
queue *rear = NULL;
int size = 0;
int ran(){
    int i = rand()%30;
    int k = (i*rand())%30;
    if(i<(i*2)%k && (i*2)<=100 && i>0){
        return i*2+rand();
    }else if(i>90){
        return (i*2)%k;
    }else{
        return i*23/k;
    }
}
void enqueue(int data){
    //sleep(1);
    if(front == NULL && rear == NULL){
        queue *newQ = (queue*)malloc(sizeof(queue));
        newQ->data = data;
        newQ->next = NULL;
        ++size;
        front = newQ;
        rear = newQ;
        printf("Enqueued - %d\n",rear->data);
    }else if(size == MAX_SIZE){
        printf("Queue is full\n");
    }else{
        queue *newQ = (queue*)malloc(sizeof(queue));
        newQ->data = data;
        newQ->next = NULL;
        rear->next = newQ;
        rear = newQ;
        ++size;
        printf("Enqueued - %d\n",rear->data);
    }
}
void dequeue(){
    //sleep(1);
    if((!front)&& (!rear)){
        printf("Queue is empty\n");
    }else if(front == rear){
        printf("Dequeued : %d\n",front->data);
        free(front);
        front = NULL;
        rear = NULL;
        --size;
    }else{
        printf("Dequeued : %d\n",front->data);
        queue *RIPQ = front;
        front = front->next;
        free(RIPQ);
        --size;
    }
}
// void display(){
//     queue *current = front;
//     while(current){
//         printf("%d\t",current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

int main(){
    while(size<MAX_SIZE){
        for(int i=0;i<(rand()%30);i++){
            enqueue(abs(rand()%30));
        }
        for(int i=0;i<(rand()%10);i++){
            dequeue();
        }
    }
    return 0;
}
