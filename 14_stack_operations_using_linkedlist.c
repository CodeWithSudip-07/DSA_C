
// isEmpty, isFull, pop, push
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node *ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

int isEmpty(struct node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct node *top){
    struct node *p=(struct node *)malloc(sizeof(struct node));
    if(p ==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct node *push(struct node *top, int x){
    if(isFull(top)){
        printf("Stack overflow! data can't be inserted...\n");
    }
    else{
        struct node *n =(struct node*)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top=n;
        return top;
    }
}

int pop(struct node **top){
    
    if(isEmpty(*top)){
        printf("Stack underflow! no element is present for pop out....\n");
    }
    else{
        struct node* n=*top;
        *top=(*top)->next;
        int x= n->data;
        free(n);
        return x;
    }
}

int main(){
    struct node *top=NULL;
    top=push(top,45);
    top=push(top,5);
    top=push(top,4);
    top=push(top,405);
    LinkedListTraversal(top);
    int element= pop(&top);
    printf("The poped element is %d\n",element);
    LinkedListTraversal(top);

    return 0;
}