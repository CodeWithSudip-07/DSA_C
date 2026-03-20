#include <stdio.h>
#include <limits.h>


int main(){
    int n,largest,second_largest;
    
    printf("Enter total no. of element: ");
    scanf("%d",&n);

    if(n<2){
        printf("atleast require two elements\n");
        return 0;
    }

    int arr[n];
    printf("Enter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    largest=second_largest=INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            second_largest=largest;
            largest=arr[i];
        }
        else if(arr[i]>second_largest && arr[i]!=largest){
            second_largest=arr[i];
        }
    }

    if(second_largest==INT_MIN){
        printf("All element are same\n");
    }
    else{
        printf("The second largest: %d",second_largest);
    }

   
    
    return 0;
}