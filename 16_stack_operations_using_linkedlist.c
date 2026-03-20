// peek , stacktop, stackbottom

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top= NULL;

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
//stack using linked list
int peek(int position){
    struct node *ptr= top;
    for(int i=0;i<position-1 && ptr!=NULL;i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }

}
int stacktop(struct node* top){
    return top->data;
}

int stackbottom(struct node *top){
    if(isEmpty(top)){
        printf("stack is empty!\n");
        return -1;
    }
    else{
        struct node *p=top;
        while(p->next!=NULL){
            p=p->next;
        }
        return p->data;
    }
}


int main(){
    top=push(top,15);
    top=push(top,5);
    top=push(top,1);
    top=push(top,150);
    LinkedListTraversal(top);

    for(int i=1;i<=4;i++){
        printf("The element of postion %d is %d\n",i,peek(i));
    }
    int st=stacktop(top);
    printf("%d",st);
    printf("stackbottom: %d\n",stackbottom(top));

    return 0;
}