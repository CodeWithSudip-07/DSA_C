#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[],int low, int mid, int high){
    int i,j,k,B[100];
    i=low,
    j=mid+1;
    k=low;

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            B[k]=arr[i];
            i++;
            k++;
        }
        else{
            B[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        B[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high){
        B[k]=arr[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=B[i];
    }
}
void mergesort(int arr[],int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){

    int arr[] = {56, 78, 586,85, 11,8685, 24, 36,8, 48, 12};
    int n = sizeof(arr) / sizeof(int);

    printArray(arr, n);
    mergesort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}