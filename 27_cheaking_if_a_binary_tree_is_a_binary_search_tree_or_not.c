#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* creation(int value){
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=value;
    n->left= NULL;
    n->right= NULL;
    return n;
}

void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int isBST(struct node* root){
    static struct node* prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main(){
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4 
    struct node* p=creation(5);
    struct node* p1=creation(3);
    struct node* p2=creation(6);
    struct node* p3=creation(1);
    struct node* p4=creation(4);

    p->left=p1;
    p->right=p2;

    p1->left=p3;
    p1->right=p4;

    inOrder(p);
    printf("\n");
    if(isBST(p)){
        printf("This is a bst" );
    }
    else{
        printf("This is not a bst");
    }



    return 0;
}