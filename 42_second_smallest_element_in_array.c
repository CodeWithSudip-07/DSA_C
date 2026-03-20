#include <stdio.h>
#include <limits.h>


int main(){
    int i,n,smallest,secondsmallest,arr[50];
    printf("Enter the no. of elements: ");
    scanf("%d",&n);

    if(n<2){
        printf("Atlest require two elemets to find the 2nd smallest");
        return 0;
    }

    printf("Enter the elements of array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    smallest=secondsmallest=INT_MAX;

    for(i=0;i<n;i++){
        if(arr[i]<smallest){
            secondsmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]<secondsmallest && arr[i]!=smallest){
            secondsmallest=arr[i];
        }
    }
    if(secondsmallest==INT_MAX){
        printf("All elements ar same\n");
    }
    else{
        printf("The second smallest element is: %d",secondsmallest);
    }
    return 0;

}