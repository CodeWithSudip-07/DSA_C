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

int main(){
    // struct stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr=(int *)malloc(s.size*sizeof(int));

    struct stack *s;
    s->size=6;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));

    //Manually push an element into stack
    s->arr[0]=7;
    s->top++;
    // s->arr[1]=70;
    // s->top++;
    // s->arr[2]=71;
    // s->top++;
    // s->arr[3]=17;
    // s->top++;
    // s->arr[4]=27;
    // s->top++;
    // s->arr[5]=37;
    // s->top++;

    //cheak is the stack is empty or not
    // if(isEmpty(s)){
    //     printf("The stack is Empty...");
    // }
    // else{
    //     printf("The stack is Not Empty...");
    // }

    //cheak is the stack is empty or not
    if(isFull(s)){
        printf("The stack is Full...");
    }
    else{
        printf("The stack is Not Full...");
    }
    return 0;
}