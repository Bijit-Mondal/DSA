#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
typedef struct queue{
    int data;
    struct queue* next;
}queue;
queue *front = NULL;
queue *rear = NULL;
int size = 0;
void enqueue(int data){
    if(size>=MAX_SIZE){
        printf("Queue is full!\n");
    }else if(front == NULL && rear == NULL){
        queue *Q = (queue*) malloc(sizeof(queue));
        Q->data = data;
        Q->next = NULL;
        front = Q;
        rear = Q;
        ++size;
    }else if() 
}
void dequeue(){

}
void display(){

}
int main(){
    return 0;
}

