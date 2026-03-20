#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    return (ptr->top == -1);
}

int isFull(struct stack *ptr){
    return (ptr->top == ptr->size - 1);
}

void push(struct stack *ptr, int value){
    if(isFull(ptr)){
        printf("Stack overflow! The value %d is not inserted\n", value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow! Cannot pop element\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// Display stack
void display(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (Top to Bottom):\n");
    for(int i = ptr->top; i >= 0; i--){
        printf("%d\n", ptr->arr[i]);
    }
}

// Reverse stack using additional stack
void reverseStack(struct stack *s1){
    struct stack *s2 = (struct stack *)malloc(sizeof(struct stack));
    s2->size = s1->size;
    s2->top = -1;
    s2->arr = (int *)malloc(s2->size * sizeof(int));

    // Pop from s1 and push into s2
    while(!isEmpty(s1)){
        push(s2, pop(s1));
    }

    // Now copy s2 to s1 WITHOUT reversing again
    s1->top=s2->top;
    for(int i=0;i<=s2->top;i++){
        s1->arr[i]=s2->arr[i];
    }

    free(s2->arr);
    free(s2);
}

int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 6;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("Stack is successfully created...\n");

    push(sp,10);
    push(sp,58);
    push(sp,89);
    push(sp,49);
    push(sp,410);
    push(sp,140);

    printf("\nBefore Reversing:\n");
    display(sp);

    reverseStack(sp);

    printf("\nAfter Reversing:\n");
    display(sp);

    free(sp->arr);
    free(sp);

    return 0;
}