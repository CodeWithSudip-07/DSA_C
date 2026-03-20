#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct stack{
    int size;
    int top;
    int* arr;
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
// Function to evaluate postfix expression
int evaluate_postfix(char postfix[]){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(int*)malloc(sp->size*sizeof(int));

    int i=0,operend1,operend2,result;

    while(postfix[i]!='\0'){
        // If character is digit, push into stack
        if(isdigit(postfix[i])){
            push(sp,postfix[i]-'0'); // convert char to int
        }
        else{
            operend2=pop(sp);
            operend1=pop(sp);
            switch(postfix[i]){
                case '*':
                    result = operend1 * operend2;
                    break;
                case '/':
                    result = operend1 / operend2;
                    break;
                case '+':
                    result = operend1 + operend2;
                    break;
                case '-':
                    result = operend1 - operend2;
                    break;
            }
            push(sp,result);
        }
        i++;
    }
    return pop(sp);
}

int main(){

    char postfix[]="23*54*+9-";
    int result=evaluate_postfix(postfix);
    printf("the final result is: %d",result);

    return 0;
}