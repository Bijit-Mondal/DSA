#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *HEAD=NULL;
void CreateAndInsertAtEnd(int data){
	node *newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	if(HEAD==NULL){
		HEAD = newNode;
	}
	else{
		node *tmp = HEAD;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
}
void Display(){
	if(HEAD == NULL){
		return;
	}
	node *current=HEAD;
	while(current!=NULL){
		printf("%d\t",current->data);
		current = current->next;
	}
	printf("\n");
}
void linearSearch(int data){
    printf("\n------------------------------------Linear Searching----------------------------------\n");
    node *current = HEAD;
    bool found = false;
    int i = 1;
    while(current->next!=NULL){
        if(current->data==data){
            found = true;
            printf("Your element was found on position %d \n",i);
            break;
        }else{
            current = current->next;
            i++;
        }
    }
    if(found == false){
        printf("Your Element Wan't Found\n");
    }
}
int getLen(node *hot,node *cold){
    int len = 1;
    while(hot->next!=cold){
        hot = hot->next;
        ++len;
    }
    return len;
}
node* getMiddlePosition(node* hot,node *cold){
    if(hot==NULL){
        return NULL;
    }else{
        int myIndex = 1;
        node *current = hot;
        int midPos = (getLen(hot,cold)/2)+1;
        while(myIndex<midPos){
            current = current->next;
            myIndex++;
        }
        return current;
    }
}
node* binarySearch(int data){
    printf("\n------------------------------------Binary Searching----------------------------------\n");
    node *hot = HEAD;
    node *cold = NULL;
    do{
        node *LukeWarm  = getMiddlePosition(hot,cold);
        if(LukeWarm == NULL){
            printf("Search Not Possible\n");
            return NULL;
        }
        if(LukeWarm->data == data){
            printf("Data Was Found\n");
            return LukeWarm;
        }else if(LukeWarm->data < data){
            hot = LukeWarm->next;
            printf("%d\n",hot->data);
        }else{
            cold = LukeWarm;
            printf("%d\n",cold->data);
        }
    }while(cold == NULL || cold!=hot);
    return NULL;
}
void SearchMenu(){
    printf("Enter 'L' or 'l' for perform Linear Search\nEnter 'B' or 'b' for perform Binary Search\n");
    char option;
    getchar();
    scanf("%c",&option);
    printf("Enter the Data to search for: ");
    int data;
    scanf("%d",&data);
    if(option=='l'||option=='L'){
        linearSearch(data);
    }else if(option=='b'||option=='B'){
        if(binarySearch(data)){
            printf("Data Was Found :)\n\n");
        }else{
            printf("Data Was Not Found :(\n\n");
        }
    }
}
int main(){
    printf("Enter the first Data Of The Node ");
    int data;
    scanf("%d",&data);
    CreateAndInsertAtEnd(data);
    printf("---------Main Menu---------\n");
    int flag = 1;
    while(flag){
        int option;
        printf("Enter 1 For Insert New Element\nEnter 2 For Show The Element's Present In The Array\nEnter 3 for search for a element\nEnter -1 for exit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the data you wanna insert ");
                scanf("%d",&data);
                CreateAndInsertAtEnd(data);
                break;
            case 2:
                Display();
                break;
            case 3:
                SearchMenu();
                break;
            case -1:
                flag = 0;
                break;
            default:
                printf("Focus!!!");
                break;
        }
    }
}
