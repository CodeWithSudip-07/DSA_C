#include <stdio.h>

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[],int n){
    int indexOfMin,temp;
    for(int i=0; i<n-1;i++){ //loop for no. of passes
        indexOfMin=i;

        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[indexOfMin]){
                indexOfMin = j;
            }
        }
        
        temp=arr[i];
        arr[i]=arr[indexOfMin];
        arr[indexOfMin]=temp;
    }

}

int main(){

    int arr[]={56,78,586,11,24,36,48,12};
    int n =sizeof(arr)/sizeof(int);

    printArray(arr,n);
    selection_sort(arr,n);
    printArray(arr,n);
    return 0;
}