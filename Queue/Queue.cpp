#include<iostream>
using namespace std;
#define MAX_SIZE 5
int q[MAX_SIZE];
int front=-1;
int rear=-1;
void enqueue(int data){
    if(rear<(MAX_SIZE-1)){
        if(rear == -1){
            q[++rear] = data;
            front = 0;
        }else{
            q[++rear]=data;
        }
    }else{
        cout <<"Data wasn't queued"<<endl;
    }
}
void dequeue(){
    if((rear == front) && (front== (MAX_SIZE-1))){
        rear = -1;
        front = -1;
    }
    else if(front<=rear){
        front++;
    }
}
void display(){
    if(front<=rear && rear!=-1){
        for(int i=front;i<=rear;i++){
            cout << q[i] << " ";
        }
        cout<<endl;
    }else{
        cout<<"Couldn't Display"<<endl;
    }
}
int main(){
    int flag=1,data;
    while(flag){
        cout<<"Enter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter -1 for quit\n";
        int option;
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            cout<<"Enter the data ";
            cin>>data;
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case -1:
            flag =0;
            break;
        default:
            cout<<"Are u sleeping"<<endl;
            break;
        }
    }
}
