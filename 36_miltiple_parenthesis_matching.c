#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
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

void push(struct stack *ptr, char value){
    if(isFull(ptr)){
        printf("Stack overflow! the value: %d is not inserted\n",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]= value;
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stackunderflow! cannot pop any element\n");
    }
    else{
        char val= ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int matched(char a, char b){
    if(a=='(' &&b ==')'){
        return 1;
    }
    if(a=='{' &&b =='}'){
        return 1;
    }
    if(a=='[' &&b ==']'){
        return 1;
    }
    return 0;
}

int parenthesisMatch(char *exp){
    // Create and initialize the stack
    struct stack* sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));
    char poped_val;
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('|| exp[i]=='{'||exp[i]=='['){
            push(sp,exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}'||exp[i]==']'){
            if(isEmpty(sp)){
                return 0;
            }
            else{
                poped_val=pop(sp);
                if(!matched(poped_val,exp[i])){
                    return 0;
                }
            }

        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    
    char *exp= "[[4-6]((8){(9-8])})";
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matched");
    }
    else{
        printf("The parenthesis is not matched");
    }

    return 0;
}