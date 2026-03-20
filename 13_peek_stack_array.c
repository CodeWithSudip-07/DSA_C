#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
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
    }
    else{
        int val= ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
//peek operation is udes to printing the value at position i in the stack(here position strat fro 1)
//stack using array
int peek(struct stack* ptr,int i){
    int arrayInd = ptr->top - i + 1; 
    if(arrayInd< 0){
        printf("Invalid position!\n");
        return -1;
    }
    else{
        return ptr->arr[arrayInd];
    }
}
// Stack Top operation
int stackTop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return -1;
    }
    return s->arr[s->top];
}

// Stack Bottom operation
int stackBottom(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return -1;
    }
    return s->arr[0];
}

// Display stack
void display(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack Elements (Top to Bottom):\n");
    for(int i = s->top; i >= 0; i--){
        printf("%d\n", s->arr[i]);
    }
}

int main(){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=16;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    printf("stack is sucessfully created...\n");

    push(sp,10);
    push(sp,58);
    push(sp,89);
    push(sp,49);
    push(sp,410);
    push(sp,140);
    push(sp,4); 
    
    //printing values from the stack
    for(int j=1; j<=sp->top+1; j++){
        printf("The value at postion %d is: %d\n",j , peek(sp,j));
    }
    // printf("stacktop is: %d\n",stackTop(sp));
    // printf("stackbottom is: %d\n",stackBottom(sp));
    display(sp);

    return 0;
}