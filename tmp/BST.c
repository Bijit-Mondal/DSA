#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *right, *left;
    int data;
}node;
node* addNode(int data,node *root){
    if(!root){
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }else{
        if(root->data < data){
            root->right = addNode(data,root->right);
        }else if(root->data > data){
            root->left = addNode(data,root->left);
        }
    }
    return root;
}
int main(){
    return 0;
}

