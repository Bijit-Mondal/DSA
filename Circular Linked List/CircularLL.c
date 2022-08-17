#include<stdio.h>
#include "CircularLL.h"
int main(){
    printf("Enter the first node in the list ");
    int data,key;
    scanf("%d",&data);
    CreateLL(data);
    int flag=1;
    while(flag){
        int option;
            printf("Enter 1 for insert at end\nEnter 2 for insert at beginning\nEnter 3 for insert before some element\nEnter 4 for insert after some element\nEnter 5 for display\nEnter 6 for delete at start\nEnter 7 for delete at end\nEnter -1 for exit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the data you wanna insert ");
                scanf("%d",&data);
                CreateLL(data);
                break;
            case 2:
                printf("Enter the data you wanna insert ");
                scanf("%d",&data);
                InsertAtBeg(data);
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
                DeleteAtFirst();
                break;
            case 7:
                DeleteAtLast();
                break;
            // case 8:
            //     DeleteList();
            //     break;
            case -1:
                flag=0;
                break;
            default:
                printf("Take Deep Breath...");
        }
    }
    return 0;
}
