#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr, int value){
    if(isFull(ptr)){
        printf("Stack overflow! the value: %d is not inserted\n",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]= value;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stackunderflow! cannot pop any element\n");
        return -1;
    }
    else{
        int val= ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void display(struct stack *sp){
    for(int i=sp->top;i>=0;i--){
        printf("%d\n",sp->arr[i]);
    }
    printf("\n");
}
int isFullq(struct queue *q){
    if(q->rear==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmptyq(struct queue *q){
    if(q->front==q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

void enQueue(struct queue* q,int val){
    if(isFullq(q)){
        printf("queue is full");
    }
    else{
        q->rear++;
        q->arr[q->rear]=val;
    }
}
int deQueue(struct queue* q){
    if(isEmptyq(q)){
        printf("queue is empty");
    }
    else{
        
        q->front++;
        int val=q->arr[q->front];
        return val;
    }
}

void reverse(struct stack* sp){
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->front=q->rear=-1;
    q->size=100;
    q->arr=(int*)malloc(q->size*sizeof(int));
    while(!isEmpty(sp)){
        enQueue(q,pop(sp));
    }

    while(!isEmptyq(q)){
        push(sp,deQueue(q));
    }
    
    free(q->arr);
    free(q);

}
int main(){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(int*)malloc(sp->size*sizeof(int));

    push(sp,50);
    push(sp,501);
    push(sp,51);
    push(sp,1);
    push(sp,2);
    push(sp,3);
    
    display(sp);

    reverse(sp);

    display(sp);
    return 0;
}

