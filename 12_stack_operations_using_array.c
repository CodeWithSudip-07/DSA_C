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
        return -1;
    }
    else{
        int val= ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main(){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=6;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    printf("stack is sucessfully created...\n");

    printf("before pushing, Empty: %d\n",isEmpty(sp));
    printf("before pushing, Full: %d\n",isFull(sp));

    push(sp,10);
    push(sp,58);
    push(sp,89);
    push(sp,49);
    push(sp,410);
    push(sp,140); //--->insert 6 element
    push(sp,4); //stacke overflow after reaching 6 elements

    printf("After pushing, Empty: %d\n",isEmpty(sp));
    printf("After pushing, Full: %d\n",isFull(sp));

    printf("The element: %d is pop from the stack\n",pop(sp)); // LIFO-> last in first out 
    printf("The element: %d is pop from the stack\n",pop(sp));
    printf("The element: %d is pop from the stack\n",pop(sp));
    printf("The element: %d is pop from the stack\n",pop(sp));

    return 0;
}