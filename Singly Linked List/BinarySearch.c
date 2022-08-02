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
int getLen(node *hot){
    int len = 1;
    while(hot->next!=NULL){
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
        int midPos = (getLen(hot)/2)+1;
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
    // while(cold->next!=NULL){
    //     cold = cold->next;
    // }
    // bool found = false;
    // node *LukeWarm  = getMiddlePosition(hot,cold);
    // if(data == LukeWarm->data){
    //     printf("Your Data Was Found ");
    //     found = true;
    // }else if(data>LukeWarm->data){

    // }else if(data<LukeWarm->data){

    // }
    do{
        node *LukeWarm  = getMiddlePosition(hot,cold);
        if(LukeWarm == NULL){
            printf("Search Not Possible");
            return NULL;
        }
        if(LukeWarm->data == data){
            printf("Data Was Found\n");
            return LukeWarm;
        }else if(LukeWarm->data >data){
            cold = LukeWarm;
        }else{
            hot = LukeWarm->next;
        }
    }while(cold == NULL || cold!=hot);
}
int main(){
    CreateAndInsertAtEnd(10);
    CreateAndInsertAtEnd(20);
    CreateAndInsertAtEnd(30);
    CreateAndInsertAtEnd(40);
    CreateAndInsertAtEnd(50);
    Display();
    linearSearch(40);
    binarySearch(10);
}
