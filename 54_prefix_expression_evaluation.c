#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
// Function to evaluate prefix expression
int prefix_evaluation(char prefix[]){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(int*)malloc(sp->size*sizeof(int));

    int len=strlen(prefix);
    
    int i, operend1, operend2, result;
    // Scan from right to left
    for(i=len-1; i>=0; i--){
        if(prefix[i]==' ')
            continue;
        if(isdigit(prefix[i])){
            push(sp,prefix[i] - '0');// convert char to int
        }
        else{

            operend1=pop(sp);
            operend2=pop(sp);
            
            switch(prefix[i]){
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
    }
    return pop(sp);
}

int main(){
    char prefix[]="-+9*263";
    int result = prefix_evaluation(prefix);

    printf("the result is: %d",result);
}