#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value){
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=value;
    n->left=NULL;
    n->right=NULL;
}

struct node* search_In_BST(struct node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(key<root->data){
        return search_In_BST(root->left,key);
    }
    else{
        return search_In_BST(root->right,key);
    }
}

int main(){
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4 
    struct node* p=createNode(5);
    struct node* p1=createNode(3);
    struct node* p2=createNode(6);
    struct node* p3=createNode(1);
    struct node* p4=createNode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;


    struct node* n=search_In_BST(p,4);
    if(n!=NULL){
        printf("found: %d",n->data);
    }
    else{
        printf("NOT found");
    }

    return 0;
}