#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};
int height(struct node* node){
    if(node == NULL){
        return 0;
    }else{
        int lheight = height(node->left);
        int rheight = height(node->right);
        //use the larger one
        return rheight>lheight?(rheight+1):(lheight+1);
    }
}
void printCurrentLevel(struct node* root,int level){
    if(!root){
        return;
    }
    if(level == 1){
        printf("%d ",root->item);
    }else if(level > 1){
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}
void printLevelOrder(struct node* root) {
    int h = height(root);
    int i;
    for(i=1;i<=h;i++){
        printCurrentLevel(root,i);
    }
}

// Create a new Node
struct node* createNode(int value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

int main() {
  struct node* root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);
  printLevelOrder(root); 
}