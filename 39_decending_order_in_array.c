#include <stdio.h>

int main(){
    int n,i,j,temp;
    printf("Enter the number of the element: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the element of the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    printf("The sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}