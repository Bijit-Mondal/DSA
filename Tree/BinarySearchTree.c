#include<stdio.h>
#include<stdlib.h>
typedef struct BST{
    int data;
    struct BST* right;
    struct BST* left;
}node;
node* addNode(node *rt,int data){
    if(rt == NULL){
        rt = (node*) malloc(sizeof(node));
        rt->data = data;
        rt->right = NULL;
        rt->left = NULL;
        return rt;
    }else if(data < rt->data){
        rt->left = addNode(rt->left,data);
    }else{
        rt->right = addNode(rt->right,data);
    }
    return rt;
}
void inorder(node *nd){
    if(nd == NULL){
        return;
    }
    inorder(nd->left);
    printf("%d ",nd->data);
    inorder(nd->right);
}
int getRightMin(node *root){
    node *tmp = root;
    while(tmp->left != NULL){
        tmp = tmp->left;
    }
    return tmp->data;
}
node* delete(node *root,int key){
    if(!root){
        return NULL;
    }
    if(root->data < key){
        root->right = delete(root->right,key);
    }else if(root->data > key){
        root->left = delete(root->left,key);
    }else{
        //when the element is found
        //case 1: leaf node deletion
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }
        //case 2: right child exists
        if(root->left == NULL){
            node *tmp = root->right;
            free(root);
            return tmp;
        }else if(root->right == NULL){//case 3: left child exists
            node *tmp = root->left;
            free(root);
            return tmp;
        }else{
            int rightMin = getRightMin(root->right);
            root->data = rightMin;
            root->right = delete(root->right,rightMin);
        }

    }
    return root;
}
node* search(node *root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }else if(root->data > key){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}
int main(){
    node *root = NULL;
    printf("Enter values to insert, enter -1 to exit\n");
    int data;
    scanf("%d",&data);
    while(data!=-1){
        root = addNode(root,data);
        scanf("%d",&data);
    }
    printf("Enter a element to search for\n");
    int key;
    scanf("%d",&key);
    if(search(root,key)){
        printf("The item was found\n");
    }else{
        printf("The item was not found\n");
    }
    printf("Inorder : ");
    inorder(root);
    printf("\nEnter a element to delete\n");
    scanf("%d",&key);
    delete(root,key);
    inorder(root);
    return 0;
}
