#include <stdio.h>

void printArray(int arr[],int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void reverseArray(int arr[],int n){
    int temp,i;
    for(i=0;i<n/2;i++){
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
}

int main(){
    int arr[]={4,8,9,65,14,75,58};
    int len=sizeof(arr)/sizeof(int);
    printArray(arr,len);
    reverseArray(arr,len);
    printArray(arr,len);
}