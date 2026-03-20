#include <stdio.h>

int main(){
    int n,i,max,min;
    printf("Enter no. of element of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("The element's in array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    max=arr[0];
    min=arr[0];

    for(i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }

    printf("The largest element of array is: %d\n",max);
    printf("The smallest element of array is: %d\n",min);
    return 0;
}