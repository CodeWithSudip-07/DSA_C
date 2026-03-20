#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front= NULL;
struct node *rear= NULL;

void LinkedListTraversal(struct node *ptr){
    printf("Printing the element of the linked list......\n");
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

void enQueue(int val){
    struct node *n =(struct node *)malloc(sizeof(struct node));
    if(n==NULL){
        printf("Queue full!\n");
    }
    else{
        n->data=val;
        n->next=NULL;
        if(front==NULL){
            front=rear=n;
        }
        else{
            rear->next=n;
            rear=n;
        }
    }

}
// int deQueue(){
//     int val= -1;
//     struct node *ptr =front;
//     if(front==NULL){
//         printf("Queue is empty\n");
//     }
//     else{
//         front=front->next;
//         val=ptr->data;
//         free(ptr);
//     }
//     return val;
// }
int deQueue(){
    int val = -1;
    struct node *ptr = front;

    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        front = front->next;

        // If queue becomes empty after deletion
        if(front == NULL){
            rear = NULL;
        }

        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main(){
    printf("Dequeuing element %d\n", deQueue());
    enQueue(34);
    enQueue(4);
    enQueue(7);
    enQueue(17);
    LinkedListTraversal(front);
    printf("Dequeuing element %d\n", deQueue());
    printf("Dequeuing element %d\n", deQueue());
    printf("Dequeuing element %d\n", deQueue());
    // printf("Dequeuing element %d\n", deQueue());
    LinkedListTraversal(front);
    return 0;
}