#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Insert at Front
void insertFront(int value){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = value;

    if(front == NULL){   // If queue is empty
        front = rear = ptr;
        ptr->next = NULL;
    }
    else{
        ptr->next = front;
        front = ptr;
    }
}

// Insert at Rear
void insertRear(int value){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;

    if(rear == NULL){   // If queue is empty
        front = rear = ptr;
    }
    else{
        rear->next = ptr;
        rear = ptr;
    }
}

// Delete from Front
void deleteFront(){
    if(front == NULL){
        printf("Deque is empty\n");
        return;
    }

    struct node* temp = front;
    printf("Deleted from Front: %d\n", front->data);

    front = front->next;

    if(front == NULL)   // If list becomes empty
        rear = NULL;

    free(temp);
}

// Delete from Rear
void deleteRear(){
    if(rear == NULL){
        printf("Deque is empty\n");
        return;
    }

    struct node* temp = rear;

    if(front == rear){   // Only one element
        printf("Deleted from Rear: %d\n", rear->data);
        free(rear);
        front = rear = NULL;
        return;
    }

    struct node* p = front;
    while(p->next != rear){
        p = p->next;
    }

    printf("Deleted from Rear: %d\n", rear->data);
    p->next = NULL;
    rear = p;

    free(temp);
}

// Display Deque
void display(){
    if(front == NULL){
        printf("Deque is empty\n");
        return;
    }

    struct node* ptr = front;
    printf("Deque elements: ");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){

    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertRear(30);

    display();

    // deleteFront();
    deleteRear();

    display();

    return 0;
}