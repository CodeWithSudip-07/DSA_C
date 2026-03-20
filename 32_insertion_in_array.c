#include <stdio.h>

//Code for Traversal
void display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//Code for insrtion in array
int index_insertion(int arr[],int size, int element, int capacity, int index){
    if(size>=capacity){
        return -1;
    }
    for(int i=size-1; i>=index; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}


int main(){
    int arr[100]={7,8,12,27,88};
    int size= 5, element=5, index=5;
    display(arr,size);
    index_insertion(arr,size,element,100,index);
    size+=1;
    display(arr,size);
    return 0;
}