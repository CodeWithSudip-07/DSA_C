#include <stdio.h>

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void bubblesort(int arr[], int n){
    int temp;
    for(int i=0;i<n-1;i++){ // loop for no. of passes
        for(int j=0;j<n-1-i;j++){// loop for no. of swaps
            if(arr[j]>arr[j+1]){
                temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int arr[]={45,69,78,14,23,56,75,44};
    int n= sizeof(arr)/sizeof(int);

    printArray(arr, n); //printing the array before sorting
    bubblesort(arr,n); //function to sort the array
    printArray(arr, n); //printing the array after sorting
    return 0;
}