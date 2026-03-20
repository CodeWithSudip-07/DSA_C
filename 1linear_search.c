#include<stdio.h>

int linearsearch(int arr[],int size,int element){
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]={45,69,12,751,42,0,15,8};
    int size= sizeof(arr)/sizeof(int);
    int element=2;
    int searchindex=linearsearch(arr,size,element);
    printf("The element %d is found in index %d\n",element,searchindex);
    return 0;
}